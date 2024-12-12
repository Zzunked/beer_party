#include "main_menu.hpp"
#include "math.hpp"


void handle_events_main_menu(SDL_Event* event, bool* running, Scene* current_scene, Button* play_btn)
{
    while(SDL_PollEvent(event))
    {
        switch (event->type)
        {
            case SDL_QUIT:
                {
                    *running = false;
                }
            case SDL_MOUSEBUTTONDOWN:
                {
                    Vector2f click_pos =  Vector2f(event->button.x, event->button.y);
                    Vector2f btn_pos = play_btn->get_position();
                    if ((click_pos.x >= btn_pos.x) && (click_pos.x <= (btn_pos.x + PLAY_BTN_W)))
                        if ((click_pos.y >= btn_pos.y) && (click_pos.y <= (btn_pos.y + PLAY_BTN_H)))
                        {
                            *current_scene = beer_party_scene_1;
                            play_btn->play_click_sound(); 
                        }
                }
            default:
                break;
        }
    }
}


void render_scene_main_menu(RenderWindow* window, Background* background, Button* play_btn)
{
    window->clear();
    window->render(*background);
    window->render(*play_btn);
}

