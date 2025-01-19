#include <vector>
#include <random>

#include "scene_handler_party_1.hpp"
#include "render_window.hpp"
#include "background.hpp"
#include "beer.hpp"
#include "constants.hpp"



SceneHandlerPartyOne::SceneHandlerPartyOne(RenderWindow* p_window, SDL_Event* p_event, bool* p_running, Scene* p_current_scene)
    :window(p_window), event(p_event), running(p_running), current_scene(p_current_scene)
{
    is_scene_loaded = false;
    SDL_Texture* beer_texture = nullptr;
    SDL_Texture* beer_party_bg_texture = nullptr;
    my_beers.reserve(9);
}


SceneHandlerPartyOne::~SceneHandlerPartyOne() {}


void SceneHandlerPartyOne::load_scene()
{
    if (!is_scene_loaded)
    {
        SDL_Texture* beer_party_bg_texture = window->load_texture("data/assets/beer_party_bg.png");
        beer_party_bg.set_texture(beer_party_bg_texture);
        add_beers();
        is_scene_loaded = true;
    }
}


void SceneHandlerPartyOne::handle_events()
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

                    for (Beer &beer: my_beers)
                    {
                        Vector2f beer_pos = beer.get_position();

                        if ((click_pos.x >= beer_pos.x) && (click_pos.x <= (beer_pos.x + 128)))
                        {
                            if ((click_pos.y >= beer_pos.y) && (click_pos.y <= (beer_pos.y + 128)))
                            {
                                beer.play_broken_glass_sound();
                                beer.move_to_bottom();
                                break;
                            }
                        }
                    }
                    break;
                }

            default:
                break;
        }
    }

    move_beers();
}


void SceneHandlerPartyOne::render_scene()
{
    window->clear();

    window->render(beer_party_bg);
    
    for (Beer &beer : my_beers)
    {
        beer.get_info();
        float beer_y = beer.get_position().y;

        if (beer_y == beer.get_min_point())
        {
            beer.play_hit_sound();

        } else if (beer_y <= (beer.get_max_point()))
        {
            beer.play_hey_sound();
        }
        window->render(beer);
    }
}


void SceneHandlerPartyOne::add_beers()
{
    SDL_Texture* beer_texture = window->load_texture("data/assets/beer.png");
    int beer_x_position = 24;
    int beer_y_position = 590;
    int beer_step = 136;
    for (int i = 0; i < 9; i++)
    {
        std::cout << beer_texture << "\n";
        my_beers.push_back(Beer(Vector2f(beer_x_position, beer_y_position), beer_texture, i));
        beer_x_position += beer_step;
    };
}


void SceneHandlerPartyOne::move_beers()
{
    for (Beer &beer : my_beers)
    {
        Vector2f current_beer_pos = beer.get_position();

        if (current_beer_pos.y >= beer.get_min_point())
        {
            int dest = calculate_random_dest(beer.get_max_point(), beer.get_min_point());
            beer.set_dest(dest);
            beer.change_direction();
        } else if (current_beer_pos.y <= beer.get_dest())
        {
            beer.change_direction();
        }
        beer.move_by_y();
    }
}


int calculate_random_dest(int start_point, int max_point)
{

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start_point, max_point);
    int dest = dist6(rng);

    return dest;
}

