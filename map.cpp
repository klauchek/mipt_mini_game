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

                ///path and ground
            case '0':s_map.setTextureRect(IntRect(102, 0, 50, 50)); break; //wall
            case ' ':s_map.setTextureRect(IntRect(0, 0, 50, 50)); break; //ground
            case '1':s_map.setTextureRect(IntRect(52, 0, 50, 50)); break; //path
            /// first exam-ticket 
            /// 
            case 'a':s_map.setTextureRect(IntRect(0, 50, 50, 50)); break;
            case 'b':s_map.setTextureRect(IntRect(50, 50, 50, 50)); break;
            case 'c':s_map.setTextureRect(IntRect(100, 50, 50, 50)); break;
            case 'd':s_map.setTextureRect(IntRect(150, 50, 50, 50)); break;
            case 'e':s_map.setTextureRect(IntRect(200, 50, 50, 50)); break;
            case 'f':s_map.setTextureRect(IntRect(250, 50, 50, 50)); break;
            case 'g':s_map.setTextureRect(IntRect(300, 50, 50, 50)); break;
            case 'h':s_map.setTextureRect(IntRect(350, 50, 50, 50)); break;
                //-----------------------------
            case 'A':s_map.setTextureRect(IntRect(0, 100, 50, 50)); break;
            case 'B':s_map.setTextureRect(IntRect(50, 100, 50, 50)); break;
            case 'C':s_map.setTextureRect(IntRect(100, 100, 50, 50)); break;
            case 'D':s_map.setTextureRect(IntRect(150, 100, 50, 50)); break;
            case 'E':s_map.setTextureRect(IntRect(200, 100, 50, 50)); break;
            case 'F':s_map.setTextureRect(IntRect(250, 100, 50, 50)); break;
            case 'G':s_map.setTextureRect(IntRect(300, 100, 50, 50)); break;
            case 'H':s_map.setTextureRect(IntRect(350, 100, 50, 50)); break;
                //-----------------------------
            case 'i':s_map.setTextureRect(IntRect(0, 150, 50, 50)); break;
            case 'j':s_map.setTextureRect(IntRect(50, 150, 50, 50)); break;
            case 'k':s_map.setTextureRect(IntRect(100, 150, 50, 50)); break;
            case 'l':s_map.setTextureRect(IntRect(150, 150, 50, 50)); break;
            case 'm':s_map.setTextureRect(IntRect(200, 150, 50, 50)); break;
            case 'n':s_map.setTextureRect(IntRect(250, 150, 50, 50)); break;
            case 'o':s_map.setTextureRect(IntRect(300, 150, 50, 50)); break;
            case 'p':s_map.setTextureRect(IntRect(350, 150, 50, 50)); break;
                //-----------------------------
            case 'I':s_map.setTextureRect(IntRect(0, 200, 50, 50)); break;
            case 'J':s_map.setTextureRect(IntRect(50, 200, 50, 50)); break;
            case 'K':s_map.setTextureRect(IntRect(100, 200, 50, 50)); break;
            case 'L':s_map.setTextureRect(IntRect(150, 200, 50, 50)); break;
            case 'M':s_map.setTextureRect(IntRect(200, 200, 50, 50)); break;
            case 'N':s_map.setTextureRect(IntRect(250, 200, 50, 50)); break;
            case 'O':s_map.setTextureRect(IntRect(300, 200, 50, 50)); break;
            case 'P':s_map.setTextureRect(IntRect(350, 200, 50, 50)); break;
                //-------------------------------------
            case '{':s_map.setTextureRect(IntRect(0, 250, 50, 50)); break;
            case '}':s_map.setTextureRect(IntRect(50, 250, 50, 50)); break;
            case '[':s_map.setTextureRect(IntRect(100, 250, 50, 50)); break;
            case ']':s_map.setTextureRect(IntRect(150, 250, 50, 50)); break;
            case '(':s_map.setTextureRect(IntRect(200, 250, 50, 50)); break;
            case ')':s_map.setTextureRect(IntRect(250, 250, 50, 50)); break;
            case '2':s_map.setTextureRect(IntRect(300, 250, 50, 50)); break;
            case '3':s_map.setTextureRect(IntRect(350, 250, 50, 50)); break;
                //------------first ticket finished


                //------------second exam ticket
            case 'q':s_map.setTextureRect(IntRect(400, 50, 50, 50)); break;
            case 'r':s_map.setTextureRect(IntRect(450, 50, 50, 50)); break;
            case 's':s_map.setTextureRect(IntRect(500, 50, 50, 50)); break;
            case 't':s_map.setTextureRect(IntRect(550, 50, 50, 50)); break;
            case 'u':s_map.setTextureRect(IntRect(600, 50, 50, 50)); break;
            case 'v':s_map.setTextureRect(IntRect(650, 50, 50, 50)); break;
            case 'w':s_map.setTextureRect(IntRect(700, 50, 50, 50)); break;
            case 'x':s_map.setTextureRect(IntRect(750, 50, 50, 50)); break;
                //---------------------------------
            case 'Q':s_map.setTextureRect(IntRect(400, 100, 50, 50)); break;
            case 'R':s_map.setTextureRect(IntRect(450, 100, 50, 50)); break;
            case 'S':s_map.setTextureRect(IntRect(500, 100, 50, 50)); break;
            case 'T':s_map.setTextureRect(IntRect(550, 100, 50, 50)); break;
            case 'U':s_map.setTextureRect(IntRect(600, 100, 50, 50)); break;
            case 'V':s_map.setTextureRect(IntRect(650, 100, 50, 50)); break;
            case 'W':s_map.setTextureRect(IntRect(700, 100, 50, 50)); break;
            case 'X':s_map.setTextureRect(IntRect(750, 100, 50, 50)); break;
                //----------------------------------
            case '4':s_map.setTextureRect(IntRect(400, 150, 50, 50)); break;
            case '5':s_map.setTextureRect(IntRect(450, 150, 50, 50)); break;
            case '6':s_map.setTextureRect(IntRect(500, 150, 50, 50)); break;
            case '7':s_map.setTextureRect(IntRect(550, 150, 50, 50)); break;
            case '8':s_map.setTextureRect(IntRect(600, 150, 50, 50)); break;
            case '9':s_map.setTextureRect(IntRect(650, 150, 50, 50)); break;
            case '?':s_map.setTextureRect(IntRect(700, 150, 50, 50)); break;
            case '%':s_map.setTextureRect(IntRect(750, 150, 50, 50)); break;
                //-----------------------------------
            case '$':s_map.setTextureRect(IntRect(400, 200, 50, 50)); break;
            case '+':s_map.setTextureRect(IntRect(450, 200, 50, 50)); break;
            case '=':s_map.setTextureRect(IntRect(500, 200, 50, 50)); break;
            case '-':s_map.setTextureRect(IntRect(550, 200, 50, 50)); break;
            case '_':s_map.setTextureRect(IntRect(600, 200, 50, 50)); break;
            case ';':s_map.setTextureRect(IntRect(650, 200, 50, 50)); break;
            case ':':s_map.setTextureRect(IntRect(700, 200, 50, 50)); break;
            case '*':s_map.setTextureRect(IntRect(750, 200, 50, 50)); break;
                //---------------------------------
            case '&':s_map.setTextureRect(IntRect(400, 250, 50, 50)); break;
            case 'y':s_map.setTextureRect(IntRect(450, 250, 50, 50)); break;
            case 'z':s_map.setTextureRect(IntRect(500, 250, 50, 50)); break;
            case 'Y':s_map.setTextureRect(IntRect(550, 250, 50, 50)); break;
            case 'Z':s_map.setTextureRect(IntRect(600, 250, 50, 50)); break;
            case '!':s_map.setTextureRect(IntRect(650, 250, 50, 50)); break;
            case '@':s_map.setTextureRect(IntRect(700, 250, 50, 50)); break;
            case '#':s_map.setTextureRect(IntRect(750, 250, 50, 50)); break;
                //----------second ticket finished
            }
                s_map.setPosition((float)j * 50, (float)i * 50);
                window.draw(s_map);
            }
        }
    }
