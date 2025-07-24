//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int length, width, max_color_int, pixel_count;
    printf("Enter length: ");
    scanf("%d", &length);
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter maximum color intensity: ");
    scanf("%d", &max_color_int);
    pixel_count = length * width;

    int pixels[pixel_count];
    for (int i = 0; i < pixel_count; i++) {
        pixels[i] = rand() % max_color_int;
    }

    printf("\nGenerated Pixel Art:\n\n");
    int counter = 0;
    for (int i = 0; i < pixel_count; i++) {
        printf("%d ", pixels[i]);
        counter++;
        if (counter == length) {
            printf("\n");
            counter = 0;
        }
    }

    return 0;
}