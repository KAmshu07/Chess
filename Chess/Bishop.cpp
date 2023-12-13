#include "Bishop.h"
#include "Board.h" // Include to use isPathClear method

extern Board board; // Assume an external reference to the board

Bishop::Bishop(int x, int y, PieceColor color, const sf::Texture& texture)
    : Piece(x, y, color, texture) {
    // Bishop-specific initialization (if needed)
}

Bishop::~Bishop() {
    // Destructor for any Bishop-specific clean-up (if necessary)
}

bool Bishop::canMoveTo(int x, int y) const {
    // Bishops move diagonally, so the absolute difference between x and y should be the same
    if (abs(x - getX()) != abs(y - getY())) {
        return false; // Not moving diagonally
    }

    // Check if the path between the current position and the target is clear
    return board.isPathClear(getX(), getY(), x, y);
}

// Additional Bishop-specific methods can be implemented here
