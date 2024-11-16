#include <SFML/Window.hpp>
#include <iostream>

int main() {
    std::cout << (sf::VideoMode::getDesktopMode().width)/2 << ", " << (sf::VideoMode::getDesktopMode().height)/2;
}
