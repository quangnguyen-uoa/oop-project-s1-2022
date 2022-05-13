#include <SFML/Graphics.hpp>
#include <string>

class Character {
    private:
        sf::CircleShape* body;
        int lives;
        int depth;
        bool isFall = true;
    public:
        Character(int r, int x, int y);
        void move_left(int speed);
        void move_right(int speed);
        void draw(sf::RenderWindow *win);
        // bool isCollide(int x, int y, int depth);
        void respawn(int max_size, int min_size);
        bool check_fall();
        int get_x();
        int get_y();
        int get_depth();
        ~Character();
};