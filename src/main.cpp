#include <raylib.h>
#include <iostream>
#include <sstream>

#include "indexing.h"
/*
 * Old way to compile
 * mkdir build && cd build
 * cmake ..
 * make
 *
 * Modern way
 * cmake -S . -B build
 * cmake --build build
 */

/*
 * Ressourcen:
 * - Bild: https://raw.githubusercontent.com/dominickleppich/FlowerWarsPP/master/specification/images/flowerwarspp-preview.png
 * - Orginalrepo: https://github.com/lquenti/flowerwarspp
 * - Lars impl: https://github.com/lquenti/eanufwpp
 * - Musterlösung: https://github.com/dominickleppich/FlowerWarsPP
 */

const int WIDTH = 1280;
const int HEIGHT = 720;
const char TITLE[] = "Flowerwars, now faster! (Hopefully)";

void draw_triangles(size_t N) {
    // compute min of height and width
    int current_width = GetRenderWidth();
    int current_height = GetRenderHeight();
    int min_xy = std::min(current_width, current_height);


    int width_of_single = min_xy/N; // width == height btw
    float left_push = current_width/2 - width_of_single*N/2;
    float top_push = current_height/2 - width_of_single*N/2;
    //width / 2 == xmargin +  width_of_single*N/2
    // draw corners from bottom to top
    for (size_t x=0; x<N+1; x++)
    {
        for (size_t y=0; y<N-x+1; y++)
        {
            float pos_x = left_push+y*width_of_single/2.0f+x*width_of_single;
            float pos_y = top_push+(N-y)*width_of_single;
            Vector2 center = {pos_x, pos_y};
            DrawCircleV(center, 10, RED);
            std::stringstream ss;
            ss << x << "," << y;
            DrawText(ss.str().c_str(),  pos_x, pos_y, 20, BLACK);
        }
    }
}

#include <iostream>
#include <stdint.h>


int main()
{
 
    // https://www.raylib.com/examples/core/loader.html?name=core_window_flags
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_triangles(6);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}