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
	float x, y, a, b, w, h, dx, dy, speed; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int direction; //�����������  �������� ������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������

public:

	Character(String F, float X, float Y, float A, float B, float W, float H); //����������� ��� ���� ����������, ����� ����� �� ������� - ������ ������
	~Character();

	Sprite get_sprite();
	bool update(Map& map, float time); //���������� ����������, ������ ��������� ����������� ��������
	virtual bool interactionWithMap(Map& map, float time) = 0;//� ������� ���� ����������, ������, ������� ��������� - � playera ��������� ������ ��������� �����������
	//virtual void control(float time, float& CurrentFrame) = 0;
	//override??




};

#endif //!__CHATACTER__H__
