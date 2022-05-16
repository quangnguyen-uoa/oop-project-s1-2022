#include "Trap.h"

Trap::Trap() {
    body->setFillColor(sf::Color::Red);
    body->setSize(sf::Vector2f(200, 5));
}

void Trap::touch(Character* character) {
    if (character->get_y() + character->get_size() == get_y()) {
        int char_x = character->get_x();
        int bar_x = get_x();
        if (char_x >= bar_x - character->get_size() && char_x <= bar_x + length())      
            character->respawn(100, 500);
    }
}


Trap::~Trap() {
    
}