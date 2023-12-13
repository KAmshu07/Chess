#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~Knight();

    bool canMoveTo(int x, int y) const override;
    // Additional Knight-specific methods (if needed)
};

#endif // KNIGHT_H
