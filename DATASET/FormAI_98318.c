//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Breakout Game Clone",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Set up the ball
    SDL_Rect ball = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 10, 10};
    int dx = 2, dy = 2;

    // Set up the paddle
    SDL_Rect paddle = {SCREEN_WIDTH/2-25, SCREEN_HEIGHT-20, 50, 10};

    // Set up the blocks
    const int NUM_BLOCKS = 32;
    SDL_Rect blocks[NUM_BLOCKS];
    int block_width = SCREEN_WIDTH/8;
    int block_height = SCREEN_HEIGHT/16;
    int x = 0, y = 0;
    for(int i=0; i<NUM_BLOCKS; i++) {
        blocks[i].x = x+5;
        blocks[i].y = y+30;
        blocks[i].w = block_width-10;
        blocks[i].h = block_height-10;
        x += block_width;
        if(x >= SCREEN_WIDTH) {
            x = 0;
            y += block_height;
        }
    }

    // Start the game loop
    int quit = 0;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = 1;
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        paddle.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        paddle.x += 5;
                        break;
                }
            }
        }

        // Update the ball position
        ball.x += dx;
        ball.y += dy;

        // Check for collisions with walls
        if (ball.x+ball.w >= SCREEN_WIDTH || ball.x <= 0)
            dx = -dx;
        if (ball.y <= 0)
            dy = -dy;
        if (ball.y+ball.h >= SCREEN_HEIGHT) {
            printf("Game over!\n");
            quit = 1;
        }

        // Check for collisions with paddle
        if (ball.y+ball.h >= paddle.y && ball.x+ball.w >= paddle.x && ball.x <= paddle.x+paddle.w)
            dy = -dy;

        // Check for collisions with blocks
        for(int i=0; i<NUM_BLOCKS; i++) {
            if (blocks[i].x > -block_width && ball.y <= blocks[i].y+blocks[i].h && ball.x+ball.w >= blocks[i].x && ball.x <= blocks[i].x+blocks[i].w) {
                dy = -dy;
                blocks[i].x = -block_width;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the ball
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball);

        // Draw the paddle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &paddle);

        // Draw the blocks
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for(int i=0; i<NUM_BLOCKS; i++) {
            if (blocks[i].x > -block_width)
                SDL_RenderFillRect(renderer, &blocks[i]);
        }

        // Update the screen
        SDL_RenderPresent(renderer);

        // Wait for a moment
        SDL_Delay(10);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}