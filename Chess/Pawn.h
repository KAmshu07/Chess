#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~Pawn();

    bool canMoveTo(int x, int y) const override;
    bool isPromotionPossible() const; // Check if pawn promotion is possible

    // Additional Pawn-specific methods (if needed)
};

#endif // PAWN_H
