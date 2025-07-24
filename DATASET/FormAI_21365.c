//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#define WIDTH 10 // define the width of the image
#define HEIGHT 10 // define the height of the image

char img[WIDTH * HEIGHT]; // initialize the image with size WIDTH x HEIGHT

int main(void)
{
    for (int y = 0; y < HEIGHT; y++) // loop through the rows of the image
    {
        for (int x = 0; x < WIDTH; x++) // loop through the columns of the image
        {
            img[(y * WIDTH) + x] = (x + y) % 2; // apply a pattern to the pixels
        }
    }

    for (int y = 0; y < HEIGHT; y++) // loop through the rows of the image
    {
        for (int x = 0; x < WIDTH; x++) // loop through the columns of the image
        {
            putchar(img[(y * WIDTH) + x] ? '#' : '.'); // print the pixel as a '#' or '.'
        }

        putchar('\n'); // move to the next line
    }

    return 0; // exit the program
}