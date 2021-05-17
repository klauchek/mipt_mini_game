#include "map.h"


Map::Map(String F)
{
    File = F;
    image.loadFromFile("game_images/maps/" + File);
    texture.loadFromImage(image);
    sprite.setTexture(texture);//�������� ������ ���������


}

Map::~Map() {}

//(IntRect(0, 0, w, h)); 

Sprite& Map::get_sprite()
{
    Sprite& s = sprite;
    return s;
}


void Map::draw_map(Sprite& s_map, RenderWindow& window)
{
    for (int i = 0; i < HEIGHT_MAP; i++)
    {
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            switch (TileMap[i][j])
            {
            case '0':s_map.setTextureRect(IntRect(102, 0, 51, 51)); break;
            case '1':s_map.setTextureRect(IntRect(0, 0, 51, 51)); break;
            case '2':s_map.setTextureRect(IntRect(51, 0, 51, 51)); break;
            case ' ':s_map.setTextureRect(IntRect(0, 51, 51, 51)); break;
            }
            s_map.setPosition((float)j * 51, (float)i * 51);
            window.draw(s_map);
        }
    }
}
