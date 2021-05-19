#include "Game_Menu.h"
#include "Player.h"
#include "Fucker.h"
#include "map.h"
#include <iostream>
using namespace sf;


//------------------buttons creating functions ------//OK

void Game_Menu::create_game_menu_background(const string& game_menu_background_)
{
    game_menu_background.loadFromFile(game_menu_background_);
    game_menu_background_texture.loadFromImage(game_menu_background);
    game_menu_background_sprite.setTexture(game_menu_background_texture);
    game_menu_background_sprite.setPosition(MENU_POS_X, MENU_POS_Y);
}

void Game_Menu::create_math_department_button(const string& math_department_button_)
{
    math_department_button.loadFromFile(math_department_button_);
    math_department_button_texture.loadFromImage(math_department_button);
    math_department_button_sprite.setTexture(math_department_button_texture);
    math_department_button_sprite.setPosition(MATH_BUTTON_POS_X, MATH_BUTTON_POS_Y);
}

void Game_Menu::create_physics_department_button(const string& physics_department_button_)
{
    physics_department_button.loadFromFile(physics_department_button_);
    physics_department_button_texture.loadFromImage(physics_department_button);
    physics_department_button_sprite.setTexture(physics_department_button_texture);
    physics_department_button_sprite.setPosition(PHYS_BUTTON_POS_X, PHYS_BUTTON_POS_Y);
}

void Game_Menu::create_game_exit_button(const string& game_exit_button_)
{
    game_exit_button.loadFromFile(game_exit_button_);
    game_exit_button_texture.loadFromImage(game_exit_button);
    game_exit_button_sprite.setTexture(game_exit_button_texture);
    game_exit_button_sprite.setPosition(EXIT_BUTTON_POS_X, EXIT_BUTTON_POS_Y);
}





//----------running levels 
void Game_Menu::run_math(RenderWindow& window)
{
    Map map("math_map.png");

    //String F, float X, float Y, float A, float B, float W, float H)
    Player student("student.png", 100, 100, 100, 0, 41, 57);
    Fucker Podlipskiy("Podlipskiy.jpg", 200, 200, 0, 0, 55, 55);
    Fucker Umnov_Jr("Umnov_Jr.jpg", 300, 300, 0, 0, 55, 55);

    float CurrentFrame = 0;
    Clock clock;

    long long int counter = 1000;

    //int mode = PATH;

    Podlipskiy.set_direction(DOWN);
    Umnov_Jr.set_direction(UP);

    while (window.isOpen())
    {
        counter++;
        std:: cout << counter << std::endl;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

 //------------------------------------------pseudo-random direction

        int a = 1429, b = 1811, c = 1747, d = 1578;
            if (counter % a == 0)
            {
                Podlipskiy.set_direction(counter % 5);
                Umnov_Jr.set_direction((counter + 1) % 5);
            }
            else if (counter % b == 0)
            {
                Podlipskiy.set_direction(counter % 5);
                Umnov_Jr.set_direction((counter + 1) % 5);
            }
            else if (counter % c == 0)
            {
                Podlipskiy.set_direction(counter % 5);
                Umnov_Jr.set_direction((counter + 1) % 5);
            }
            else if (counter % d == 0)
            {
                Podlipskiy.set_direction(counter % 5);
                Umnov_Jr.set_direction((counter + 1) % 5);
            }

            if (counter >= 9000)
            {
                counter = 1000;
                a += 5;
                b += 5;
                c += 5;
                d += 5;
            }
 
//------------------------------------------------------------------------
  
        student.control(time, CurrentFrame, map);
        Podlipskiy.control(time, map);
        Umnov_Jr.control(time, map);



        window.clear();
        


        map.draw_map(map.get_sprite(), window);
        window.draw(student.get_sprite());
        window.draw(Podlipskiy.get_sprite());
        window.draw(Umnov_Jr.get_sprite());


        window.display();

    }
}


void Game_Menu::run_phys(RenderWindow& window)
{
    Map map("phys_map.png");

    //String F, float X, float Y, float A, float B, float W, float H)
    Player student("student.png", 100, 100, 100, 0, 41, 57);
    Fucker Bulygin("Bulygin.jpg", 200, 200, 0, 0, 55, 55);
    Fucker Kuznetsov("Kuznetsov.jpg", 300, 300, 0, 0, 55, 55);

    float CurrentFrame = 0;
    Clock clock;

    int counter = 0;
    Bulygin.set_direction(LEFT);
    Kuznetsov.set_direction(UP);



    while (window.isOpen())
    {
        ++counter;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

  
        //------------------------------------------pseudo-random direction
        if (counter % 449 == 0)
        {
            Bulygin.set_direction((DOWN + 1) % 5);
            Kuznetsov.set_direction((UP + 1) % 5);
        }
        else if (counter % 727 == 0)
        {
            Bulygin.set_direction((DOWN + 2) % 5);
            Kuznetsov.set_direction((UP + 2) % 5);
        }
        else if (counter % 1077 == 0)
        {
            Bulygin.set_direction((DOWN + 3) % 5);
            Kuznetsov.set_direction((UP + 3) % 5);
        }
        else if (counter % 1586 == 0)
        {
            Bulygin.set_direction((DOWN + 4) % 5);
            Kuznetsov.set_direction((UP + 4) % 5);
        }

        //------------------------------------------------------------------------
 
        student.control(time, CurrentFrame, map);
        Bulygin.control(time, map);
        Kuznetsov.control(time, map);



        window.clear();



        map.draw_map(map.get_sprite(), window);
        window.draw(student.get_sprite());
        window.draw(Bulygin.get_sprite());
        window.draw(Kuznetsov.get_sprite());


        window.display();

    }
}

//---------processing bottons (грубо говоря: что делает каждая кнопка при нажатии)


//OK
void Game_Menu:: game_welcome_page(const string& game_menu_background_,
    const string& game_exit_button_,
    const string& math_department_button_,
    const string& physics_department_button_)//создание всего, рисование всего
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "EXAM SIMULATOR");
    create_game_menu_background(game_menu_background_);
    create_math_department_button(math_department_button_);
    create_physics_department_button(physics_department_button_);
    create_game_exit_button(game_exit_button_);

    window.clear();

    window.draw(game_menu_background_sprite);
    window.draw(math_department_button_sprite);
    window.draw(physics_department_button_sprite);
    window.draw(game_exit_button_sprite);

    window.display();
    processing_menu(window);
}


void Game_Menu::math_department_button_pressed(RenderWindow& window)
{
    RenderWindow new_window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MATH");
    window.close();
    run_math(new_window);

    return;
}
void Game_Menu::physics_department_button_pressed(RenderWindow& window)
{
    RenderWindow new_window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PHYSICS");
    window.close();
    run_phys(new_window);

    return;
}


//OK
void Game_Menu::game_exit_button_pressed(RenderWindow& window)//почему статик
{
    window.close();
}


//OK
void Game_Menu::processing_menu(RenderWindow& window) //само меню со всеми кликабельными кнопочками
{
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                game_exit_button_pressed(window);


            if (IntRect(EXIT_BUTTON_POS_X, EXIT_BUTTON_POS_Y,
                EXIT_BUTTON_WIDTH, EXIT_BUTTON_HEIGHT).contains(Mouse::getPosition(window)))
                menuNum = EXIT;

            if (IntRect(MATH_BUTTON_POS_X, MATH_BUTTON_POS_Y,
                MATH_BUTTON_WIDTH, MATH_BUTTON_HEIGHT).contains(Mouse::getPosition(window)))
                menuNum = MATH;

            if (IntRect(PHYS_BUTTON_POS_X, PHYS_BUTTON_POS_Y,
                PHYS_BUTTON_WIDTH, PHYS_BUTTON_HEIGHT).contains(Mouse::getPosition(window)))
                menuNum = PHYS;

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == EXIT)
                    game_exit_button_pressed(window);
                else if (menuNum == MATH)
                    math_department_button_pressed(window);
                else if (menuNum == PHYS)
                    physics_department_button_pressed(window);
            }
        }
    }
}


