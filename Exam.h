#ifndef __EXAM__H__
#define __EXAM__H__

#include <SFML/Graphics.hpp>
using namespace sf;

class ExamBar
{
private:
	Image image;
	Texture t;
	Sprite s;
	int max;
	RectangleShape bar;

public:


	ExamBar();
	~ExamBar();

	void update(int score);
	void draw(RenderWindow& window);
};




#endif // !__EXAM__H__

