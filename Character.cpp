#include "Character.h"

Character::Character(String F, float X, float Y, float A, float B, float W, float H)
{  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
    File = F;//имя файла+расширение
    w = W; h = H;//высота и ширина
    x = X; y = Y;//координата появления спрайта
    a = A; b = B;
    dx = 0;
    dy = 0;
    speed = 0;
    direction = 0;


    image.loadFromFile("game_images/" + File);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    //sprite.setTextureRect(IntRect(0, 0, w, h));  //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
    sprite.setTextureRect(IntRect(a, b, w, h));
}

Character::~Character() {}

Sprite Character::get_sprite()
{
    return sprite;

}

void Character::update(float time)
{
    {
        switch (direction)
        {
        case DOWN: dx = 0;
            dy = speed;
            break;

        case UP:   dx = 0;
            dy = -speed;
            break;

        case RIGHT:dx = speed;
            dy = 0;
            break;

        case LEFT: dx = -speed;
            dy = 0;
            break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
    }

}






