#include "GUN.h"

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

void GUN::update(NPC_SET& npcs) {

	if (showBullet == true) {
		bullet.move(0.0f, -8.0f);

		if (bullet.getPosition().y < -10.0f) {
			showBullet = false;
		}
		else {
			// Bullet의 FloatRect를 구해서, 
			// NPC_SET 객체의 checkHit()을 호출하면 된다.
			npcs.checkHit(bullet.getGlobalBounds());
			// 왜 checkHit에는 참조자로 인수를 전달해줄 수가 없는가?
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