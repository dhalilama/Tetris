
#include "Well.h"
#include "UserInterface.h"
#include "Piece.h"

using namespace std;
const char BOUND='@';

Well::Well(): WIDTH(10), HEIGHT(18)
{
    
    //intialize vector
    well=vector<vector<char>>(WIDTH+2, vector<char>(HEIGHT+1, ' ')); //data
    for(int i=0; i<WIDTH+2; i++)
        for(int j=0; j<HEIGHT+1;j++)
        {
            well[i][j]= ' ';
        }
    for(int i=0; i<WIDTH+1; i++)
    {
        well[i][HEIGHT]=BOUND; //CANT BE CHANGED
    }
    for(int i=0; i<HEIGHT+1;i++)
    {
        well[0][i]=BOUND;
        well[WIDTH+1][i]=BOUND;
    }
    
}
Well::Well(int x, int y): WIDTH(x), HEIGHT(y)
{
    
    //intialize vector
    well=vector<vector<char>>(WIDTH+2, vector<char>(HEIGHT+1, ' ')); //data
    for(int i=0; i<WIDTH+2; i++)
        for(int j=0; j<HEIGHT+1;j++)
        {
            well[i][j]= ' ';
        }
    for(int i=0; i<WIDTH+1; i++)
    {
        well[i][HEIGHT]=BOUND; //CANT BE CHANGED
    }
    for(int i=0; i<HEIGHT+1;i++)
    {
        well[0][i]=BOUND;
        well[WIDTH+1][i]=BOUND;
    }
    
}
void Well::display(Screen& screen, int x, int y) //SHOULD TAKE DATA FROM VECTOR AND PRINT IT TO SCREEN
{
    for(int i=0; i<WIDTH+2; i++)
    {
        for(int j=0; j<HEIGHT+1; j++)
        {
            char c= well[i][j];
            screen.gotoXY(i, j);
            screen.printChar(c);
        }
    }
    screen.gotoXY(x, y);
}
int Well::getWidth() const
{
    return WIDTH;
}
char Well::getIndex(int x,int y) //accessor function for well
{
    return well[x][y];
}
void Well::setIndex(int x, int y, char c) // sets index to char
{
    well[x][y]=c;
}
int Well::isVaporized() //returns number of times a row has been vaporized
{
    int countChar = 0;
    int eraser = 0;
    
    for(int j = 17;j>0;j--)
    {
        for(int i=1; i< 11; i++)
        {
            if (getIndex(i, j)=='$' || getIndex(i, j)=='*')
            {
                countChar++;
            }
            if(countChar ==10)
            {
                wellErase(j);
                eraser++;
            }
        }
        countChar=0;
     
    }
    return eraser;
}

void Well::wellErase(int row) // erases row if vaproized is true
{
    for(int i = 1; i < 11; i++)
    {
        setIndex(i, row, ' ');
    }
    int pushDown = row - 1;
    
    while(pushDown >= 0)
    {
        for(int i = 1; i < 11; i++)
        {
            char ch= getIndex(i, pushDown);
            setIndex(i, row, ch);
        }
        row--;
        pushDown--;
    }
}


bool Well::checkCollision_R(int x, int y) //check collision on right side
{
    if(x>10 || x<0) return false;
    if(well[x+1][y] != ' ') return false;
    return true;
}
bool Well::checkCollision_L(int x, int y) //checks left collisions
{
    if(x>10 || x<0) return false;
    if(well[x-1][y] != ' ') return false;
    return true;
       
}
bool Well::checkCollision_B(int x, int y)//check bottom collisions
{
    if(y<0 || y>=18) return false;
    if(well[x][y+1]!= ' ' || well[x][y]!= ' ')return false;
    return true;
}


