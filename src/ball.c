#include "raylib.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define GRAVITY 9.8f
#define WIND 1.2f

int IsQuitWindow(void)
{
    if (IsKeyDown(KEY_LEFT_CONTROL))
    {
        if (IsKeyDown(KEY_C))
        {
            return 1;
        }
    }
    if (IsKeyDown(KEY_LEFT_SUPER))
    {
        if (IsKeyDown(KEY_W))
        {
            return 1;
        }
    }
    return 0;
}

typedef struct Ball
{
    Vector2 pos;
    Vector2 vel;
    Color color;
    float radius;
} Ball;

Ball *InitBall(float radius, Color color)
{
    Ball *ball = malloc(sizeof(Ball));
    ball->pos.x = WINDOW_WIDTH / 2.0f;
    ball->pos.y = WINDOW_HEIGHT / 2.0f;
    ball->radius = radius;
    ball->color = color;
    ball->vel.x = 1;
    ball->vel.y = 1;
    return ball;
}

void Draw(Ball *ball)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(ball->pos.x, ball->pos.y, ball->radius, ball->color);
    EndDrawing();
}

void CheckBorderCollision(Ball *ball)
{
    if (ball->radius + ball->pos.y >= WINDOW_HEIGHT)
    {
        ball->vel.y = -1;
    }
    if (ball->pos.y - ball->radius <= 0)
    {
        ball->vel.y = 1;
    }
    if (ball->radius + ball->pos.x >= WINDOW_WIDTH)
    {
        ball->vel.x = -1;
    }
    if (ball->pos.x - ball->radius <= 0)
    {
        ball->vel.x = 1;
    }
}

void Update(Ball *ball)
{
    CheckBorderCollision(ball);
    ball->pos.y += GRAVITY * ball->vel.y;
    ball->pos.x += WIND * ball->vel.x;
}

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bouncing Ball");
    SetTargetFPS(60);
    Ball *ball = InitBall(40.0f, RAYWHITE);

    while (!WindowShouldClose())
    {
        if (IsQuitWindow())
            break;
        Draw(ball);
        Update(ball);
    }

    CloseWindow();

    return 0;
}
