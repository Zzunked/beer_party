cmake_minimum_required(VERSION 3.28.3)

project(simple_game_sdl2)
set(CMAKE_CXX_STANDARD 20)

add_executable(
    game 
    src/main.cpp 
    src/render_window.cpp 
    src/utils.cpp 
    src/entity.cpp
    src/math.cpp
    src/beer.cpp
    src/background.cpp
    src/scenes/beer_party_1.cpp
    src/scenes/main_menu.cpp
    src/button.cpp
    src/music_player.cpp
)

# Variables storing SDL framework locations
set(SDL2       /Library/Frameworks/SDL2.framework)
set(SDL2_image /Library/Frameworks/SDL2_image.framework)
set(SDL2_ttf   /Library/Frameworks/SDL2_ttf.framework)
set(SDL2_mixer   /Library/Frameworks/SDL2_mixer.framework)

target_link_libraries(
    game PRIVATE
    ${SDL2}/Versions/A/SDL2
    ${SDL2_image}/Versions/A/SDL2_image
    ${SDL2_ttf}/Versions/A/SDL2_ttf
    ${SDL2_mixer}/Versions/A/SDL2_mixer
)


target_include_directories(
    game PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/scenes
    ${SDL2}/Versions/A/Headers
    ${SDL2_image}/Versions/A/Headers
    ${SDL2_ttf}/Versions/A/Headers
    ${SDL2_mixer}/Versions/A/Headers
)
