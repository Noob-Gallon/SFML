/*

NPC, Non-Player Character �����̱�

�簢���� ����������.
myRect.move(float offset_x, float offset_y)

�簢�� �����̴� �ӵ��� �����غ���

���� ���� �簢���� �����غ��� // vector�� ���� ����.
-vector

*/


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <vector>

using namespace sf;
using namespace std;

int main() {

	RenderWindow window(VideoMode(640, 480), "Hello SFML!"); // ȭ���� ũ��
	window.setFramerateLimit(30);
	CircleShape shape(50.0f, 30); // SFML Homepage�� ���� Manual�� �� �ִ�.

	vector<RectangleShape> npcs(3);
	
	int inc = 0;
	for (auto& _e : npcs) {
		_e.setSize(Vector2f(30.0f, 10.0f));
		_e.setFillColor(Color::Magenta);
		_e.setPosition(30.0f+inc, 30.0f+inc);

		inc += 20;
	}

	/*
		���� �����ڸ� ����, (float radius = 0, std::size_t pointCount = 30) ���� �Ǿ��ִ�.
		��ǻ�Ϳ����� ��� ���� �׸��Ⱑ �������, �ﰢ���� ��Ƽ� ���� �׸��� �ȴ�.
		�׷��� CircleShape�� ���������� �ﰢ������ ���� �׸��� �Ǵµ�, �� ������ ������ �� �ִ� ���̴�.
	*/
	shape.setFillColor(Color::Cyan);
	shape.setPosition(320.0f - 50.0f, 240.0f - 50.0f);
	// ���� �׸���, ���� ��ġ�� ���� �߽��� �ƴ϶�, ���� ���ΰ� �ִ� �簢���� �������� ���� ����� ��ǥ�̴�.

	float offset_x = 1.0f;

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

		for (auto& _e : npcs) {
			Vector2f pos = _e.getPosition();

			if (pos.x > 600.f) {
				offset_x = -2.0f;
			}
			else if (pos.x < 30.0f) {
				offset_x = 2.0f;
			}

			_e.move(offset_x, 0.0f);
		}

		window.clear();

		window.draw(shape);
		
		for (auto& _e : npcs) {
			window.draw(_e);
		}

		window.display();
	}

	return 0;
}
