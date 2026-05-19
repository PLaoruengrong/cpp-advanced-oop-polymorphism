#ifndef CHESS_ENGINE_H_ 
#define CHESS_ENGINE_H_
#include <string> 
using namespace std; 

struct MoveRecord { 
    char type; 
    char color; 
    int startX; 
    int startY; 
    int endX; 
    int endY;
}; 
    
class Board { 
    private: 
        char ** board_; 
        static const int width_; 
        static const int height_; 
        vector<Piece> whitePieces_; 
        vector<Piece> blackPieces_; 
        vector<Piece> retiredPieces_; 
        vector<MoveRecord> moveHistory_; 
        const char empty_ = ' '; 
        const char pawn_ = 'p'; 
        const char rook_ = 'r'; 
        const char knight_ = 'k'; 
        const char bishop_ = 'b'; 
        const char queen_ = 'Q'; 
        const char king_ = 'K'; 
    public: 
        Board(); 
        ~Board(); 
        void printBoard() const; 
        void init(); 
        void playerTurn(char currentColor); 
        bool isGameOver(); 
        void addMoveToHistory(const Piece& piece, int x, int y);
};

class Piece { 
    private: 
        char type_; 
        char color_; 
        int posX_; 
        int posY_; 
    public: 
        void move(int desX, int desY); 
        void attack(Piece target); 
        bool isMoveAllowed(char type, int oldX, int oldY, int x, int y, bool obstacle); 
        int getX() const {return posX_;}; 
        int getY() const {return posY_;}; 
        char getType() const {return type_;}; 
        char getColor() const {return color_;}; 
        void setPosition(char type, int x, int y);
}; 

#endif 