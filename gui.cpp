#include "gui.h"
#include <SFML/Graphics.hpp>

GUI::GUI(int height, int width) {
    if (!font.loadFromFile("QUICKENS.ttf")) {
        exit(0);
    }
    menu[0].setFont(font);
    menu[0].setString("Play");
    menu[0].setCharacterSize(80);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setPosition(400, 300); 

    menu[1].setFont(font);
    menu[1].setString("Quit");
    menu[1].setCharacterSize(80);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(400, 400); 

    GameName.setFont(font);
    GameName.setFillColor(sf::Color::Blue);
    GameName.setString("FALL GUY");
    GameName.setCharacterSize(100);
    GameName.setPosition(280, 50);
}

GUI::~GUI() {}

void GUI::draw(sf::RenderWindow *window) {

    window->draw(GameName);

    for (int i = 0; i < 2; i++) {
        window->draw(menu[i]);
    }
}
