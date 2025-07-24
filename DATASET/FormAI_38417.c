//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main(){

    char choice;

    printf("Welcome to Pixel Perfect Image Editor!\n");
    printf("Please choose an option:\n");
    printf("a) Add border to the image\n");
    printf("b) Convert to black and white\n");
    printf("c) Blur image\n");
    printf("d) Rotate image\n");
    printf("e) Exit\n");
    
    scanf("%c", &choice);

    switch(choice){
        
        case 'a':
            // adding border to the image code
            break;
        
        case 'b':
            // converting image to black and white code
            break;

        case 'c':
            // blurring the image code
            break;

        case 'd':
            // rotating the image code
            break;

        case 'e':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
    
    return 0;
}