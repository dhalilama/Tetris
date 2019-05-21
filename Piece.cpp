#include "Piece.h"
#include "UserInterface.h"
#include "Well.h"

int Piece::getX() const //get x foord
{
    return start_x;
}
int Piece::getY() const //get y coord
{
    return start_y;
}
void Piece::update_Y() // mutate y up(down)
{
    start_y++;
}
void Piece::increase_X() // mutate x up
{
    start_x++;
}
void Piece::decrease_X() //mutate x down
{
    start_x--;
}
char Piece::getChar(int x, int y) const //accessor function
{
    char c= box[x][y];
    return c;
}
void Piece::setChar(int x, int y, char c) //setter function
{
    box[x][y]=c;
}
void Piece::displayPiece(Screen& screen) //IMPLEMENT FOR VECTOR DATA AS WELL
{
    int start_x=getX();
    int start_y=getY();
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            if(getChar(i,j)=='#')
            {
                
                char c= '#';
                screen.gotoXY(i+start_x, j+start_y);
                screen.printChar(c);
            }
        }
    }
}

void Piece::deletePiece(Screen& screen)// delete piece from screen
{
    int start_x=getX();
    int start_y=getY();
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            if(getChar(i,j)=='#')
            {
                char c=' ';
                screen.gotoXY(i+start_x, j+start_y);
                screen.printChar(c);
            }
        }
    }
}
void Piece::setPiece(Well& well, Screen& screen) set pieces in screen and well
{
    int start_x=getX();
    int start_y=getY();
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            if(getChar(i,j)=='#')
            {
                char c='$';
                well.setIndex(start_x+i, start_y+j, c); 
                screen.gotoXY(i+start_x, j+start_y);
                screen.printChar(c);
            }
        }
    }
}
bool Piece::checkLeft(Well& well)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(getChar(i,j) == '#')
            {
                if(!well.checkCollision_L(i+start_x,j+start_y))
                {
                    return false;
                }
            }
    return true;
}

bool Piece::checkRight(Well& well) // check right boundary of @ symbols
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(getChar(i,j) == '#')
            {
                if(!well.checkCollision_R(i+start_x,j+start_y))
                {
                    return false;
                }
            }
    return true;
    
}

bool Piece::checkDown(Well& well)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(getChar(i,j) == '#')
            {
                if(!well.checkCollision_B(i+start_x,j+start_y))
                {
                    return false;
                }
            }
    return true;
}
void Piece::rotate() // swaps current bounding box with each orientation , ogint in order
{
    switch(count)
    {
        case 0:
        {
            std::swap(box,POS_1);
            count++;
            break;
        }
            
        case 1:
        {
            std::swap(box,POS_2);
            count++;
            break;
        }
        case 2:
        {
            std::swap(box,POS_3);
            count++;
            break;
        }
        case 3:
        {
            std::swap(box,POS_3);
            count++;
            break;
        }
        case 4:
        {
            std::swap(box,POS_4);
            count=0;
            break;
        }
        default:
        {
            std::swap(box,POS_1);
            count=0;
            break;
        }
    }
}


