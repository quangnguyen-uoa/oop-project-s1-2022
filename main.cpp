#include <SFML/Graphics.hpp>
#include <string>
#include "character.h"
#include <math.h>
#include <iostream>
#include "gui.h"

class Game {
    private:
        sf::RenderWindow *win;
        Character* character;
        int _score = 0;
        int _speed;
        int window_size;
        sf::Text Text;
        sf::Font Font;

    public:
        Game(int size, std::string title, int speed) {
            win = new sf::RenderWindow(sf::VideoMode(size, size), title);
            character = new Character(10, 50, 50);
            _speed = speed;
            window_size = size;
            if (!Font.loadFromFile("QUICKENS.ttf")) {
                exit(0);
            }
            Text.setFont(Font);
            Text.setFillColor(sf::Color::Blue);
            Text.setCharacterSize(25); 
        }
        void run() {
            sf::RenderWindow *gui_win = new sf::RenderWindow(sf::VideoMode(window_size, window_size), "Game Menu", sf::Style::Default);
            GUI *gui = new GUI(window_size, window_size);

            while(gui_win->isOpen()) {
                sf::Event menu_event;
                while(gui_win->pollEvent(menu_event)) {
                    if (menu_event.type == sf::Event::Closed || menu_event.key.code == sf::Keyboard::Q)
                        gui_win->close();
                    if (menu_event.type == sf::Event::MouseButtonPressed) {
                        if (menu_event.mouseButton.y <= 370 && menu_event.mouseButton.y >= 300) {
                            while (win->isOpen()) {
                                sf::Event event;
                                while (win->pollEvent(event)) {
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
                                gui_win->close();
                                win->clear();
                                character->draw(win);
                                std::string info;
                                info = "Score " + std::to_string(_score) + "\n" + "Lives " + std::to_string(character->get_life()) + " ";
                                Text.setString(info);
                                win->draw(Text);
                                win->display();
                            }
                        }
                        else if (menu_event.mouseButton.y >= 400 && menu_event.mouseButton.y <= 470) {
                            gui_win->close();
                        }
                        break;
                    }
                }
                gui_win->clear();
                gui->draw(gui_win);
                gui_win->display();
            }
        }
        ~Game(){};
};


int main() {
    Game game(1000, "OOP Game", 4);
    game.run();
    return 0;
}