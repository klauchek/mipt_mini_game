#include "Player.h"
#include <iostream>




Player::Player(String F, float X, float Y, float A, float B, float W, float H) : Character(F, X, Y, A, B, W, H)
{
    score = 0;
}
Player::~Player() {}


bool Player::interactionWithMap(Map& map, float time)
{
    for (int i = y / 50; i < (y + h) / 50; ++i)
    {
        for (int j = x / 50; j < (x + w) / 50; ++j)
        {
            if ((map.TileMap[i][j] == '0') || (map.TileMap[i][j] == ' '))//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
            {
                if (dy > 0)//если мы шли вниз,
                {
                    y = i * 50 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
                }
                else if (dy < 0)
                {
                    y = i * 50 + 50;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
                }
                else if (dx > 0)
                {
                    x = j * 50 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
                }
                else if (dx < 0)
                {
                    x = j * 50 + 50;//аналогично идем влево
                }
            }
           
            else if (((map.TileMap[i][j] == '3') || (map.TileMap[i][j] == '2')) && score < 1)
            {
                ++score;
                std::cout << score << std::endl;
            }
            else if (((map.TileMap[i][j] == 'X') || (map.TileMap[i][j] == '%')) && score < 2)
            {
                ++score;
            }
        }
    }

    return false;
}


bool Player::control(float time, Map& map, float& CurrentFrame, Fucker& fucker1, Fucker& fucker2)
{

    //if (mode == PATH)
        speed = 0.2;
   // else if (mode == EXAM)
      //  speed = 0.00;

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
    else if (getRect().intersects(fucker1.getRect()))
    {
        speed = 0;

    }
    else if (getRect().intersects(fucker2.getRect()))
    {
        speed = 0;
    }

    else if (score == 2)
    {
        std::cout << "WIN";
        speed = 0;
    }
    else
        speed = 0;

    return update(map, time);
}



int Player::getScore()
{
    return score;
}

void Player::setSpeed(float Speed)
{
    speed = Speed;
}