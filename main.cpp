#include <Resources.hpp>
#include <MyGame.hpp>

int main() {
    Resources::load();
    MyGame mygame(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height,"MyGame",sf::Style::Default);
    mygame.run();
    return 0;
}

