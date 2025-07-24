//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>

//function declaration
void draw_rectangle(int height, int width);

//main function
int main() {
    int height, width;
    printf("Please enter the height of the rectangle: ");
    scanf("%d", &height);
    printf("Please enter the width of the rectangle: ");
    scanf("%d", &width);
    draw_rectangle(height, width);
    return 0;
}

//function definition
void draw_rectangle(int height, int width) {
    for(int i=0; i<height; i++) {
        if(i==0) {
            for(int j=0; j<width; j++) {
                printf("*");
            }
        }
        else if(i==height-1) {
            printf("\n");
            for(int j=0; j<width; j++) {
                printf("*");
            }
        }
        else {
            printf("\n*");
            for(int j=0; j<width-2; j++) {
                printf(" ");
            }
            printf("*");
        }
    }
}