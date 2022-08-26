#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include "include/raylib.h"

#define u32 uint32_t

bool ball1_state, ball2_state;
const u32 sw = 480;
const u32 sh = 270;
Vector2 ball1_position = {(float)sw / 3, (float)sh / 3};
Vector2 ball2_position = {(float)sw / 3 * 2, (float)sh / 3 * 2};
double speed1 = 2, speed2 = 2;

void movef1(double x, double y){
    double value = sqrt((x*x)+(y*y));
    if(value == 0)
        return;
    ball1_position.x += (x / value) * speed1;
    ball1_position.y += (y / value) * speed1;
}
void movef2(double x, double y){
    double value = sqrt((x*x)+(y*y));
    if(value == 0)
        return;
    ball2_position.x += (x / value) * speed2;
    ball2_position.y += (y / value) * speed2;
}

int main(void){
    double x1, y1, x2, y2;

    InitWindow(sw, sh, "hello,world.");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        ball1_state = true;
        ball2_state = true;

        if (IsKeyDown(KEY_D) && ball1_position.x + 30 < sw)
        { x1 = 1.0f;}
        if (IsKeyDown(KEY_A) && ball1_position.x - 30 > 0)
        { x1= -1.0f;}
        if (IsKeyDown(KEY_W) && ball1_position.y - 30 > 0)
        { y1 = -1.0f;}
        if (IsKeyDown(KEY_S) && ball1_position.y + 30 < sh)
        { y1 = 1.0f;}

        if (IsKeyDown(KEY_KP_6) && ball2_position.x + 30 < sw)
        { x2 = 1.0f;}
        if (IsKeyDown(KEY_KP_4) && ball2_position.x - 30)
        { x2= -1.0f;}
        if (IsKeyDown(KEY_KP_8) && ball2_position.y - 30 > 0)
        { y2 = -1.0f;}
        if (IsKeyDown(KEY_KP_5) && ball2_position.y + 30 < sh)
        { y2 = 1.0f;}

        movef1(x1, y1);
        movef2(x2, y2);

        if (IsKeyDown(KEY_LEFT_SHIFT)) { speed1 = 4.0f;}
        else if(IsKeyDown(KEY_LEFT_CONTROL)) { speed1 = 1.0f;}
        else { speed1 = 2.0f;}

        if (IsKeyDown(KEY_RIGHT_SHIFT)) { speed2 = 4.0f;}
        else if(IsKeyDown(KEY_SLASH)) { speed2 = 1.0f;}
        else { speed2 = 2.0f;}

        BeginDrawing();

        ClearBackground(WHITE);
        DrawCircle(ball1_position.x, ball1_position.y, 30, BLUE);
        DrawCircle(ball2_position.x, ball2_position.y, 30, RED);

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}