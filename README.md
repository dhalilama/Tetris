
Game.cpp- internal game engine
    void play();
Internal game engine, runs the entire game and invokes play one level. If play one level fails, it ends the game
    bool playOneLevel();
Returns true if the game is still active 
Adds piece to well and checks all boundaries
If a piece is established, it changes to a $ symbol and is added to internal data structure well, which holds a 2d vector
Returns false if game over( press.q or reach top of well)
    void displayPrompt(std::string s);
Display prompt such as Enter to start game to screen
    void displayStatus();
Prints stats to the screen
    void print_Piece(Piece* m_piece);
Prints next piece to the screen in stats
    void del_Piece(Piece* p);
Deletes next piece in stats screen
    std::string print_seven(int n);
Converts to string and right justifies
    void move(Piece* piece, char c);
Moves the piece left right or down depending on char
    //check walls
    bool check_Lbound(Piece* m_piece);
Checks left wall containing @ symbols
    bool check_Rbound(Piece* m_piece);
Checks right wall containing @ symbols
    //check if level is active
    bool level_isActive();
Checks if level is still active, if no level iterates
    void cyclePiece(int &count);
Adds random piece to internal queue storing pieces
    bool gameOver(char ch);
True if the player reaches the top of the well or hits q, 
Piece.cpp- pieces that fall , uses inheritance but not polymorphism so no virtual keyword is necessary
void displayPiece(Screen& screen);
Displays current piece to the screen when invoked in game
    void deletePiece(Screen& screen);
Deletes current piece from the screen when invoked in game
    void setPiece(Well& well, Screen& screen);
Sets piece in both the well as well as printing to the screen
    //accessors
    char getChar(int x, int y) const;
Accessor function for piece
    int getX() const;
Accessor for starting x coord
    int getY() const;
Accessor for starting y coord
    //mutators
    void update_Y();
Update y
    void increase_X();
Increase x
    void decrease_X();
Decrease x
    void setChar(int x, int y, char c) ;
Set char at this coord to c
    void rotate();
Rotates current piece to next orientation, sets current bounding box to next bounding box in piece class
    //boundaries
    bool checkLeft(Well& well);
Check left boundary  of piece in well
    bool checkRight(Well& well);
Check right boundary  of piece in well
    bool checkDown(Well& well);
Check bottom boundary of piece in well

Well.cpp- holds a 2d vector that stores internal data of $’s and *
  void display(Screen& screen, int x, int y);
Displays well to screen
    char getIndex(int x, int y);
Accessor for well
    int getWidth() const;
Accessor for width
    void setIndex(int x, int y, char c);
Sets index to passed in char
    int isVaporized();
Returns how many times a row has been vaporized
    void wellErase(int row);
Erases row if conditions are met
    bool checkCollision_R(int x, int y);
Checks collision of piece in well
    bool checkCollision_L(int x, int y);
Checks collision of piece in well
    bool checkCollision_B(int x, int y);
Checks collision of piece in well


Failed to Finish Implementation
Did not get to special functions/special classes. Vapor Bomb, Crazy Shape, instead function as normal pieces
My next piece does not show up correctly


Assumptions
Assumed that well only contained the $ symbols and * symbols
Assumed that timer would increment and move faster with every level
Assumed that next piece would be back of queue
Assumed queue would always have size of two 
