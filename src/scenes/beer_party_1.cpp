#include <random>

#include "beer_party_1.hpp"


int calculate_random_dest(int start_point, int max_point)
{

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start_point, max_point);
    int dest = dist6(rng);

    return dest;
}


void move_beers(std::vector<Beer>& beers)
{

    for (Beer &beer : beers)
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


void handle_events_beer_party_1(float* accumulator, const float* time_step, SDL_Event* event,  std::vector<Beer>& beers, bool* running)
        
{
    while (*accumulator >= *time_step) 
    {

        while(SDL_PollEvent(event))
        {

            if (event->type == SDL_QUIT)
            {

                *running = false;

            } else if (event->type == SDL_MOUSEBUTTONDOWN)
            {
                Vector2f click_pos =  Vector2f(event->button.x, event->button.y);

                for (Beer &beer: beers)
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
            }
        }    
        *accumulator -= *time_step;
    }
    move_beers(beers);
}


void render_scene_beer_party_1(RenderWindow* window, Background* background, std::vector<Beer>& beers)
{
    window->clear();

    window->render(*background);
    
    for (Beer &beer : beers)
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

