#include "NPC.h"

NPC::NPC(float _x, float _y, float _speed, Color _c) : x(_x), y(_y), speed(_speed), c(_c), offset_x(_speed) {
	rectShape = RectangleShape(Vector2f(30.0f, 10.0f));
	rectShape.setFillColor(_c);
	rectShape.setPosition(_x, _y);
}

FloatRect NPC::getArea() {
	return rectShape.getGlobalBounds();
}

void NPC::update() {

	if (destroyed == true) {
		return;
	}

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

	if (destroyed == true) {
		return;
	}

	_window.draw(rectShape);
}