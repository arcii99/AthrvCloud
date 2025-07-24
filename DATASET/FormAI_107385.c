//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(char image[10][10]) {
    int i, j;
    printf("Generated Pixel Art:\n");
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%c  ", image[i][j]);
        }
        printf("\n");
    }
}

void pixel_art_generator(char image[10][10]){
    int i, j, choose_color;
    char colors[] = {'R', 'G', 'B', 'Y', 'O'};
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            choose_color = rand() % 5;
            image[i][j] = colors[choose_color];
        }
    }
}

int main(){
    char image[10][10];
    pixel_art_generator(image);
    display(image);
    return 0;
}