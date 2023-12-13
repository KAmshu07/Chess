#include "Pawn.h"

Pawn::Pawn(int x, int y, PieceColor color, const sf::Texture& texture)
    : Piece(x, y, color, texture) {
    // Pawn-specific initialization (if needed)
}

Pawn::~Pawn() {
    // Destructor for any Pawn-specific clean-up (if necessary)
}

bool Pawn::canMoveTo(int x, int y) const {
    int direction = (getColor() == PieceColor::White) ? 1 : -1;
    int startRow = (getColor() == PieceColor::White) ? 1 : 6;

    // Standard move
    if (x == getX() && y == getY() + direction) {
        return true;
    }

    // First move: 2 squares forward
    if (x == getX() && getY() == startRow && y == getY() + 2 * direction) {
        return true;
    }

    // Capturing move
    if (abs(x - getX()) == 1 && y == getY() + direction) {
        // Additional logic will be needed to check if an enemy piece is at the new position
        return true;
    }

    return false;
}

bool Pawn::isPromotionPossible() const {
    // Promotion is possible when a pawn reaches the opposite end of the board
    int promotionRow = (getColor() == PieceColor::White) ? 7 : 0;
    return getY() == promotionRow;
}

// Additional Pawn-specific methods can be implemented here
