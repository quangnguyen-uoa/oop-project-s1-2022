#include "Bar.h"

Bar::Bar() {
    body = new sf::RectangleShape(sf::Vector2f(300, 5));
}

void Bar::spawn(sf::RenderWindow *win) {
    int pos_x = rand() % 800;
    body->setPosition(pos_x, 1500);
}

bool Bar::draw(sf::RenderWindow *win, double speed) {
    body->move(0, -0.05 * speed);
    if (body->getPosition().y >= 0.05) {
        win->draw(*body);
        return true;
    }
    else {
        spawn(win);
    }
    return false;
}

int Bar::get_x() {
    return body->getPosition().x;;
}
int Bar::get_y() {
    return body->getPosition().y;
}

int Bar::length() {
    return body->getSize().x;
}

Bar::~Bar() {
    delete body;
}