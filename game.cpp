#include <SFML/Graphics.hpp>

using namespace sf;

float offsetX=0, offsetY=0;

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
	Sprite sprite;
	
	PLAYER(Texture &image)
	{
		sprite.setTexture(image);
		rect = FloatRect(50, 40, 50, 50);

		dx = dy = 0;
	}
	void update(float time)
	{
		rect.left += dx * time;
		rect.top += dy * time;
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
		dy = 0;
	}
};

int main() {
  RenderWindow window(VideoMode(800, 800), "Test");

  CircleShape MyCircle(100.f);
  MyCircle.setFillColor(Color::Green);

  Texture t;
  t.loadFromFile("pl.jpg");


  PLAYER p(t); 

 
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
      p.dx =  -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
      p.dx = 0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
      p.dy = -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
      p.dy = 0.1;
    }

    window.clear();

    offsetX = p.rect.left - 800/2;
    offsetY = p.rect.top - 800/2;

    window.clear(Color::White);

    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 30; j++) {
        if (TileMap[i][j] == 'B')
          rectangle.setFillColor(Color::Black);
        if (TileMap[i][j] == ' ')
          continue;

        rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY);
        window.draw(rectangle);
      }

    p.update(time);

    window.draw(p.sprite);
    window.display();
  }
  return 0;
}
