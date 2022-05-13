#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Bar {
public:
    Bar();
    void spawn(sf::RenderWindow*);
    virtual void touch() = 0;
    void draw(sf::RenderWindow*);
    ~Bar();
protected:
    sf::RectangleShape *body;
    int speed;
};