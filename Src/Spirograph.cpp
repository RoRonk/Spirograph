#include <SFML/Graphics.hpp>
#include <cmath>

class Spirograph {
private:
    sf::VertexArray lineStrip;

public:
    Spirograph() {
        lineStrip.setPrimitiveType(sf::LineStrip);

        // Add vertices to LineStrip
        lineStrip.append(sf::Vertex(sf::Vector2f(600, 400)));
        lineStrip.append(sf::Vertex(sf::Vector2f(600, 700)));
        lineStrip.append(sf::Vertex(sf::Vector2f(500, 600)));

        // calculate distance 1st & 2nd point and adjust 3rd point to be 1/3 of that distance to the 2nd
    }

    sf::VertexArray getLines() { return lineStrip; }

    void rotate() {
        // complex multiplication e.g. *-i is 180 degree turn

    }

    // maybe not
    //double resizeThird() {
    //    sf::Vertex v0 = lineStrip[0];
    //    sf::Vertex v1 = lineStrip[1];
    //    sf::Vertex v2 = lineStrip[2];

    //    double dist = sqrt(((v1.position.x-v0.position.x)*(v1.position.x - v0.position.x))
    //                + ((v1.position.y - v0.position.y) * (v1.position.y - v0.position.y)));

    //    double veLength = dist / 3;
    //    v2.position.x = 2;
    //}
};