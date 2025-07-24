//FormAI DATASET v1.0 Category: QR code generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed
    printf("My love, let me create a QR code to show you how much I care\n\n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int random_number = rand() % 2; //choose random 0 or 1
            if(random_number == 0){
                printf("\u2588\u2588"); //print a black square
            } else {
                printf("  "); //print a white space
            }
        }
        printf("\n"); //move to next line
    }

    printf("\n\nJust like this QR code, my love for you is binary - it's either 0 or 1,\nand I choose 1 every time because you mean everything to me.\n");
    
    return 0;
}