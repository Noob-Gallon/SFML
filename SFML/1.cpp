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

	RenderWindow window(VideoMode(640, 480), "Hello SFML!"); // ȭ���� ũ��
	CircleShape shape(50.0f, 30); // SFML Homepage�� ���� Manual�� �� �ִ�.
	/*
		���� �����ڸ� ����, (float radius = 0, std::size_t pointCount = 30) ���� �Ǿ��ִ�.
		��ǻ�Ϳ����� ��� ���� �׸��Ⱑ �������, �ﰢ���� ��Ƽ� ���� �׸��� �ȴ�.
		�׷��� CircleShape�� ���������� �ﰢ������ ���� �׸��� �Ǵµ�, �� ������ ������ �� �ִ� ���̴�.
	*/
	shape.setFillColor(Color::Cyan);
	shape.setPosition(320.0f-50.0f, 240.0f-50.0f);
	// ���� �׸���, ���� ��ġ�� ���� �߽��� �ƴ϶�, ���� ���ΰ� �ִ� �簢���� �������� ���� ����� ��ǥ�̴�.

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
