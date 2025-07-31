#include "raylib.h"
#include <stdio.h>

int IsQuitWindow(void)
{
    if (IsKeyDown(KEY_LEFT_SUPER))
    {
        if (IsKeyDown(KEY_W))
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        if (IsQuitWindow())
            break;
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
