#include "Knight.h"

Knight::Knight(int x, int y, PieceColor color, const sf::Texture& texture)
    : Piece(x, y, color, texture) {
    // Knight-specific initialization (if needed)
}

Knight::~Knight() {
    // Destructor for any Knight-specific clean-up (if necessary)
}

bool Knight::canMoveTo(int x, int y) const {
    // The Knight moves in an L-shape: two squares in one direction, then one square perpendicular
    int dx = abs(x - getX());
    int dy = abs(y - getY());

    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

// Additional Knight-specific methods can be implemented here
