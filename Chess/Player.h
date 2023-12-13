#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Piece.h"

enum class PlayerColor { White, Black };

class Player {
public:
    Player(PlayerColor color);
    ~Player();

    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    const std::vector<Piece*>& getPieces() const;
    PlayerColor getColor() const;

    // Additional methods related to player actions

private:
    std::vector<Piece*> pieces; // The pieces that the player has
    PlayerColor color;          // The color assigned to the player
};

#endif // PLAYER_H
