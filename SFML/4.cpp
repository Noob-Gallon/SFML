/*

Let's fire a bullet!


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
		NPC npc(30.0f + inc, 30.0f + inc, (i + 1) * 2, colors[i % 3]);
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

class GUN {
private:
	CircleShape gun;
	CircleShape bullet;
	bool showBullet;
public:
	GUN();
	void moveLeft();
	void moveRight();
	void fireBullet();
	void update();
	void draw(RenderWindow& _window);
};

void GUN::moveLeft() {
	gun.move(-10.0f, 0.0f);
}

void GUN::moveRight() {
	gun.move(10.0f, 0.0f);
}

void GUN::fireBullet() {
	if (showBullet == false) {
		Vector2f pos = gun.getPosition();
		bullet.setPosition(pos.x + 50.0f, pos.y); // Vector 2f도 동그라미 이므로, 위치를 조정해준다.
		showBullet = true;
	}
}

void GUN::update() {

	if (showBullet == true) {
		bullet.move(0.0f, -8.0f);

		if (bullet.getPosition().y < -10.0f) {
			showBullet = false;
		}
	}
}

void GUN::draw(RenderWindow& _window) {
	_window.draw(gun);
	
	if (showBullet == true) {
		_window.draw(bullet);
	}
}

GUN::GUN() {
	gun = CircleShape(50.0f);
	gun.setFillColor(Color::Green);
	gun.setPosition(320.0f - 50.0f, 480.0f - 50.0f);

	showBullet = false;
	bullet = CircleShape(5.0f);
	bullet.setFillColor(Color::Red);
}

int main() {

	RenderWindow window(VideoMode(640, 480), "Hello SFML!"); // 화면의 크기
	window.setFramerateLimit(30);

	NPC_SET npcs(6);
	GUN gun;

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {

			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left) == true) {
					gun.moveLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
					gun.moveRight();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space) == true) {
					gun.fireBullet();
				}
				break;
			default:
				break;
			}
		}

		gun.update();
		npcs.update();

		window.clear();
		npcs.draw(window);
		gun.draw(window);

		window.display();
	}

	return 0;
}
