#include "Fucker.h"

Fucker::Fucker(String F, float X, float Y, float A, float B, float W, float H) : Character(F, X, Y, A, B, W, H) {}
Fucker::~Fucker() {}


int Fucker::get_direction()
{
    return direction;
}

void Fucker::set_direction(int dir)
{
    direction = dir;
}

bool Fucker::control(float time, Map& map)
{
    speed = 0.15;

    switch (direction)
    {
    case UP:
        sprite.setTextureRect(IntRect(0, 0, 55, 55));
        break;
    case RIGHT:
        sprite.setTextureRect(IntRect(0, 0, 55, 55));
        break;
    case DOWN:
        sprite.setTextureRect(IntRect(0, 0, 55, 55));
        break;
    case LEFT:
        sprite.setTextureRect(IntRect(0, 0, 55, 55));
        break;
    default:
        break;
    }

    return update(map, time);
}

//now the same as Player has
bool Fucker::interactionWithMap(Map& map, float time)
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

    return false;
}

