#ifndef WELL_INCLUDED
#define WELL_INCLUDED
#include <vector>

class Screen;
class Piece;
class Well
{
public:
    Well(); //well constructor
    Well(int x, int y);
    void display(Screen& screen, int x, int y);
    char getIndex(int x, int y);
    int getWidth() const;
    //check for filled row
    void checkRowFilled();
    void setIndex(int x, int y, char c);
    int isVaporized();
    void wellErase(int row);
    bool checkCollision_R(int x, int y);
    bool checkCollision_L(int x, int y);
    bool checkCollision_B(int x, int y);

private:
    Screen* screen;
    //internal data structure(should it hold Coords?)
    std::vector<std::vector<char>> well;
    int WIDTH;
    int HEIGHT;
};

#endif // WELL_INCLUDED
