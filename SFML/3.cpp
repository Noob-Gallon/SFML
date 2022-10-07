/*

npc가 각각의 특징을 갖게 하기 위해, npc라는 클래스를 생성한다.

*/


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class NPC {

public:
	NPC(float _x, float _y, float _speed, Color _c);
	void update();
	void draw(RenderWindow& _window);
private:
	float x, y;
	float speed;
	Color c;
	RectangleShape rectShape;
	float offset_x;

};

NPC::NPC(float _x, float _y, float _speed, Color _c) : x(_x), y(_y), speed(_speed), c(_c), offset_x(_speed) {
	rectShape = RectangleShape(Vector2f(30.0f, 10.0f));
	rectShape.setFillColor(_c);
	rectShape.setPosition(_x, _y);
}

void NPC::update() {
	Vector2f pos = rectShape.getPosition();

	if (pos.x > 600.0f) {
		offset_x = -speed;
	} 
	else if (pos.x < 30.0f) {
		offset_x = speed;
	}

	rectShape.move(offset_x, 0.0f);
}

void NPC::draw(RenderWindow& _window) {
	_window.draw(rectShape);
}

class NPC_SET {
private:
	vector<NPC> npcs;
public:
	NPC_SET(int _num);
	void update();
	void draw(RenderWindow& _window);
};

NPC_SET::NPC_SET(int _num) {

	int inc = 0;
	Color colors[3] = { Color::Red, Color::Green, Color::Magenta };

	for (int i = 0; i < _num; i++) {
		NPC npc(30.0f + inc, 30.0f + inc, (i + 1) * 2, colors[i%3]);
		npcs.push_back(npc);
		inc += 20;
	}
}

void NPC_SET::update() {

	for (auto& _e : npcs) {
		_e.update();
	}

}

void NPC_SET::draw(RenderWindow& _window) {

	for (auto& _e : npcs) {
		_e.draw(_window);
	}

}

int main() {

	RenderWindow window(VideoMode(640, 480), "Hello SFML!"); // 화면의 크기
	window.setFramerateLimit(30);
	CircleShape shape(50.0f, 30); // SFML Homepage에 가면 Manual이 다 있다.
	shape.setFillColor(Color::Green);
	shape.setPosition(320.0f - 50.0f, 480.0f - 50.0f);

	NPC_SET npcs(5);

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

		npcs.update();

		window.clear();
		window.draw(shape);
		npcs.draw(window);
		window.display();
	}

	return 0;
}
