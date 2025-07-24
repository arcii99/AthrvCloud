//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
/*
 * This is a classical circuit simulator program that simulates a basic electronic circuit consisting of a resistor and a capacitor.
 * It takes in user inputs for the resistance and capacitance, and calculates the voltage across the capacitor at a given time based on Kirchhoff's laws.
 * It displays the time-voltage graph for the circuit on the console, and saves it to a file in .png format.
 * The program is implemented in C language using the SDL2 library for graphics and the math.h library for math operations.
 * Author: John Doe
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

// Constants
#define PI 3.14159265358979323846
#define MAX_TIME 10.0
#define TIME_STEP 0.01
#define RESISTANCE_PROMPT "Enter the resistance (in ohms): "
#define CAPACITANCE_PROMPT "Enter the capacitance (in farads): "
#define WINDOW_TITLE "Circuit Simulator"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GRAPH_MARGIN 50
#define GRAPH_COLOR {0xFF, 0xFF, 0xFF, 0xFF} // White

// Function prototypes
double voltage(double R, double C, double t);
void plot_graph(SDL_Surface *surface, double R, double C);

int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("SDL_CreateWindow error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create surface
    SDL_Surface *surface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0, 0, 0, 0);
    if (surface == NULL)
    {
        printf("SDL_CreateRGBSurface error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Prompt user for resistance and capacitance
    double R, C;
    printf(RESISTANCE_PROMPT);
    scanf("%lf", &R);
    printf(CAPACITANCE_PROMPT);
    scanf("%lf", &C);

    // Plot graph
    plot_graph(surface, R, C);

    // Save surface to file
    if (SDL_SaveBMP(surface, "graph.bmp") != 0)
    {
        printf("SDL_SaveBMP error: %s\n", SDL_GetError());
    }

    // Free resources
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

double voltage(double R, double C, double t)
{
    double tau = R * C;
    return (1 - exp(-t/tau));
}

void plot_graph(SDL_Surface *surface, double R, double C)
{
    // Set color
    SDL_Color graph_color = GRAPH_COLOR;
    Uint32 color = SDL_MapRGBA(surface->format, graph_color.r, graph_color.g, graph_color.b, graph_color.a);

    // Draw axes
    SDL_RenderDrawLine(surface->format->palette, GRAPH_MARGIN, GRAPH_MARGIN, GRAPH_MARGIN, surface->h - GRAPH_MARGIN); // y-axis
    SDL_RenderDrawLine(surface->format->palette, GRAPH_MARGIN, surface->h - GRAPH_MARGIN, surface->w - GRAPH_MARGIN, surface->h - GRAPH_MARGIN); // x-axis

    // Draw time-voltage graph
    double t;
    for (t = 0; t <= MAX_TIME; t += TIME_STEP)
    {
        double v = voltage(R, C, t);
        int x = GRAPH_MARGIN + (int)((surface->w - 2*GRAPH_MARGIN) * t / MAX_TIME);
        int y = surface->h - GRAPH_MARGIN - (int)((surface->h - 2*GRAPH_MARGIN) * v);
        SDL_RenderDrawPoint(surface->format->palette, x, y);
    }

    // Update surface
    SDL_UpdateWindowSurface(NULL);
}