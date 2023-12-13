#include "King.h"
#include "Board.h" // Include to use isPathClear method and other board functionalities

extern Board board; // Assume an external reference to the board

King::King(int x, int y, PieceColor color, const sf::Texture& texture)
    : Piece(x, y, color, texture) {
    // King-specific initialization (if needed)
}

King::~King() {
    // Destructor for any King-specific clean-up (if necessary)
}

bool King::canMoveTo(int x, int y) const {
    // Standard King move: one square in any direction
    int dx = abs(x - getX());
    int dy = abs(y - getY());
    if ((dx == 1 && dy <= 1) || (dy == 1 && dx <= 1)) {
        return true;
    }

    // Castling move
    if (isCastlingMove(x, y)) {
        return true;
    }

    return false;
}

bool King::isCastlingMove(int x, int y) const {
    // Castling conditions: the King and the chosen Rook have not moved, 
    // there are no pieces between them, and the King is not in check.

    // This is a placeholder for castling logic. 
    // Implement the detailed conditions for castling here.
    // Example: check if the squares between the King and Rook are clear, 
    // and if the King and Rook have not moved from their initial positions.

    return false; // Placeholder, adjust as needed
}

// Additional King-specific methods can be implemented here
