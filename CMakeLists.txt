cmake_minimum_required(VERSION 3.28.3)

project(simple_game_sdl2)
set(CMAKE_CXX_STANDARD 20)

add_executable(game src/main.cpp src/render_window.cpp)

# Variables storing SDL framework locations
set(SDL2       /Library/Frameworks/SDL2.framework)
set(SDL2_image /Library/Frameworks/SDL2_image.framework)
set(SDL2_ttf   /Library/Frameworks/SDL2_ttf.framework)

target_link_libraries(
    game PRIVATE
    ${SDL2}/Versions/A/SDL2
    ${SDL2_image}/Versions/A/SDL2_image
    ${SDL2_ttf}/Versions/A/SDL2_ttf
)


target_include_directories(
    game PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2}/Versions/A/Headers
    ${SDL2_image}/Versions/A/Headers
    ${SDL2_ttf}/Versions/A/Headers
)