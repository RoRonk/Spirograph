#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <Complex>
#define PI std::acos(-1)
using namespace std;


std::complex<double> makeComplex(sf::Vector2f v) {
    return std::complex<double>(v.x, v.y);
}

sf::Vector2f makeVector(std::complex<double> c) {
    return sf::Vector2f(c.real(), c.imag());
}


int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "cirlces");
    sf::Vector2u size = window.getSize();
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(size.x, size.y));
    window.setView(view);

    sf::VertexArray lineStrip(sf::LineStrip, 3);
    lineStrip[0] = sf::Vertex(sf::Vector2f(0, 0));
    lineStrip[1] = sf::Vertex(sf::Vector2f(0, 300));
    lineStrip[2] = sf::Vertex(sf::Vector2f(-50, 250));

    sf::VertexArray trace(sf::LineStrip);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        auto c0 = makeComplex(lineStrip[0].position);
        auto c1 = makeComplex(lineStrip[1].position);
        auto c2 = makeComplex(lineStrip[2].position);


        //R(z) = e^(i * theta)(z - z0) + z0
        c1 = exp(1i * (0.9 * PI / 180)) * c1;

        c2 = exp(1i * (0.9 * PI / 180)) * c2;
        c2 = exp(1i * (1.3 * PI / 180)) * (c2 - c1) + c1;

        lineStrip[1].position = makeVector(c1);
        lineStrip[2].position = makeVector(c2);

        trace.append(sf::Vertex(lineStrip[2].position, sf::Color(238, 192, 255, 255)));

        Sleep(1);

        window.clear();
        window.draw(lineStrip);
        window.draw(trace);
        window.display();
    }

	return 0;
}
