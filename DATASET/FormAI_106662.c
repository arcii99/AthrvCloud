//FormAI DATASET v1.0 Category: Fractal Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// Constant variables
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int POINT_SIZE = 2;
const int MAX_ITERATIONS = 100000;
const double SCALE = 200;
const double MIN_X = -2.2;
const double MAX_X = 1.2;
const double MIN_Y = -1.7;
const double MAX_Y = 1.7;

// Function prototypes
void init();
void drawPixel(int x, int y);
void drawMandelbrot();
int isMandelbrot(double x0, double y0, int maxIterations);

// Global variables
int* pixels;
double x;
double y;
double xOffset;
double yOffset;

int main()
{
    init();
    drawMandelbrot();

    return 0;
}

void init()
{
    // Initialize random seed
    srand(time(NULL));

    // Allocate memory for the pixel array
    pixels = (int*)malloc(WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(int));

    // Set initial values for x, y, xOffset, yOffset
    x = 0;
    y = 0;
    xOffset = rand() % 1000 / 1000.0;
    yOffset = rand() % 1000 / 1000.0;
}

void drawPixel(int x, int y)
{
    pixels[x + y * WINDOW_WIDTH] = 0xFFFFFFFF;
}

void drawMandelbrot()
{
    for (int pixelY = 0; pixelY < WINDOW_HEIGHT; pixelY++)
    {
        y = (((double)pixelY) / WINDOW_HEIGHT * (MAX_Y - MIN_Y) + MIN_Y) + yOffset;

        for (int pixelX = 0; pixelX < WINDOW_WIDTH; pixelX++)
        {
            x = (((double)pixelX) / WINDOW_WIDTH * (MAX_X - MIN_X) + MIN_X) + xOffset;

            if (isMandelbrot(x, y, MAX_ITERATIONS))
            {
                drawPixel(pixelX, pixelY);
            }
        }
    }
}

int isMandelbrot(double x0, double y0, int maxIterations)
{
    double x = 0;
    double y = 0;

    for (int i = 0; i < maxIterations; i++)
    {
        double xTemp = x * x - y * y + x0;
        double yTemp = 2 * x * y + y0;

        if (xTemp * xTemp + yTemp * yTemp > SCALE)
        {
            return i;
        }

        x = xTemp;
        y = yTemp;
    }

    return -1;
}