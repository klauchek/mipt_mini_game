#include "Fucker.h"

Fucker::Fucker(String F, float X, float Y, float A, float B, float W, float H) : Character(F, X, Y, A, B, W, H) {}
Fucker::~Fucker() {}


void Fucker::control(float time, int dir)
{
    direction = dir;
    speed = 0.15;

    switch (direction)
    {
    case UP:
    case RIGHT:
    case DOWN:
    case LEFT: sprite.setTextureRect(IntRect(0, 0, 55, 55));
        break;
    default:
        break;
    }

}

//now the same as Player has
void Fucker::interactionWithMap(Map& map, float time)
{
    for (int i = y / 51; i < (y + h) / 51; ++i)
    {
        for (int j = x / 51; j < (x + w) / 51; ++j)
        {
            if (map.TileMap[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
            {
                if (dy > 0)//���� �� ��� ����,
                {
                    y = i * 51 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
                }
                else if (dy < 0)
                {
                    y = i * 51 + 51;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
                }
                else if (dx > 0)
                {
                    x = j * 51 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
                }
                else if (dx < 0)
                {
                    x = j * 51 + 51;//���������� ���� �����
                }
            }
            //else if (map.TileMap[i][j] == ' ')
            //{
            //    float cur_time = time;
            //    while (time < cur_time + 10000)
            //    {
            //        speed = 0;
            //        sprite.setPosition(300, 300);
            //    }
            //}
        }
    }
}

