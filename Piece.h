#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
#include <iostream>
enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();
class Well;
class Screen;
class Piece{
public:
    //movement
    void displayPiece(Screen& screen);
    void deletePiece(Screen& screen);
    void setPiece(Well& well, Screen& screen);
    //accessors
    char getChar(int x, int y) const;
    int getX() const;
    int getY() const;
    //mutators
    void update_Y();
    void increase_X();
    void decrease_X();
    void setChar(int x, int y, char c) ;
    void rotate();
    //boundaries
    bool checkLeft(Well& well);
    bool checkRight(Well& well);
    bool checkDown(Well& well);
protected:
    char box [4][4]; // current piece'sbounding box
    int start_x;
    int start_y;
    int count;
    char POS_1 [4][4];
    char POS_2 [4][4];
    char POS_3 [4][4];
    char POS_4 [4][4];
    
    
};
class PIECE_I:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_I()
    {
        count = 0;
        // ORIENTATION ONE
        POS_1[0][1] = '#';
        POS_1[1][1] =  '#';
        POS_1[2][1] = '#';
        POS_1[3][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
            }
        
        // ORIENTATION TWO
        POS_2[1][0] = '#';
        POS_2[1][1] =  '#';
        POS_2[1][2] = '#';
        POS_2[1][3] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][1] = '#';
        POS_3[1][1] =  '#';
        POS_3[2][1] = '#';
        POS_3[3][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][0] = '#';
        POS_4[1][1] =  '#';
        POS_4[1][2] = '#';
        POS_4[1][3] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
    }
    
private:
    
};

class PIECE_L:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_L()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[0][1] = '#';
        POS_1[1][1] =  '#';
        POS_1[2][1] = '#';
        POS_1[0][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[1][0] = '#';
        POS_2[2][0] =  '#';
        POS_2[2][1] = '#';
        POS_2[2][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][2] = '#';
        POS_3[1][2] =  '#';
        POS_3[2][2] = '#';
        POS_3[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][1] = '#';
        POS_4[1][2] =  '#';
        POS_4[1][3] = '#';
        POS_4[2][3] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
};

class PIECE_J:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_J()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[1][1] = '#';
        POS_1[2][1] =  '#';
        POS_1[3][1] = '#';
        POS_1[3][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
            }
        
        // ORIENTATION TWO
        POS_2[1][3] = '#';
        POS_2[2][1] =  '#';
        POS_2[2][2] = '#';
        POS_2[2][3] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
                
            }
        
        // ORIENTATION THREE
        POS_3[1][1] = '#';
        POS_3[1][2] =  '#';
        POS_3[2][2] = '#';
        POS_3[3][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][0] = '#';
        POS_4[1][1] =  '#';
        POS_4[1][2] = '#';
        POS_4[2][0] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
    
};

class PIECE_T:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_T()
    {
        count = 0;
        start_x = 3;
        start_y = 0;
        // ORIENTATION ONE
        POS_1[0][1] = '#';
        POS_1[1][1] =  '#';
        POS_1[1][0] = '#';
        POS_1[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[1][0] = '#';
        POS_2[1][1] =  '#';
        POS_2[1][2] = '#';
        POS_2[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][1] = '#';
        POS_3[1][1] =  '#';
        POS_3[1][2] = '#';
        POS_3[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[0][1] = '#';
        POS_4[1][0] =  '#';
        POS_4[1][1] = '#';
        POS_4[1][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
    }
    
};

class PIECE_O:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_O()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[0][0] = '#';
        POS_1[0][1] =  '#';
        POS_1[1][0] = '#';
        POS_1[1][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[0][0] = '#';
        POS_2[1][0] =  '#';
        POS_2[1][1] = '#';
        POS_2[0][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][0] = '#';
        POS_3[1][0] =  '#';
        POS_3[0][1] = '#';
        POS_3[1][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][1] = '#';
        POS_4[0][0] =  '#';
        POS_4[1][0] = '#';
        POS_4[0][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
    
};

class PIECE_S:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_S()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[0][2] = '#';
        POS_1[1][1] =  '#';
        POS_1[1][2] = '#';
        POS_1[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[2][1] = '#';
        POS_2[1][0] =  '#';
        POS_2[1][1] = '#';
        POS_2[2][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][2] = '#';
        POS_3[1][1] =  '#';
        POS_3[1][2] = '#';
        POS_3[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][0] = '#';
        POS_4[1][1] =  '#';
        POS_4[2][1] = '#';
        POS_4[2][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
    
};
class PIECE_Z:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_Z()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[2][2] = '#';
        POS_1[0][1] =  '#';
        POS_1[1][2] = '#';
        POS_1[1][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[1][2] = '#';
        POS_2[1][1] =  '#';
        POS_2[2][0] = '#';
        POS_2[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][1] = '#';
        POS_3[1][1] =  '#';
        POS_3[1][2] = '#';
        POS_3[2][2] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][1] = '#';
        POS_4[1][2] =  '#';
        POS_4[2][0] = '#';
        POS_4[2][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
    
};
class PIECE_VAPOR:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_VAPOR()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[1][0] = '#';
        POS_1[2][0] =  '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[1][0] = '#';
        POS_2[2][0] =  '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[1][0] = '#';
        POS_3[2][0] =  '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][0] = '#';
        POS_4[2][0] =  '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
};
class PIECE_FOAM:public Piece

{
public:
    char getChar(int x, int y);
    PIECE_FOAM()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[1][1] = '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[1][1] = '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[1][1] = '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[1][1] = '#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
    }
    
    
};
class PIECE_CRAZY:public Piece
{
public:
    char getChar(int x, int y);
    PIECE_CRAZY()
    {
        count = 0;
        
        // ORIENTATION ONE
        POS_1[0][0] = '#';
        POS_1[3][0] =  '#';
        POS_1[2][1] = '#';
        POS_1[1][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_1[i][j] != '#')
                {
                    POS_1[i][j] = ' ';
                }
                box[i][j] = POS_1[i][j];
                
            }
        
        // ORIENTATION TWO
        POS_2[2][1] = '#';
        POS_2[2][2] =  '#';
        POS_2[3][0] = '#';
        POS_2[3][3] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_2[i][j] != '#')
                {
                    POS_2[i][j] = ' ';
                }
            }
        
        // ORIENTATION THREE
        POS_3[0][3] = '#';
        POS_3[1][1] =  '#';
        POS_3[2][2] = '#';
        POS_3[3][3] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_3[i][j] != '#')
                {
                    POS_3[i][j] = ' ';
                }
            }
        
        // ORIENTATION FOUR
        POS_4[0][0] = '#';
        POS_4[0][3] =  '#';
        POS_4[1][2] = '#';
        POS_4[1][1] ='#';
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(POS_4[i][j] != '#')
                {
                    POS_4[i][j] = ' ';
                }
            }
        start_x = 3;
        start_y = 0;
        
    }
    
    
};
#endif // PIECE_INCLUDED
