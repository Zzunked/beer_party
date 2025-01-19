#include "scene_handler_main_menu.hpp"
#include "math.hpp"


SceneHandlerMainMenu::SceneHandlerMainMenu(RenderWindow* p_window, SDL_Event* p_event, bool* p_running, Scene* p_current_scene)
    :window(p_window), event(p_event), running(p_running), current_scene(p_current_scene) 
{
    is_scene_loaded = false;
    SDL_Texture* play_btn_texture = nullptr;
    SDL_Texture* main_menu_bg_texture = nullptr;
}


SceneHandlerMainMenu::~SceneHandlerMainMenu() {}


void SceneHandlerMainMenu::load_scene()
{
    if (!is_scene_loaded)
    {
        SDL_Texture* play_btn_texture = window->load_texture("data/assets/play_btn.png");
        SDL_Texture* main_menu_bg_texture = window->load_texture("data/assets/main_menu_bg.png");
        main_menu_bg.set_texture(main_menu_bg_texture);
        play_btn.set_texture(play_btn_texture);
        play_btn.set_position(Vector2f(600, 360));
        play_btn.set_size(PLAY_BTN_W, PLAY_BTN_H);
        is_scene_loaded = true;
        std::cout << "Main menu sceen is loaded!\n";
    }
}


void SceneHandlerMainMenu::handle_events()
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
                    Vector2f btn_pos = play_btn.get_position();
                    if ((click_pos.x >= btn_pos.x) && (click_pos.x <= (btn_pos.x + PLAY_BTN_W)))
                        if ((click_pos.y >= btn_pos.y) && (click_pos.y <= (btn_pos.y + PLAY_BTN_H)))
                        {
                            *current_scene = beer_party_scene_1;
                            play_btn.play_click_sound(); 
                        }
                }
            default:
                break;
        }
    }
}


void SceneHandlerMainMenu::render_scene()
{
    window->clear();
    window->render(main_menu_bg);
    window->render(play_btn);
}

