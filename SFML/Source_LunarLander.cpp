#include <string>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

using namespace sf;
using namespace std;

class LunarLander {
private:
	double x, y; // ������ ���� ��ġ
	double velocity; // ���� �ӵ�
	double fuel; // �����ִ� ���ᷮ

	string status; // �������
	Texture t1, t2;
	Sprite spaceship, burst; // ���� �����̴� ����, ���ӿ��� ĳ���͸� �����δٴ� ���� ���׸� patch�� �����̴� ���̴�. �̸� Sprite��� �Ѵ�.
	Font font; // ȭ�� �� ���� ���ڸ� �ǹ��Ѵ�.
	Text text;
public:
	LunarLander(double h, double v, double f);
	void update(double rate);
	void draw(RenderWindow& window); // ���������� �׷��ִ� �Լ�. window���� �޾Ƽ� �׸��� ���ؼ� window�� �޾ƿ´�.
};

int main(void) {

	


	return 0;
}