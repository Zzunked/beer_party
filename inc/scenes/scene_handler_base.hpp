#pragma once

class SceneHandlerBase
{
    public:
        virtual void load_scene() = 0;
        virtual void handle_events() = 0;
        virtual void render_scene() = 0;
        virtual ~SceneHandlerBase() {};
};

