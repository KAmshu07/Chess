#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

class Board {
public:
    Board();
    ~Board();

    void setupBoard();
    void draw(sf::RenderWindow& window);
    Piece* getPieceAt(int x, int y) const;
    void movePiece(int fromX, int fromY, int toX, int toY);
    bool isMoveLegal(int fromX, int fromY, int toX, int toY);
    bool isPathClear(int startX, int startY, int endX, int endY) const;

private:
    std::array<std::array<Piece*, 8>, 8> squares; // 2D array for the 8x8 board
    void placePieces();
    void clearBoard(); // Helper function to clear the board

    // Texture resources for pieces
    sf::Texture texturePawn;
    sf::Texture textureRook;
    sf::Texture textureKnight;
    sf::Texture textureBishop;
    sf::Texture textureQueen;
    sf::Texture textureKing;
    // Other textures
};

#endif // BOARD_H
