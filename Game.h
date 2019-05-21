#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "UserInterface.h"
#include "Piece.h"
#include <string>
#include <queue>
// [Add other #include directives as necessary.]
class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
    void print_Piece(Piece* m_piece);
    void del_Piece(Piece* p);
    std::string print_seven(int n);
    void move(Piece* piece, char c);
    //check walls
    bool check_Lbound(Piece* m_piece);
    bool check_Rbound(Piece* m_piece);
    //check if level is active
    bool level_isActive();
    void cyclePiece(int &count);
    bool gameOver(char ch);
  private:
    
    Well    m_well;
    Screen  m_screen;
    //display variables
    int     m_level;
    int     m_score;
    int     rows_left;
    //internal data structure
    std::queue<Piece*> p_cycle; // queue for piece cycle- maybe have a function for pushing in a new piece once curr piece has been established?
   
};

#endif // GAME_INCLUDED
