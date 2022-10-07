#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

	// SFML은 대부분 windows 정의부터 시작하며, sf:: 는 namespace를 의미한다.
	// VideoMode( , )는 내가 만든 게임의 화면 크기이다. (가로, 세로)
	// RenderWindow class의 Constructor를 호출한다.
	// VideoMode 또한 Class이다.
	// 화면에 그려주는 것을 Render라고 하며, 게임 화면을 그려주는 창이라는 뜻으로 RenderWindow를 사용한다.
	RenderWindow window(VideoMode(200, 200), "First Example");

	// Constructor에서 하나의 argument를 받는데, 이는 반지름이다.
	CircleShape shape(100.0f);

	// 원을 그리는데, 원이 색깔로 꽉 채워진 원이라는 뜻이다.
	shape.setFillColor(Color::Green);

	// 아두이노와 개발하는 방식이 비슷한데, 아두이노는 setup이 끝나면 infinite loop을 돈다.
	// 게임 프로그래밍도 마찬가지로 infinite loop을 만들어서 동작을 구현한다.

	while (window.isOpen()) {

		Event e; // event란, 마우스를 움직이거나 창을 건드리는 등 사람이 조작하는 행위를 전부 Event라고 본다.

		// click event, drag event 등등... 다양한 event가 존재한다.
		// window.pollEvent()는 사용자가 event를 발생시켰는지 조사한다는 뜻이다.
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();

		// draw(object) 한다고 그림이 바로 그려지지 않는다. draw를 하면 그래픽 카드 메모리에 객체가 로딩되고,
		// display()를 실행하면 그림이 그려진다.
		window.draw(shape);
		window.display();

	}

	return 0;
}