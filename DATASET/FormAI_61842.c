//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

// Constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BALL_SIZE 10
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 50

// Game objects
struct ball {
    SDL_Rect rect;
    int vx, vy;
};

struct paddle {
    SDL_Rect rect;
};

// Function prototypes
void handle_input(struct paddle* paddle);
void move_ball(struct ball* ball);
void move_ai_paddle(struct paddle* paddle, struct ball* ball);
void render_game(SDL_Renderer* renderer, struct ball* ball, struct paddle* player, struct paddle* ai);

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    struct ball ball = {{SCREEN_WIDTH/2-BALL_SIZE/2,SCREEN_HEIGHT/2-BALL_SIZE/2,BALL_SIZE,BALL_SIZE}, 3, 3};
    struct paddle player = {{10,SCREEN_HEIGHT/2-PADDLE_HEIGHT/2,PADDLE_WIDTH,PADDLE_HEIGHT}};
    struct paddle ai = {{SCREEN_WIDTH-10-PADDLE_WIDTH,SCREEN_HEIGHT/2-PADDLE_HEIGHT/2,PADDLE_WIDTH,PADDLE_HEIGHT}};

    bool is_running = true;

    while (is_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }

        handle_input(&player);
        move_ball(&ball);
        move_ai_paddle(&ai, &ball);
        render_game(renderer, &ball, &player, &ai);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void handle_input(struct paddle* paddle) {
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);

    if (keyboard_state[SDL_SCANCODE_UP]) {
        paddle->rect.y -= 5;
    }
    if (keyboard_state[SDL_SCANCODE_DOWN]) {
        paddle->rect.y += 5;
    }
}

void move_ball(struct ball* ball) {
    ball->rect.x += ball->vx;
    ball->rect.y += ball->vy;

    // Check for collisions with walls
    if (ball->rect.x < 0 || ball->rect.x > SCREEN_WIDTH-BALL_SIZE) {
        ball->vx = -ball->vx;
    }
    if (ball->rect.y < 0 || ball->rect.y > SCREEN_HEIGHT-BALL_SIZE) {
        ball->vy = -ball->vy;
    }
}

void move_ai_paddle(struct paddle* paddle, struct ball* ball) {
    int ball_center = ball->rect.y + BALL_SIZE/2;
    int paddle_center = paddle->rect.y + PADDLE_HEIGHT/2;

    if (ball_center < paddle_center) {
        paddle->rect.y -= 3;
    }
    else if (ball_center > paddle_center) {
        paddle->rect.y += 3;
    }
}

void render_game(SDL_Renderer* renderer, struct ball* ball, struct paddle* player, struct paddle* ai) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render the ball and paddles
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball->rect);
    SDL_RenderFillRect(renderer, &player->rect);
    SDL_RenderFillRect(renderer, &ai->rect);

    // Present the renderer
    SDL_RenderPresent(renderer);
}