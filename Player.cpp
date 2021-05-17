#include "Player.h"



Player::Player(String F, float X, float Y, float A, float B, float W, float H) : Character(F, X, Y, A, B, W, H) {}
Player::~Player() {}

void Player::interactionWithMap(Map& map, float time)
{
    for (int i = y / 34; i < (y + h) / 34; ++i)
    {
        for (int j = x / 32; j < (x + w) / 32; ++j)
        {
            if (map.TileMap[i][j] == '0')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
            {
                if (dy > 0)//если мы шли вниз,
                {
                    y = i * 32 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
                }
                else if (dy < 0)
                {
                    y = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
                }
                else if (dx > 0)
                {
                    x = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
                }
                else if (dx < 0)
                {
                    x = j * 32 + 32;//аналогично идем влево
                }
            }
            else if (map.TileMap[i][j] == ' ')
            {
                float cur_time = time;
                while (time != (cur_time + 1000000))
                {
                    dx = 0;
                    dy = 0;
                }
            }
        }
    }
}


void Player::control(float time, float& CurrentFrame)
{
    speed = 0.2;
    CurrentFrame += 0.005f * time;

    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        direction = RIGHT;
        CurrentFrame = CurrentFrame > 3 ? 0 : CurrentFrame;
        sprite.setTextureRect(IntRect(100 + 41 * int(CurrentFrame), 0, 41, 57));
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        direction = LEFT;
        CurrentFrame = CurrentFrame > 3 ? 0 : CurrentFrame;
        sprite.setTextureRect(IntRect(100 + 41 * int(CurrentFrame + 1), 0, -41, 57));
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        direction = UP;
        CurrentFrame = CurrentFrame > 1 ? 0 : CurrentFrame;
        sprite.setTextureRect(IntRect(45 + 41 * int(CurrentFrame), 0, 41, 57));
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        direction = DOWN;
        CurrentFrame = CurrentFrame > 1 ? 0 : CurrentFrame;
        sprite.setTextureRect(IntRect(41 * int(CurrentFrame), 0, 41, 57));
    }
    else
        speed = 0;

}