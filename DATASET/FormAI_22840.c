//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BLOCK_WIDTH = 50;
const int BLOCK_HEIGHT = 20;

// Structs
typedef struct Block {
    SDL_Rect rect;
    int strength;
} Block;

typedef struct Ball {
    SDL_Rect rect;
    int dx;
    int dy;
} Ball;

// Function prototypes
void drawBlocks(Block blocks[]);
void resetBlocks(Block blocks[]);
void handleCollision(Ball *ball, Block blocks[]);
int gameOver();
void resetBall(Ball *ball);
void handleInput(Ball *ball);

int main(int argc, char* argv[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Seed random number generator
    srand(time(NULL));

    // Create blocks
    Block blocks[10];
    resetBlocks(blocks);

    // Create ball
    Ball ball;
    ball.rect.x = SCREEN_WIDTH/2 - BLOCK_WIDTH/2;
    ball.rect.y = SCREEN_HEIGHT - BLOCK_HEIGHT*2;
    ball.rect.w = BLOCK_WIDTH;
    ball.rect.h = BLOCK_HEIGHT;
    ball.dx = rand() % 3 - 1; // Randomly start ball moving left, right, or center
    ball.dy = -2;

    // Game loop
    while (true) {
        // Handle input
        handleInput(&ball);

        // Move ball
        ball.rect.x += ball.dx;
        ball.rect.y += ball.dy;

        // Handle wall collision
        if (ball.rect.x < 0 || ball.rect.x + ball.rect.w > SCREEN_WIDTH) {
            ball.dx *= -1;
        }
        if (ball.rect.y < 0) {
            ball.dy *= -1;
        } else if (gameOver(ball)) {
            resetBall(&ball);
            continue;
        }

        // Handle block collision
        handleCollision(&ball, blocks);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw blocks
        drawBlocks(blocks);

        // Draw ball
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball.rect);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void drawBlocks(Block blocks[]) {
    SDL_Renderer* renderer = SDL_GetRenderer(SDL_GetWindowFromID(1));
    for (int i=0; i<10; i++) {
        if (blocks[i].strength > 0) {
            if (blocks[i].strength == 3) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            } else if (blocks[i].strength == 2) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            }
            SDL_RenderFillRect(renderer, &blocks[i].rect);
        }
    }
}

void resetBlocks(Block blocks[]) {
    for (int i=0; i<10; i++) {
        blocks[i].rect.x = BLOCK_WIDTH*(i%10);
        blocks[i].rect.y = BLOCK_HEIGHT*(i/10+1);
        blocks[i].rect.w = BLOCK_WIDTH;
        blocks[i].rect.h = BLOCK_HEIGHT;
        blocks[i].strength = 3;
    }
}

void handleCollision(Ball *ball, Block blocks[]) {
    for (int i=0; i<10; i++) {
        if (blocks[i].strength > 0) {
            if (ball->rect.x + ball->rect.w >= blocks[i].rect.x && ball->rect.x <= blocks[i].rect.x + blocks[i].rect.w) {
                if (ball->rect.y + ball->rect.h >= blocks[i].rect.y && ball->rect.y <= blocks[i].rect.y + blocks[i].rect.h) {
                    // Ball hit block
                    blocks[i].strength--;
                    if (blocks[i].strength == 0) {
                        ball->dy *= -1; // Bounce ball back up
                    } else {
                        if (ball->dx > 0)
                            ball->dx++;
                        else if (ball->dx < 0)
                            ball->dx--;
                        ball->dy *= -1; // Bounce ball back up
                    }
                }
            }
        }
    }
}

int gameOver(Ball ball) {
    if (ball.rect.y + ball.rect.h > SCREEN_HEIGHT) {
        return 1;
    } else {
        return 0;
    }
}

void resetBall(Ball *ball) {
    ball->rect.x = SCREEN_WIDTH/2 - BLOCK_WIDTH/2;
    ball->rect.y = SCREEN_HEIGHT - BLOCK_HEIGHT*2;
    ball->dx = rand() % 3 - 1; // Randomly start ball moving left, right, or center
    ball->dy = -2;
}

void handleInput(Ball *ball) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                exit(1);
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                        ball->dx--;
                        break;
                    case SDLK_RIGHT:
                        ball->dx++;
                        break;
                }
                break;
        }
    }
}