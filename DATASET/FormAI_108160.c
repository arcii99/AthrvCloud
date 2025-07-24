//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include<stdio.h>
#include<stdint.h>

int main(){

    printf("Please Input A Number between 1-5:\n");
    int8_t number;
    scanf("%d", &number);

    switch(number){
        case 1:
            printf("You have chosen 1\n");
            break;
        case 2:
            printf("You have chosen 2\n");
            break;
        case 3:
            printf("You have chosen 3\n");
            break;
        case 4:
            printf("You have chosen 4\n");
            break;
        case 5:
            printf("You have chosen 5\n");
            break;
        default:
            printf("Error: Invalid Input\n");
            printf("Shapeshifting to handle error...\n");

            int temp = 0;

            for(int i=0; i<10; i++){
                printf("Shape Shift: ");
                for(int j=i; j<10; j++){
                    printf("*");
                }
                printf("\n");
                temp++;
            }
            printf("The Program has successfully Shape Shifted %d times!\n", temp);
     }

     return 0;
}