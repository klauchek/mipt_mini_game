#ifndef __MAP__H__
#define __MAP__H__

#include "SFML/Graphics.hpp"
#include <locale>
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
    "0                        0",
    "0 abcdefg       11111    0",
    "0 ABCDEFGH      1        0",
    "0 ijklmnop      1        0",
    "0 IJKLMNOP      1        0",
    "0 {}[]()23     11        0",
    "0   1111111111111        0",
    "0   1       qrstuvwx     0",
    "0   1       QRSTUVWX     0",
    "0   1       456789?%     0",
    "0   1       $+=-_;:*     0",
    "0           &yzYZ!@#     0",
    "00000000000000000000000000",
    };

    Map(String F);
    ~Map();

    Sprite& get_sprite();
    void draw_map(Sprite& s_map, RenderWindow& window);

};





#endif //!__MAP__H__
