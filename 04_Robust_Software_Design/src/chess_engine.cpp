#include "chess_engine.h" 

const int Board::width_=8; 
const int Board::height_=8; 
Board::Board(){init();}; 
void Board::init(){ 
    board_ = new char*[height_]; 
    for(int i=0; i<height_; i++) board_[i] = new char[width_]; 
    for(int i=0; i<height_; i++){ 
        for(int j=0; j<width_; j++) board_[i][j] = empty_;} 
    Piece piece; 
    for(int i=0; i<width_; i++){ 
        piece.setPosition(pawn_, i, 1); 
        blackPieces_.push_back(piece); 
        board_[1][i] = pawn_; 
        piece.setPosition(pawn_, i, 6); 
        whitePieces_.push_back(piece); 
        board_[6][i] = pawn_;} 
    piece.setPosition(rook_, 0, 0); 
    blackPieces_.push_back(piece); 
    board_[0][0] = rook_; 
    piece.setPosition(rook_, 7, 0); 
    board_[0][7] = rook_; 
    blackPieces_.push_back(piece); 
    piece.setPosition(knight_, 1, 0); 
    whitePieces_.push_back(piece); 
    board_[0][1] = knight_; 
    blackPieces_.push_back(piece); 
    piece.setPosition(knight_, 6, 0); 
    board_[0][6] = knight_; 
    blackPieces_.push_back(piece); 
    piece.setPosition(bishop_, 2, 0); 
    board_[0][2] = bishop_; 
    blackPieces_.push_back(piece); 
    piece.setPosition(bishop_, 5, 0); 
    board_[0][5] = bishop_; 
    blackPieces_.push_back(piece); 
    piece.setPosition(queen_, 3, 0); 
    board_[0][3] = queen_; 
    blackPieces_.push_back(piece); 
    piece.setPosition(king_, 4, 0); 
    blackPieces_.push_back(piece); 
    board_[0][4] = king_; 
    piece.setPosition(rook_, 0, 7); 
    board_[7][0] = rook_; 
    piece.setPosition(rook_, 7, 7); 
    whitePieces_.push_back(piece); 
    board_[7][7] = rook_; 
    piece.setPosition(knight_, 1, 7); 
    whitePieces_.push_back(piece); 
    board_[7][1] = knight_; 
    piece.setPosition(knight_, 6, 7); 
    whitePieces_.push_back(piece); 
    board_[7][6] = knight_; 
    piece.setPosition(bishop_, 2, 7); 
    whitePieces_.push_back(piece); 
    board_[7][2] = bishop_; 
    piece.setPosition(bishop_, 5, 7); 
    whitePieces_.push_back(piece); 
    board_[7][5] = bishop_; 
    piece.setPosition(queen_, 3, 7); 
    whitePieces_.push_back(piece); 
    board_[7][3] = queen_; 
    piece.setPosition(king_, 4, 7); 
    board_[7][4] = king_; 
    whitePieces_.push_back(piece);
} 

Board::~Board(){ 
    for(int i=0; i<height_; i++) delete[] board_[i]; 
    delete[] board_;
} 

void Board::printBoard() const{ 
    cout << endl; 
    for(int i=0; i<height_; i++){ 
        for(int j=0; j<width_; j++) cout << board_[i][j]; 
        cout << endl;
    } 
    cout << endl;
} 

void Board::playerTurn(char currentColor){ 
    int choice=0; 
    while(choice!=1){ 
        cout << "It's your turn: Enter 1 for making a move or 2 to view a board: "; 
        cin >> choice; 
        if (choice==1){ 
            int fromX; 
            int fromY; 
            cout << "Please choose your piece position x and y: "; 
            cin >> fromX >> fromY; 
            int x; 
            int y; 
            Piece* piece = nullptr; 
            Piece* targetPiece = nullptr; 
            int targetPiecePos = 0; 
            bool obstacle=false; 
            vector<Piece>& activePiece = (currentColor == 'w') ? whitePieces_ : blackPieces_; 
            vector<Piece>& oppPiece = (currentColor == 'w') ? blackPieces_ : whitePieces_; 
            for(auto& p : activePiece){ 
                if(p.getX() == fromX && p.getY() == fromY){ 
                    piece = &p; 
                    break;
                }
            } 
            if(piece == nullptr){ 
                cout << "There's not your piece on that position!" << endl; 
                break;
            }else{ 
                cout << "Please enter destination position x and y: "; 
                cin >> x >> y; 
                if(x>fromX && y > fromY){ 
                    for(int i=fromY; i<y; i++){ 
                        for(int j=fromX; j<x; j++){ 
                            if(board_[i][j] != empty_) obstacle=true;}} 
                }else if(x>fromX && fromY > y){  
                    for(int i=y; i<fromY; i++){ 
                        for(int j=fromX; j<x; j++){ 
                            if(board_[i][j] != empty_) obstacle=true;}} 
                }else if(x<fromX && y > fromY){ 
                    for(int i=fromY; i<y; i++){ 
                        for(int j=x; j<fromX; j++){ 
                            if(board_[i][j] != empty_) obstacle=true;}} 
                }else{ 
                    for(int i=y; i<fromY; i++){ 
                        for(int j=x; j<fromX; j++){ 
                            if(board_[i][j] != empty_) obstacle=true;}}
                }  
                if(board_[y][x] != empty_){ 
                    for(auto& p : activePiece){ 
                        if(p.getX() == x && p.getY() == y){ 
                            cout << "Target piece is the same team! Unable to move."; 
                            break;}} 
                    for(auto& p : oppPiece){ 
                        if(p.getX() == x && p.getY() == y){ 
                        targetPiece = &p; 
                            for(int i=0; i< oppPiece.size(); i++){ 
                            if(targetPiece == &oppPiece[i]) targetPiecePos = i;}   
                            break;
                        }
                    }
                }
            } 
            if(piece->isMoveAllowed(piece->getType(), fromX, fromY, x, y, obstacle)){ 
                addMoveToHistory(*piece, x, y); 
                if(targetPiece == nullptr) piece->move(x, y); 
                else{ 
                    piece->attack(*targetPiece); 
                    oppPiece.erase(oppPiece.begin()+targetPiecePos); 
                    retiredPieces_.push_back(*targetPiece);}     
                    board_[fromY][fromX] = empty_; 
                    board_[y][x] = piece->getType(); 
            }else cout << "Unable to move."; 
        if(isGameOver()){cout << "Game over."<< endl;}
        } 
        else if (choice==2) printBoard(); 
    else cout << "Invalid input" << endl;
    }
} 

bool Board::isGameOver(){ 
    bool kingCount =0; 
    for(int i=0; i< retiredPieces_.size(); i++){ 
        if(retiredPieces_[i].getType() == 'K') kingCount=true;
    } 
    return kingCount;
} 

void Board::addMoveToHistory(const Piece& piece, int x, int y){ 
    MoveRecord record; 
    record.type = piece.getType(); 
    record.color = piece.getColor(); 
    record.startX = piece.getX(); 
    record.startY = piece.getY(); 
    record.endX = x; 
    record.endY = y; 
    moveHistory_.push_back(record);
} 

void Piece::move(int desX, int desY){ 
    posX_ = desX; 
    posY_ = desY;
} 

void Piece::attack(Piece target){ 
    posX_ = target.posX_; 
    posY_ = target.posY_;
} 

bool Piece::isMoveAllowed(char type, int oldX, int oldY, int x, int y, bool obstacle){ 
    if(type != 'k' && obstacle) return 0; 
    switch(type){ 
        case 'K': return (abs(oldX-x)==1 || abs(oldY-y)==1) ? 1 : 0; 
        case 'r': return (oldX==x|| oldY==y) ? 1 : 0; 
        case 'b': return (abs(oldX-x)==abs(oldY-y)) ? 1 : 0; 
        case 'Q': return (abs(oldX-x)==1 || abs(oldY-y)==1 || oldX==x|| oldY==y || abs(oldX-x)==abs(oldY-y)) ? 1 : 0; 
        case 'k': return ((abs(oldX-x)==2 && abs(oldY-y)==1) || (abs(oldY-y)==2 && abs(oldX-x)==1)) ? 1 : 0; 
        case 'p': return (y==oldY-1) ? 1 : 0;} 
    return 0;
} 

void Piece::setPosition(char type, int x, int y){ 
    type_=type; 
    posX_=x; 
    posY_=y; 
    color_ = (y==0 || y ==1) ? 'b' : 'w';
} 