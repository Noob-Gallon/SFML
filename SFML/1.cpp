/*

CircleShape::setPosition(float x, float y)

RectangleShape, Vector2f

Event.type, KeyPressed

keyboard, isKeyPressed

CircleShape::move(float offset_x, float offset_y)

*/


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>

using namespace sf;

int main() {

	RenderWindow window(VideoMode(640, 480), "Hello SFML!"); // 화면의 크기
	CircleShape shape(50.0f, 30); // SFML Homepage에 가면 Manual이 다 있다.
	/*
		실제 생성자를 보면, (float radius = 0, std::size_t pointCount = 30) 으로 되어있다.
		컴퓨터에서는 사실 원을 그리기가 어려워서, 삼각형을 모아서 원을 그리게 된다.
		그래서 CircleShape도 마찬가지로 삼각형으로 원을 그리게 되는데, 이 개수를 지정할 수 있는 것이다.
	*/
	shape.setFillColor(Color::Cyan);
	shape.setPosition(320.0f-50.0f, 240.0f-50.0f);
	// 원을 그릴때, 원의 위치는 원의 중심이 아니라, 원을 감싸고 있는 사각형을 기준으로 좌측 상단의 좌표이다.

	RectangleShape myRect(Vector2f(30.0f, 10.0f));
	myRect.setFillColor(Color::Magenta);
	myRect.setPosition(30.0f, 30.0f);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			
			switch (event.type) {

			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left) == true) {
					shape.move(-10.0f, 0.0f);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
					shape.move(10.0f, 0.0f);
				}
			default:
				break;
			}

		}

		window.clear();

		window.draw(shape);
		window.draw(myRect);

		window.display();
	}

	return 0;
}
