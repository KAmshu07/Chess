#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~King();

    bool canMoveTo(int x, int y) const override;
    // Additional King-specific methods, like for castling (if implemented)

private:
    bool isCastlingMove(int x, int y) const;
};

#endif // KING_H
