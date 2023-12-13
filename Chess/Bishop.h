#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~Bishop();

    bool canMoveTo(int x, int y) const override;
    // Additional Bishop-specific methods (if needed)
};

#endif // BISHOP_H
