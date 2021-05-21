#ifndef __MAP__H__
#define __MAP__H__

#include "SFML/Graphics.hpp"

using namespace sf;



class Map
{
private:
    static const int HEIGHT_MAP = 14;
    static const int WIDTH_MAP = 26;
    Image image;
    Texture texture;
    Sprite sprite;
    String File;



public:



    String TileMap[HEIGHT_MAP] = {
    "00000000000000000000000000",
    "0 abcdefgh               0",
    "0 ABCDEFGH     11111111  0",
    "0 ijklmnop     11111111  0",
    "0 IJKLMNOP     11    11  0",
    "0 {}[]()23 111111    11  0",
    "0       111111111    11  0",
    "0   11111111         11  0",
    "0   1111111 qrstuvwx 11110",
    "0   11      QRSTUVWX111110",
    "0111111111  456789?%111  0",
    "0111111111  $+=-_;:*     0",
    "0   11  11  &yzYZ!@#     0",
    "00000000000000000000000000",
    };

    Map(String F);
    ~Map();

    Sprite& get_sprite();
    void draw_map(Sprite& s_map, RenderWindow& window);

};





#endif //!__MAP__H__
