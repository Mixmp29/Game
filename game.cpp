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
  FloatRect rect;
  bool onGround;
  Sprite sprite;
  float currentFrame;

  PLAYER(Texture &image) {
    sprite.setTexture(image);
    rect = FloatRect(7 * 32, 9 * 32, 40, 50);

    dx = dy = 0.1;
    currentFrame = 0;
  }

  void update(float time) {
    rect.left += dx * time;
    currentFrame += 0.005 * time;
    if (currentFrame > 6)
      currentFrame -= 6;

    if (dx > 0)
      sprite.setTextureRect(IntRect(40 * int(currentFrame), 244, 40, 50));
    if (dx < 0)
      sprite.setTextureRect(IntRect(40 * int(currentFrame) + 40, 244, -40, 50));

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

    dx = 0;
  }
};

int main() {
  RenderWindow window(VideoMode(800, 800), "Test");

  CircleShape MyCircle(100.f);
  MyCircle.setFillColor(Color::Green);

  Texture t;
  t.loadFromFile("pl.jpg");

  Sprite s;
  s.setTexture(t);
  s.setPosition(100, 100);

  RectangleShape rectangle(Vector2f(32, 32));

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
      s.move(-0.1, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
      s.move(0.1, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
      s.move(0, -0.1);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
      s.move(0, 0.1);
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
