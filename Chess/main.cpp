#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
// Include other necessary headers

Board board;
int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");

    // Initialize game components
    Board board; // Assumes Board constructor initializes the board
    Player whitePlayer(PlayerColor::White);
    Player blackPlayer(PlayerColor::Black);
    // Initialize other components as necessary

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle other events, like player input
        }

        // Clear screen
        window.clear();

        // Draw the board
        board.draw(window);

        // Draw other components (like UI elements) if necessary

        // Update the window
        window.display();
    }

    return 0;
}
