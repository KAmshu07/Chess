#include "Player.h"

Player::Player(PlayerColor color) : color(color) {
    // Player-specific initialization (if needed)
}

Player::~Player() {
    // Cleanup if required
    // Note: The Board class should be responsible for deleting the Piece instances
}

void Player::addPiece(Piece* piece) {
    pieces.push_back(piece);
}

void Player::removePiece(Piece* piece) {
    pieces.erase(std::remove(pieces.begin(), pieces.end(), piece), pieces.end());
}

const std::vector<Piece*>& Player::getPieces() const {
    return pieces;
}

PlayerColor Player::getColor() const {
    return color;
}

// Additional methods related to player actions can be implemented here
