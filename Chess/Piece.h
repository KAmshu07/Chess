#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

enum class PieceColor { White, Black };

class Piece {
public:
    Piece(int x, int y, PieceColor color, const sf::Texture& texture);
    virtual ~Piece();

    virtual void draw(sf::RenderWindow& window) const;
    virtual bool canMoveTo(int x, int y) const = 0; // Pure virtual function for specific piece movement logic
    void setPosition(int x, int y);

    int getX() const;
    int getY() const;
    PieceColor getColor() const;

protected:
    int posX, posY;
    PieceColor color;
    sf::Sprite sprite; // SFML sprite for rendering the piece
};

#endif // PIECE_H
