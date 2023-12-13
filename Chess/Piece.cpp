#include "Piece.h"

Piece::Piece(int x, int y, PieceColor color, const sf::Texture& texture)
    : posX(x), posY(y), color(color), sprite(texture) {
    setPosition(x, y); // Set the initial position of the sprite
}

Piece::~Piece() {
    // Destructor for any clean-up, if necessary
}

void Piece::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

bool Piece::canMoveTo(int x, int y) const {
    // This method is purely virtual and will be overridden in derived classes
    return false;
}

void Piece::setPosition(int x, int y) {
    posX = x;
    posY = y;
    sprite.setPosition(static_cast<float>(x * 60), static_cast<float>(y * 60)); // Assuming each square is 60x60 pixels
}

int Piece::getX() const {
    return posX;
}

int Piece::getY() const {
    return posY;
}

PieceColor Piece::getColor() const {
    return color;
}
