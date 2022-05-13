#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include "Character.h"
#include <iostream>

Character::Character(int r, int x, int y) {
    body = new sf::CircleShape();
    body->setRadius(r);
    body->setPosition(x, y);
    body->setFillColor(sf::Color::Red);
    depth = r;
}

void Character::move_left(int speed) {
    body->move(-speed, 0);
}

void Character::move_right(int speed) {
    body->move(speed, 0);
}

void Character::draw(sf::RenderWindow* win) {
    win->draw(*body);
    if (isFall)
        body->move(0, 0.05);
}

bool Character::check_fall() {
    return isFall;
}

int Character::get_x() {
    return body->getPosition().x;;
}
int Character::get_y() {
    return body->getPosition().y;
}
int Character::get_depth() { 
    return depth;
}

int Character::get_life() {
    return lives;
}

void Character::respawn(int max_size, int min_size) {
    int new_y = rand() % max_size + min_size;
    int new_x = rand() % max_size + min_size;
    body->setPosition(new_x, new_y);
    isFall = true;
}

Character::~Character() {};