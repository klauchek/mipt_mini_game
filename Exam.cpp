#include "Exam.h"

ExamBar::ExamBar()
{
	image.loadFromFile("game_images/exam.png");
	t.loadFromImage(image);
	s.setTexture(t);
	s.setTextureRect(IntRect(0, 0, 173, 35));

	bar.setFillColor(Color(0, 0, 0));//черный прямоугольник накладывается сверху и появляется эффект отсутствия здоровья
	max = 80;

	bar.setSize(Vector2f(max, 28));
}

ExamBar:: ~ExamBar() {}

void ExamBar::update(int k)// k-текущее здоровье

{
	if (k > 0)
		if (k < 3)
			bar.setSize(Vector2f(max - 40*k, 28)); 
}

void ExamBar:: draw(RenderWindow& window)
{
	Vector2f center = window.getView().getCenter();
	Vector2f size = window.getView().getSize();

	s.setPosition(center.x - size.x / 2 + 15, center.y - size.y / 2 + 15);//позиция на экране
	bar.setPosition(center.x - size.x / 2 + 110, center.y - size.y / 2 + 17);

	window.draw(s);//сначала рисуем полоску здоровья
	window.draw(bar);//поверх неё уже черный прямоугольник, он как бы покрывает её
}