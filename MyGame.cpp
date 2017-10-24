#include "MyGame.hpp"

MyGame::MyGame(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) {
    //Create the components of the game and init them
    _scrwidth = scrwidth;
    _scrheight = scrheight;
    player.setFillColor (sf::Color::Magenta);
    sf::Vector2f size(scrheight/10,scrheight/10);
    player.setSize (size);
    sf::Vector2f origin(size.x/2,size.y/2);
    player.setOrigin (origin);
    _position.x =scrwidth/2;
    _position.y = scrheight/2;
    player.setPosition (_position);
    _acc = 0;
    _speed = 10;
    _friction = 2;
    _scont = _movx = _movy = 0.0;
    _dir = None;
}

MyGame::~MyGame() {}

void MyGame::update(float deltaTime){
    // Update the game
    _scont += deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) _dir = Up;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) _dir = Down;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) _dir = Left;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))_dir = Right;
    else _dir = None;
    if(_dir != None){
        _movx += mx[_dir]*_speed*deltaTime;
        _movy += my[_dir]*_speed*deltaTime;
    }
    else{
        if(_movx >= 0.f)
            _movx = std::max(0.f, _movx - _friction*deltaTime);
        else
            _movx = std::min(0.f, _movx + _friction*deltaTime);

        if(_movy >= 0.f)
            _movy = std::max(0.f, _movy - _friction*deltaTime);
        else
            _movy = std::min(0.f, _movy + _friction*deltaTime);
    }

    _position.x += _movx;
    _position.y += _movy;
    player.setPosition (_position);

}

void MyGame::draw(){
    // Draw the game
    window.draw (player);
}

void MyGame::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
            // Add more events to handle them.
        case  sf::Event::KeyPressed:
            //Close key
            if (event.key.code == sf::Keyboard::Escape){
                window.close();
            }
            break;
        default:
            break;
        }
    }
}
