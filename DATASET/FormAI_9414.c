//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hi there! Let's have some geometric fun!\n");
    printf("We're going to create a simple square using ASCII characters.\n");

    int sideLength;
    printf("What's the length of the square's sides? ");
    scanf("%d", &sideLength);
    printf("Awesome! Here's your square: \n");

    for(int i = 0; i < sideLength; i++) {
        for(int j = 0; j < sideLength; j++) {
            if(i == 0 || i == sideLength-1 || j == 0 || j == sideLength-1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    printf("Beautiful, isn't it? But let's take it up a notch.\n");
    printf("How about we calculate the area and perimeter of your square?\n");

    int area = sideLength * sideLength;
    int perimeter = 4 * sideLength;

    printf("The area of the square is %d square units\n", area);
    printf("The perimeter of the square is %d units\n", perimeter);

    printf("Yay, we did it! Let's do more geometric stuff next time. Bye!\n");

    return 0;
}