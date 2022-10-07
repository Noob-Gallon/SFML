#include <SFML/Graphics.hpp>
#include <vector>
#include "GUN.h"
#include "NPC_SET.h"

using namespace sf;
using namespace std;


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

		gun.update(npcs);
		npcs.update();

		window.clear();
		npcs.draw(window);
		gun.draw(window);

		window.display();
	}

	return 0;
}
