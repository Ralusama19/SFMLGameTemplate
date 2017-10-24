#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"

class MyGame : public Game {
public:
    MyGame(int scrwidth, int scrheight, std::string title, int style);
    ~MyGame();
    void update(float deltaTime);
    void draw();
    void processEvents();
private:
    //The components of the game
    sf::RectangleShape player;
    sf::Vector2f _position;
    int _scrwidth, _scrheight;
    float _scont, _speed, _acc, _friction, _movx, _movy;
    enum Direction { Down, Left, Right, Up , None};
    const int mx[5] = {0,	-1,    1,   0,   0};
    const int my[5] = {1,	 0,    0,  -1,   0};
    Direction _dir;

    //bool onScreen(float posX, float posY);
};

#endif // MYGAME_H
