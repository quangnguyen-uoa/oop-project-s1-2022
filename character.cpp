#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include "character.h"
#include <iostream>

Character::Character(int r, int x, int y) {
    body = new sf::CircleShape();
    body->setRadius(r);
    body->setPosition(x, y);
    body->setFillColor(sf::Color::Red);
    isFall = 1;
}

void Character::move_left(int speed) {
    if (get_x() > 0) 
        body->move(-speed, 0);
}

void Character::move_right(int speed) {
    if (get_x() < 980) 
        body->move(speed, 0);
}

void Character::draw(sf::RenderWindow* win, double speed) {
    win->draw(*body);
    if (isFall) {
        body->move(0, 0.1 * speed);
        if (get_y() == 1500) respawn(100, 500);
    }
    else {
        body->move(0, -0.05 * speed);
        if (get_y() == 0) respawn(100, 500);
    }
}

bool Character::check_fall() {
    return isFall;
}

void Character::stand() {
    isFall = 0;
}

void Character::fall() {
    isFall = 1;
}

int Character::get_x() {
    return body->getPosition().x;;
}
int Character::get_y() {
    return body->getPosition().y;
}
int Character::get_size() { 
    return body->getRadius() * 2;
}

int Character::get_life() {
    return lives;
}

void Character::respawn(int max_size, int min_size) {
    int new_y = rand() % max_size + min_size;
    int new_x = rand() % max_size + min_size;
    body->setPosition(new_x, new_y);
    isFall = true;
    lives--;
}

Character::~Character() {};