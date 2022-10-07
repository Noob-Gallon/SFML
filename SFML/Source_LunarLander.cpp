#include <string>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

using namespace sf;
using namespace std;

class LunarLander {
private:
	double x, y; // 착륙선 현재 위치
	double velocity; // 착륙 속도
	double fuel; // 남아있는 연료량

	string status; // 현재상태
	Texture t1, t2;
	Sprite spaceship, burst; // 내가 움직이는 조각, 게임에서 캐릭터를 움직인다는 것은 조그만 patch를 움직이는 것이다. 이를 Sprite라고 한다.
	Font font; // 화면 상에 찍을 글자를 의미한다.
	Text text;
public:
	LunarLander(double h, double v, double f);
	void update(double rate);
	void draw(RenderWindow& window); // 실제적으로 그려주는 함수. window에서 받아서 그리기 위해서 window를 받아온다.
};

int main(void) {

	


	return 0;
}