#ifndef __CHARACTER__H__
#define __CHARACTER__H__

#include "map.h"
#include <SFML/Graphics.hpp>
using namespace sf;

enum directions
{
	RIGHT = 1,
	LEFT,
	UP,
	DOWN
};



class Character
{
protected:
	float x, y, a, b, w, h, dx, dy, speed; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int direction; //направление  движения игрока
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт

public:

	Character(String F, float X, float Y, float A, float B, float W, float H); //конструктор для всех одинаковый, новых полей не повятся - только методы
	~Character();

	Sprite get_sprite();
	bool update(Map& map, float time); //реализация одинаковая, просто обработка направлений движения
	virtual bool interactionWithMap(Map& map, float time) = 0;//у каждого своя реализация, правда, отличия небольшие - у playera добавится только обработка препятствий
	//virtual void control(float time, float& CurrentFrame) = 0;
	//override??




};

#endif //!__CHATACTER__H__
