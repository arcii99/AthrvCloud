//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Pixel Art Generator!\n\n");
    printf("Enter the dimensions of your desired image in pixels:\n");
    int width, height;
    scanf("%d %d", &width, &height);
    srand(time(NULL));
    char pixel_chars[2] = {' ','X'};
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int random_index = rand() % sizeof(pixel_chars);
            printf("%c", pixel_chars[random_index]);
        }
        printf("\n");
    }
    printf("\nTa-da! Your masterpiece has been created. Share it with the world!\n");
    return 0;
}