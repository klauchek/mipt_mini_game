#include "Character.h"
#include "Player.h"
#include "Fucker.h"
#include "Game_Menu.h"




int main()
{


    Game_Menu g;
    RenderWindow window(VideoMode(1200, 675), "MIPT Mini-game");
    g.game_welcome_page("game_images/game_menu_background.jpg", "game_images/game_exit_button.jpg", "game_images/math_department_button.png", "game_images/physics_department_button.png");

    return 0;
}