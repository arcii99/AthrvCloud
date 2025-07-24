//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("\n\t\tWelcome to the Happy Movie Rating System!\n");

    int rating;

    printf("\nEnter your rating (1-10): ");
    scanf("%d", &rating);

    if(rating < 1 || rating > 10){
        printf("\nInvalid rating! Please enter a number between 1 and 10.\n");
        return 0;
    }

    printf("\nThank you for your rating! Here is the corresponding Happy Rating: ");

    switch(rating){

        case 1:
            printf("X_X\n");
            break;

        case 2:
            printf(":-(\n");
            break;

        case 3:
            printf(":-|\n");
            break;

        case 4:
            printf(":-/\n");
            break;

        case 5:
            printf(":-)\n");
            break;

        case 6:
            printf(":-D\n");
            break;

        case 7:
            printf(":-O\n");
            break;

        case 8:
            printf(";-)\n");
            break;

        case 9:
            printf(":-P\n");
            break;

        case 10:
            printf(":-D\n");
            break;
    }

    printf("\nThank you for using the Happy Movie Rating System! Have a nice day!\n");
    
    return 0;
}