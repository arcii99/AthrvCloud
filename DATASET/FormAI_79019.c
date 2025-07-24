//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    const int WIDTH = 8;
    const int HEIGHT = 8;
    srand(time(0));

    char pixelArt[HEIGHT][WIDTH];
    char shapes[] = {'#', '@', '*', '&', '$', '%', '!', '?'};
    int shapesSize = sizeof(shapes) / sizeof(shapes[0]);

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            pixelArt[i][j] = shapes[rand() % shapesSize];
        }
    }

    printf("\n   -------------------------\n");
    for(int i = 0; i < HEIGHT; i++){
        printf("   | ");
        for(int j = 0; j < WIDTH; j++){
            printf("%c ", pixelArt[i][j]);
        }
        printf("|\n");
    }
    printf("   -------------------------\n\n");

    char userInput;
    printf("Can you guess what shape has been used in this pixel art?\n");
    printf("Enter your guess: ");
    scanf("%c", &userInput);

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(pixelArt[i][j] == userInput){
                printf("Well done! You found the shape!\n");
                return 0;
            }
        }
    }

    printf("Oops! The shape you guessed is not in the pixel art. Better luck next time!\n");
    return 0;
}