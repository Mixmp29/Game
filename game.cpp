#include <SFML/Graphics.hpp>

using namespace sf;

const int H = 12;
const int W = 40;

String TileMap[H] = {

    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "B          B                      B    B",
    "B          B                           B",
    "BBBBBBB    B                           B",
    "B          BBBBBBBB    BBBB            B",
    "B          B           B  B            B",
    "B   BBBBBBBB           B  B            B",
    "B                      BBBB            B",
    "B                                      B",
    "B          BBBBBB                      B",
    "B          B                           B",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};

class PLAYER {

public:
	float dx, dy;
};

int main() {
  RenderWindow window(VideoMode(800, 800), "Test");

  CircleShape MyCircle(100.f);
  MyCircle.setFillColor(Color::Green);

  Texture t;
  t.loadFromFile("pl.jpg");

  Sprite s;
  s.setTexture(t);
  s.setTextureRect( IntRect(0, 0, 50, 50) );
  s.setPosition(100, 100);

  Clock clock;

  RectangleShape rectangle(Vector2f(32, 32));

  while (window.isOpen()) {

    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();

    time = time/500;

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
      s.move(-0.1*time, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
      s.move(0.1*time, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
      s.move(0, -0.1*time);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
      s.move(0, 0.1*time);
    }

    window.clear();

    window.clear(Color::White);

    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 30; j++) {
        if (TileMap[i][j] == 'B')
          rectangle.setFillColor(Color::Black);
        if (TileMap[i][j] == ' ')
          continue;

        rectangle.setPosition(j * 32, i * 32);
        window.draw(rectangle);
      }

    window.draw(s);
    window.display();
  }
  return 0;
}
