#include <SFML/Graphics.hpp>
#include <string>
#include "character.h"
#include <math.h>
#include <iostream>

class Game {
    private:
        sf::RenderWindow *win;
        Character* character;
        int _army_size;
        int _score;
        int _speed;
        int window_size;
    public:
        Game(int size, std::string title, int speed) {
            win = new sf::RenderWindow(sf::VideoMode(size, size), title);
            character = new Character(10, 50, 50);
            _speed = speed;
            window_size = size;
        }
        void run() {
            while (win->isOpen()) {
                sf::Event event;
                while ( win->pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        win->close();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                        character->move_left(_speed);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                        character->move_right(_speed);
                    if (character->get_y() >= 1000) {
                        character->respawn(500, 50);
                    }
                    if (character->get_x() >= 1000 || character->get_x() <= 0) {
                        character->respawn(500, 50);
                    }
                }
                win->clear();
                character->draw(win);
                win->display();
            }
        }
        ~Game(){
        };
};


int main() {
    Game game(1000, "OOP Game", 4);
    game.run();
    return 0;
}