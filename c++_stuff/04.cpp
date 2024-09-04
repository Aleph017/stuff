#include <SFML/Graphics.hpp>

int main(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle");

    sf::CircleShape circle(50);
    circle.setPosition(350, 250);
    circle.setFillColor(sf::Color::Black);

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(circle);
        window.display();
    }

    return 0;
}