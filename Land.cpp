#include "Land.h"

Land::Land() {
    body->setFillColor(sf::Color::Green);
}

void Land::touch(Character* character) {
    if (character->get_y() + character->get_size() == get_y()) {
        int char_x = character->get_x();
        int bar_x = get_x();
        if (char_x >= bar_x - character->get_size() && char_x <= bar_x + length()) character->stand();
        else character->fall();
    }
}


Land::~Land() {
    
}