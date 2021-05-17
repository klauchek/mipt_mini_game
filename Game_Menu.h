#ifndef __GAME__MENU__
#define __GAME__MENU__

#include <SFML/Graphics.hpp>
#include <string>

using std::string;
using namespace sf;

class Game_Menu
{
private:

    enum Buttons
    {
        EXIT = 1,
        MATH = 2,
        PHYS = 3,

        MENU_POS_X = 0,
        MENU_POS_Y = 0,

        MATH_BUTTON_POS_X = 160,
        MATH_BUTTON_POS_Y = 220,
        MATH_BUTTON_WIDTH = 304,
        MATH_BUTTON_HEIGHT = 166,

        PHYS_BUTTON_POS_X = 790,
        PHYS_BUTTON_POS_Y = 220,
        PHYS_BUTTON_WIDTH = 294,
        PHYS_BUTTON_HEIGHT = 168,

        EXIT_BUTTON_POS_X = 1100,
        EXIT_BUTTON_POS_Y = 575,
        EXIT_BUTTON_WIDTH = 100,
        EXIT_BUTTON_HEIGHT = 100,

        WINDOW_WIDTH = 1200,
        WINDOW_HEIGHT = 675
    };

    //const static bool NO = false;
    //const static bool YES = true;

protected:
    Image game_menu_background;
    Texture game_menu_background_texture;
    Sprite game_menu_background_sprite;

    Image math_department_button;
    Texture math_department_button_texture;
    Sprite math_department_button_sprite;

    Image physics_department_button;
    Texture physics_department_button_texture;
    Sprite physics_department_button_sprite;

    Image game_exit_button;
    Texture game_exit_button_texture;
    Sprite game_exit_button_sprite;
    int menuNum = 0;
public:


    //---------------------------------------creating sprites for menu:
    void create_game_menu_background(const string& game_menu_background_);
    void create_math_department_button(const string& math_department_button_);
    void create_physics_department_button(const string& physics_department_button_);
    void create_game_exit_button(const string& game_exit_button_);

    //-----------------------------running levels
    void run_math(RenderWindow& window);
    void run_phys(RenderWindow& window);

    //------------------------------------------------processing bottons:

    void game_welcome_page(const string& game_menu_background_,
        const string& game_exit_button_,
        const string& math_department_button_,
        const string& physics_department_button_);

    void math_department_button_pressed(RenderWindow& window);
    void physics_department_button_pressed(RenderWindow& window);
    void game_exit_button_pressed(RenderWindow& window);
    void processing_menu(RenderWindow& window);
    //------------------------------------------------------------------
};



#endif __GAME__MENU__
