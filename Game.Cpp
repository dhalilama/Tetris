#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include "Piece.h"
#include <string>
using namespace std;
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;
/* game constructor initializes private members such as well */
Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1), m_well(width, height)
{
}

void Game::play()
{
    m_well.display(m_screen, WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
        waitForEnter();
        m_level++;
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}
void Game::print_Piece(Piece* m_piece)
{
    int x=NEXT_PIECE_X;
    int y=NEXT_PIECE_Y;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m_piece->getChar(i,j)=='#')
            {
                
                char c= '#';
                m_screen.gotoXY(i+x, j+y);
                m_screen.printChar(c);
            }
        }
    }
}
void Game::del_Piece(Piece* p)
{
    int x=NEXT_PIECE_X;
    int y=NEXT_PIECE_Y;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            if(p->getChar(i,j)=='#')
            {
                
                char c= ' ';
                m_screen.gotoXY(i+x, j+y);
                m_screen.printChar(c);
            }
        }
    }
  
}
string Game::print_seven(int n)
{
    string s= to_string(n);
    string ans="      "+s;
    return ans;
}
void Game::displayStatus()
{
    // Next Piece:
    m_screen.gotoXY(NEXT_PIECE_TITLE_X,NEXT_PIECE_TITLE_Y);
    m_screen.printStringClearLine("Next Piece:");
    //Score:
    m_screen.gotoXY(SCORE_X, SCORE_Y);
    m_screen.printStringClearLine("Score:     "+ print_seven(m_score));
    //Rows:
    m_screen.gotoXY(ROWS_LEFT_X, ROWS_LEFT_Y);
    m_screen.printStringClearLine("Rows Left: "+ print_seven(rows_left));
    // Level:
    m_screen.gotoXY(LEVEL_X, LEVEL_Y);
    m_screen.printStringClearLine("Level:     "+print_seven(m_level));
    
    
}
bool Game::gameOver(char ch)
{
    if((int) ch ==81 || (int)ch==113) return true;
    for(int i=0; i<m_well.getWidth()+1; i++)
    {
        if(m_well.getIndex(i, 0)=='$' || m_well.getIndex(i, 0)=='*') //if top of well is filled
        {
            return true;
        }
    }
    return false;
}
bool Game::playOneLevel()
{
    bool game_over=false;
    while(level_isActive()) // iterates to next level when false
    {
        m_well.display(m_screen, WELL_X, WELL_Y);
        int count=5;
        cyclePiece(count);// queue of pieces with capacity of 2, current piece and next piece
        print_Piece(p_cycle.back());
        Piece* m_piece;
        bool isSet=false;
        Timer t;
        while(isSet==false){
            m_piece=p_cycle.front();
            m_piece->displayPiece(m_screen);
            if(t.elapsed()>= std::max(1000-(100*(m_level-1)),100)) //if time elapsed is greater than this function, move piece down
            {
                if(!m_piece->checkDown(m_well))
                {
                    
                    m_piece->deletePiece(m_screen);
                    m_piece->setPiece(m_well, m_screen);
                    m_screen.refresh();
                    isSet=true;
                    break;
                }
                else{
                    move(m_piece,ARROW_DOWN);
                }
                t.start();
            }
            char ch;
            if(getCharIfAny(ch)) // get user input
            {
                discardPendingKeys();
                if(gameOver(ch))
                {
                    game_over=true;
                    break;
                }
                if(ch==ARROW_UP) //rotations
                {
                    if(!m_piece->checkRight(m_well) || !m_piece->checkLeft(m_well) ||!m_piece->checkDown(m_well)) // hit side  temp fix
                    {
                        ;// if rotation fails do nothing
                    }
                    else
                    {
                        m_piece->deletePiece(m_screen);
                        m_piece->rotate();
                        m_piece->displayPiece(m_screen);
                        m_screen.refresh();
                        
                    }
                    
                }
                if((int)ch==32) //spacebar
                {
                    ch=ARROW_DOWN;
                    while(m_piece->checkDown(m_well))
                    {
                        
                        move(m_piece,ch);
                    }
                    if(!m_piece->checkDown(m_well))
                    {
                        m_piece->deletePiece(m_screen);
                        m_piece->setPiece(m_well, m_screen);
                        m_screen.refresh();
                        isSet=true;
                        break;
                    }
                }
                if(ch==ARROW_RIGHT)
                {
                    if(!m_piece->checkRight(m_well) && !check_Rbound(m_piece)) //hit right wall
                    {
                        ; //do nothing
                        
                    }
                    if(!m_piece->checkRight(m_well) && check_Rbound(m_piece)) // hit piece to right
                    {
                        
                        m_piece->deletePiece(m_screen);
                        m_piece->setPiece(m_well, m_screen);
                        m_screen.refresh();
                        isSet=true;
                        break;
                    }
                    else if(m_piece->checkRight(m_well) && check_Rbound(m_piece)) // no collisions
                    {
                        move(m_piece,ch);
                    }
                    
                }
                if(ch==ARROW_LEFT)
                {
                    if(!m_piece->checkLeft(m_well) && !check_Lbound(m_piece))
                    {
                        ; //do nothing
                        
                    }
                    if(!m_piece->checkLeft(m_well) && check_Lbound(m_piece))
                    {
                        
                        m_piece->deletePiece(m_screen);
                        m_piece->setPiece(m_well, m_screen);
                        m_screen.refresh();
                        isSet=true;
                        break;
                    }
                    else if(m_piece->checkLeft(m_well) && check_Lbound(m_piece))
                    {
                        move(m_piece,ch);
                    }
                }
                if(ch==ARROW_DOWN)
                {
                    if(!m_piece->checkDown(m_well))
                    {
                        
                        m_piece->deletePiece(m_screen);
                        m_piece->setPiece(m_well, m_screen);
                        m_screen.refresh();
                        isSet=true;
                        break;
                    }
                    else{
                        move(m_piece,ch);
                    }
                }
            }
            
            
        } //replace with TIMER!
        if(isSet==true)
        {
            del_Piece(p_cycle.back());
            p_cycle.pop(); // get next piece
        }
        delete m_piece;
        if(game_over==true) break;
    }
    if(game_over==true) return false;
    return true;
}
//check left and right bounds
bool Game::check_Rbound(Piece* m_piece)
{
    int right=0;
    int k=0;
    while(k<3)
    {
        for(int i=3; i>=0;i--)
        {
            if(m_piece->getChar(i,k)=='#' && i>right)
            {
                right=i;
                break;
            }
        }
        k++;
    }
    if(m_well.getIndex(m_piece->getX()+right+1, k)=='@') return false;
    
    return true;
}
bool Game::check_Lbound(Piece* m_piece) //check left boundary of passed in piece and mwell
{
    int left=3;
    int k=0;
    while(k<3)
    {
        for(int i=0;i<4;i++)
        {
            if(m_piece->getChar(i, k)=='#' && i<left)
            {
                left=i;
                break;
            }
        }
        k++;
    }
    if(m_well.getIndex(m_piece->getX()+left-1, k)=='@') return false;
    return true;
}

/* move piece function */
void Game::move(Piece* p, char c)
{
    //CHECK FOR OVERLAP IN THIS FUNCTION
    if(c==ARROW_DOWN)
    {
        p->deletePiece(m_screen);
        p->update_Y();
        m_screen.refresh();
        p->displayPiece(m_screen);
    }
    if(c==ARROW_LEFT)
    {
        p->deletePiece(m_screen);
        p->decrease_X();
        m_screen.refresh();
        p->displayPiece(m_screen);
    }
    if(c==ARROW_RIGHT)
    {
        p->deletePiece(m_screen);
        p->increase_X();
        m_screen.refresh();
        p->displayPiece(m_screen);
    }
}
void Game::cyclePiece(int &count)
{
while(count!=0)
{
    Piece *p;
    switch(chooseRandomPieceType())
    {
        case PIECE_T:
        {
            p= new class PIECE_T();
            break;
        }
        case  PIECE_L:
        {
            p= new class PIECE_L();
            break;
        }
        case PIECE_J:
        {
            p= new class PIECE_J();
            break;
        }
        case PIECE_O:
        {
            p= new class PIECE_O();
            break;
        }
        case PIECE_S:
        {
           p= new class PIECE_S();
            break;
        }
        case PIECE_Z:
        {
         p= new class PIECE_Z();
            break;
        }
        case PIECE_I:
        {
            p= new class PIECE_I();
            break;
        }
        case PIECE_VAPOR:
        {
            p= new class PIECE_VAPOR();
            break;
        }
        case PIECE_FOAM:
        {
            p= new class PIECE_FOAM();
            break;
        }
        case PIECE_CRAZY:
        {
            p= new class PIECE_CRAZY();
            break;
        }
        default:
            break;
    }
    p_cycle.push(p);
    count--;
}
}


bool Game::level_isActive()
{
    /* here, ALL THE GAME RULES FOR COMPLETING A LEVEL WILL GO */
    //eg : once 5 rows are vaporized
    int count=m_well.isVaporized();
    rows_left=m_level-count;
    m_score=2^(count*50);
    m_well.display(m_screen, WELL_X, WELL_Y);
    int compare =5*m_level;
    if(count>=compare)return false;
    return true;
}



