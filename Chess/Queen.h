#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~Queen();

    bool canMoveTo(int x, int y) const override;
    // Additional Queen-specific methods (if needed)
};

#endif // QUEEN_H
