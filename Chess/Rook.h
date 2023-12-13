#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~Rook();

    bool canMoveTo(int x, int y) const override;
    void setHasMoved();
    bool hasMoved() const;

private:
    bool moved; // Tracks if the Rook has moved
};

#endif // ROOK_H
