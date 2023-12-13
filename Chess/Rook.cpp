#include "Rook.h"
#include "Board.h" // Include to use isPathClear method

extern Board board; // Assume an external reference to the board

Rook::Rook(int x, int y, PieceColor color, const sf::Texture& texture)
    : Piece(x, y, color, texture), moved(false) {
    // Rook-specific initialization (if needed)
}

Rook::~Rook() {
    // Destructor for any Rook-specific clean-up (if necessary)
}

bool Rook::canMoveTo(int x, int y) const {
    // Rooks move in straight lines along rows or columns
    if (x != getX() && y != getY()) {
        return false; // Not moving in a straight line
    }

    // Check if the path between the current position and the target is clear
    return board.isPathClear(getX(), getY(), x, y);
}

void Rook::setHasMoved() {
    moved = true;
}

bool Rook::hasMoved() const {
    return moved;
}

// Additional Rook-specific methods can be implemented here
