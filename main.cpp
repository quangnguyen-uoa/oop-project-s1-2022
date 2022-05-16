#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bar.h"
#include "Land.h"
#include "Trap.h"
#include "gui.h"
#include <math.h>
#include <string>

class Game {
    private:
        sf::RenderWindow *win;
        Character* character;
        int _score = 0;
        int _speed = 1;
        int window_size;
        sf::Text Text;
        sf::Font Font;

    public:
        Game(int size, std::string title, int speed) {
            win = new sf::RenderWindow(sf::VideoMode(size, size + 500), title, sf::Style::Close);
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
            int speed_bar = 1;
            sf::Clock clock;
            vector<Bar*> v;
            sf::RenderWindow *gui_win = new sf::RenderWindow(sf::VideoMode(window_size, window_size + 500), "Game Menu", sf::Style::Close);
            GUI *gui = new GUI(window_size, window_size);

            while(gui_win->isOpen()) {
                sf::Event menu_event;
                while(gui_win->pollEvent(menu_event)) {
                    if (menu_event.type == sf::Event::Closed || menu_event.key.code == sf::Keyboard::Q)
                        gui_win->close();
                    if (menu_event.type == sf::Event::MouseButtonPressed) {
                        if (menu_event.mouseButton.y <= 370 && menu_event.mouseButton.y >= 300 && menu_event.mouseButton.x >= 400 && menu_event.mouseButton.x <= 570) {
                            while (win->isOpen() && character->get_life() > 0) {
                                sf::Event event;
                                sf::Time elapsed1 = clock.getElapsedTime();
                                int sec_1 = elapsed1.asSeconds();

                                while ( win->pollEvent(event)) {
                                    if (event.type == sf::Event::Closed)
                                        win->close();
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                                        character->move_left(_speed);
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                                        character->move_right(_speed);
                                }
                                

                                std::string info;
                                info = "Score " + std::to_string(sec_1) + "\n" + "Lives " + std::to_string(character->get_life()) + " ";
                                Text.setString(info);

                                if (v.empty() || (v.size() < 10 && v.back()->get_y() == 1350)) {
                                    Bar *A;
                                    if (v.size() % 3 == 0) 
                                        A = new Trap;
                                    else 
                                        A = new Land;
                                    A->spawn(win);
                                    v.push_back(A);
                                } 
                                int n = v.size();
                                for (int i = 0; i < n; ++i) {
                                    v[i]->touch(character);
                                    v[i]->draw(win, speed_bar);
                                }
                                gui_win->close();
                                character->draw(win, speed_bar);
                                win->draw(Text);
                                win->display();
                                win->clear();
                            }
                        }
                        else if (menu_event.mouseButton.y >= 400 && menu_event.mouseButton.y <= 470 && menu_event.mouseButton.x >= 400 && menu_event.mouseButton.x <= 560) {
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
        ~Game(){
            delete win;
            delete character;
        };
};


int main() {
    Game game(1000, "OOP Game", 4);
    game.run();
    return 0;
}