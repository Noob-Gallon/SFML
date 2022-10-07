#pragma once
#include <vector>
#include "NPC.h"

using namespace std;
using namespace sf;

class NPC_SET {
private:
	vector<NPC> npcs;
public:
	NPC_SET(int _num);
	void update();
	void draw(RenderWindow& _window);
	void checkHit(FloatRect _rect);
};