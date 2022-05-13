#include "Bar.h"

Bar::Bar() {
    body = new sf::RectangleShape(sf::Vector2f(30.f, 200.f));
}

void Bar::spawn(sf::RenderWindow *win) {
    int pos_x = rand() % win->getSize().x + 1;
    body->setPosition(pos_x, win->getSize().y);
} 

void Bar::draw(sf::RenderWindow *win) {
    body->move(0, -0.25);
    if (body->getPosition().y <= win->getSize().y) win->draw(*body);
}

Bar::~Bar() {
    delete body;
}