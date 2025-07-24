//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

// Define the constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int MAX_ITERATIONS = 1000;

// Define the complex number structure
typedef struct {
    double real;
    double imag;
} Complex;

// Define the color structure for the SDL2 renderer
typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
} Color;

// Function declarations
void createMandelbrotSet(SDL_Renderer *renderer);
int calculateMandelbrotSet(Complex c);
Color getColor(int iterations);

int main() {
    // Intialize the SDL2 library and create a window and renderer
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Create the Mandelbrot set
    createMandelbrotSet(renderer);

    // Event loop to keep the window open
    SDL_Event event;
    while (1) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
    }

    // Clean up and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// Function to create the Mandelbrot set
void createMandelbrotSet(SDL_Renderer *renderer) {
    // Define the bounds of the image
    double xmin = -2.0;
    double xmax = 2.0;
    double ymin = -2.0;
    double ymax = 2.0;

    // Loop through each pixel in the image and calculate the corresponding point in the Mandelbrot set
    for (int x = 0; x < WINDOW_WIDTH; x++) {
        for (int y = 0; y < WINDOW_HEIGHT; y++) {
            // Calculate the complex number corresponding to the pixel
            Complex c = {
                xmin + (double)x * (xmax - xmin) / (double)WINDOW_WIDTH,
                ymin + (double)y * (ymax - ymin) / (double)WINDOW_HEIGHT
            };

            // Calculate the number of iterations for the complex number
            int iterations = calculateMandelbrotSet(c);

            // Get the color for the number of iterations and set the pixel in the renderer
            Color color = getColor(iterations);
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    // Present the renderer to the window
    SDL_RenderPresent(renderer);
}

// Function to calculate the Mandelbrot set for a given complex number
int calculateMandelbrotSet(Complex c) {
    Complex z = { 0, 0 };
    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        // Calculate the next value of z
        Complex z_next = {
            z.real * z.real - z.imag * z.imag + c.real,
            2 * z.real * z.imag + c.imag
        };

        // If the magnitude of z exceeds 2, the point is not in the Mandelbrot set
        if (sqrt(z_next.real * z_next.real + z_next.imag * z_next.imag) > 2) {
            break;
        }

        z = z_next;
        iterations++;
    }

    return iterations;
}

// Function to get the color for a given number of iterations
Color getColor(int iterations) {
    Color color;

    if (iterations == MAX_ITERATIONS) {
        color.r = 0;
        color.g = 0;
        color.b = 0;
    } else {
        color.r = 255 * (double)iterations / (double)MAX_ITERATIONS;
        color.g = 255 * (double)iterations / (double)MAX_ITERATIONS;
        color.b = 255 * (double)iterations / (double)MAX_ITERATIONS;
    }

    return color;
}