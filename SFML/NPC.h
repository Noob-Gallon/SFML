#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class NPC {

public:
	NPC(float _x, float _y, float _speed, Color _c);
	void update();
	void draw(RenderWindow& _window);
	bool destroyed = false;
	FloatRect getArea();
private:
	float x, y;
	float speed;
	Color c;
	RectangleShape rectShape;
	float offset_x;

};