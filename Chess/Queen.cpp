#include "Queen.h"
#include "Board.h" // Include to use isPathClear method

extern Board board; // Assume an external reference to the board

Queen::Queen(int x, int y, PieceColor color, const sf::Texture& texture)
    : Piece(x, y, color, texture) {
    // Queen-specific initialization (if needed)
}

Queen::~Queen() {
    // Destructor for any Queen-specific clean-up (if necessary)
}

bool Queen::canMoveTo(int x, int y) const {
    // The Queen combines the moves of the Rook and Bishop
    // It moves in straight lines or diagonally

    // Check for straight line movement (like Rook)
    if (x == getX() || y == getY()) {
        return board.isPathClear(getX(), getY(), x, y);
    }

    // Check for diagonal movement (like Bishop)
    if (abs(x - getX()) == abs(y - getY())) {
        return board.isPathClear(getX(), getY(), x, y);
    }

    return false; // Not a valid Queen move
}

// Additional Queen-specific methods can be implemented here
