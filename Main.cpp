#include <SFML/Graphics.hpp>
#include <string>
#include "Character.h"
#include "Bar.h"
#include "Land.h"
#include "Trap.h"
#include <math.h>
#include <iostream>

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
            win = new sf::RenderWindow(sf::VideoMode(size, size + 500), title, sf::Style::Close);
            character = new Character(20, 50, 50);
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
            sf::Clock clock;
            vector<Bar*> v;
            int speed = 1;
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
                    v[i]->draw(win, speed);
                }
                //cout << A->get_x() << ' ' << A->get_y() << '\n';
                
                
                character->draw(win, speed);
                win->draw(Text);
                win->display();
                win->clear();
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