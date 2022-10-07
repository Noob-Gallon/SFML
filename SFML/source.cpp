#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

	// SFML�� ��κ� windows ���Ǻ��� �����ϸ�, sf:: �� namespace�� �ǹ��Ѵ�.
	// VideoMode( , )�� ���� ���� ������ ȭ�� ũ���̴�. (����, ����)
	// RenderWindow class�� Constructor�� ȣ���Ѵ�.
	// VideoMode ���� Class�̴�.
	// ȭ�鿡 �׷��ִ� ���� Render��� �ϸ�, ���� ȭ���� �׷��ִ� â�̶�� ������ RenderWindow�� ����Ѵ�.
	RenderWindow window(VideoMode(200, 200), "First Example");

	// Constructor���� �ϳ��� argument�� �޴µ�, �̴� �������̴�.
	CircleShape shape(100.0f);

	// ���� �׸��µ�, ���� ����� �� ä���� ���̶�� ���̴�.
	shape.setFillColor(Color::Green);

	// �Ƶ��̳�� �����ϴ� ����� ����ѵ�, �Ƶ��̳�� setup�� ������ infinite loop�� ����.
	// ���� ���α׷��ֵ� ���������� infinite loop�� ���� ������ �����Ѵ�.

	while (window.isOpen()) {

		Event e; // event��, ���콺�� �����̰ų� â�� �ǵ帮�� �� ����� �����ϴ� ������ ���� Event��� ����.

		// click event, drag event ���... �پ��� event�� �����Ѵ�.
		// window.pollEvent()�� ����ڰ� event�� �߻����״��� �����Ѵٴ� ���̴�.
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();

		// draw(object) �Ѵٰ� �׸��� �ٷ� �׷����� �ʴ´�. draw�� �ϸ� �׷��� ī�� �޸𸮿� ��ü�� �ε��ǰ�,
		// display()�� �����ϸ� �׸��� �׷�����.
		window.draw(shape);
		window.display();

	}

	return 0;
}