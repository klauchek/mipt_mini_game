#include "map.h"


Map::Map(String F)
{
    File = F;
    image.loadFromFile("game_images/maps/" + File);
    texture.loadFromImage(image);
    sprite.setTexture(texture);//заливаем спрайт текстурой


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
            case '0':s_map.setTextureRect(IntRect(102, 0, 50, 50)); break;
            case '1':s_map.setTextureRect(IntRect(0, 0, 50, 50)); break;
            case '2':s_map.setTextureRect(IntRect(51, 0, 50, 50)); break;
            case ' ':s_map.setTextureRect(IntRect(0, 51, 50, 50)); break;
            }
            s_map.setPosition((float)j * 50, (float)i * 50);
            window.draw(s_map);
        }
    }
}
