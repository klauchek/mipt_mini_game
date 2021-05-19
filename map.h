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
    "0                        0",
    "0                        0",
    "0    112222222222222222  0",
    "0       222222222222     0",
    "0                        0",
    "0             111111111  0",
    "0 1111111111111111       0",
    "0      11111111111       0",
    "0      2222222222        0",
    "0      2222222222        0",
    "0                        0",
    "0                        0",
    "00000000000000000000000000",
    };

    Map(String F);
    ~Map();

    Sprite& get_sprite();
    void draw_map(Sprite& s_map, RenderWindow& window);

};





#endif //!__MAP__H__
