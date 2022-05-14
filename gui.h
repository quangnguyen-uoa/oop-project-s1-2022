#include <iostream>
#include <SFML/Graphics.hpp>

class GUI {
    public:
        GUI(int height, int width);
        void draw(sf::RenderWindow *window);
        void move_up();
        void move_down();
        int clicked();
        ~GUI();
    
    private:
        int menuSelected;
        sf::Font font;
        sf::Text menu[2];
        sf::Text GameName;
};