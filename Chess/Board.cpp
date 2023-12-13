#include "Board.h"

Board::Board() {
    // Load textures for each piece type
    texturePawn.loadFromFile("images/Pawn.png");
    textureRook.loadFromFile("images/Rook.png");
    textureKnight.loadFromFile("images/Knight.png");
    textureBishop.loadFromFile("images/Bishop.png");
    textureKing.loadFromFile("images/King.png");
    textureQueen.loadFromFile("images/Queen.png");

    // Load other textures

    setupBoard();
}

Board::~Board() {
    clearBoard();
}

void Board::setupBoard() {
    clearBoard();
    placePieces();
}

void Board::draw(sf::RenderWindow& window) {
    // Define the size of a square on the board
    const int squareSize = 60; // Example size, adjust as needed

    // Draw the board (grid, colors, etc.)
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            // Create a square
            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));

            // Set the position of the square
            square.setPosition(x * squareSize, y * squareSize);

            // Alternate the square colors
            if ((x + y) % 2 == 0) {
                square.setFillColor(sf::Color::White);
            }
            else {
                square.setFillColor(sf::Color::Black);
            }

            // Draw the square
            window.draw(square);
        }
    }

    // Draw the pieces
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Piece* piece = squares[y][x];
            if (piece) {
                piece->draw(window);
            }
        }
    }
}


Piece* Board::getPieceAt(int x, int y) const{
    return squares[y][x];
}

void Board::movePiece(int fromX, int fromY, int toX, int toY) {
    if (!isMoveLegal(fromX, fromY, toX, toY)) {
        return; // Move is not legal
    }

    Piece* piece = squares[fromY][fromX];
    squares[toY][toX] = piece;
    squares[fromY][fromX] = nullptr;

    if (piece) {
        piece->setPosition(toX, toY);
    }
}

bool Board::isMoveLegal(int fromX, int fromY, int toX, int toY) {
    Piece* piece = getPieceAt(fromX, fromY);
    if (piece && piece->canMoveTo(toX, toY)) {
        // Add additional checks (like checking for check, etc.)
        return true;
    }
    return false;
}

bool Board::isPathClear(int startX, int startY, int endX, int endY) const {
    // Determine the direction of movement
    int deltaX = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
    int deltaY = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

    int currentX = startX + deltaX;
    int currentY = startY + deltaY;

    // Traverse the path
    while (currentX != endX || currentY != endY) {
        if (getPieceAt(currentX, currentY) != nullptr) {
            return false; // Path is not clear
        }

        currentX += deltaX;
        currentY += deltaY;
    }

    return true; // Path is clear
}


void Board::placePieces() {
    // Place Pawns
    for (int i = 0; i < 8; i++) {
        squares[1][i] = new Pawn(i, 1, PieceColor::White, texturePawn);
        squares[6][i] = new Pawn(i, 6, PieceColor::Black, texturePawn);
    }

    // Place Rooks
    squares[0][0] = new Rook(0, 0, PieceColor::White, textureRook);
    squares[0][7] = new Rook(7, 0, PieceColor::White, textureRook);
    squares[7][0] = new Rook(0, 7, PieceColor::Black, textureRook);
    squares[7][7] = new Rook(7, 7, PieceColor::Black, textureRook);

    // Place Knights
    squares[0][1] = new Knight(1, 0, PieceColor::White, textureKnight);
    squares[0][6] = new Knight(6, 0, PieceColor::White, textureKnight);
    squares[7][1] = new Knight(1, 7, PieceColor::Black, textureKnight);
    squares[7][6] = new Knight(6, 7, PieceColor::Black, textureKnight);

    // Place Bishops
    squares[0][2] = new Bishop(2, 0, PieceColor::White, textureBishop);
    squares[0][5] = new Bishop(5, 0, PieceColor::White, textureBishop);
    squares[7][2] = new Bishop(2, 7, PieceColor::Black, textureBishop);
    squares[7][5] = new Bishop(5, 7, PieceColor::Black, textureBishop);

    // Place Queens
    squares[0][3] = new Queen(3, 0, PieceColor::White, textureQueen);
    squares[7][3] = new Queen(3, 7, PieceColor::Black, textureQueen);

    // Place Kings
    squares[0][4] = new King(4, 0, PieceColor::White, textureKing);
    squares[7][4] = new King(4, 7, PieceColor::Black, textureKing);
}


void Board::clearBoard() {
    for (auto& row : squares) {
        for (auto& piece : row) {
            if (piece != nullptr) {
                delete piece;
                piece = nullptr;
            }
        }
    }
}

