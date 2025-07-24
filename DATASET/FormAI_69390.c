//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include<stdio.h>

int main()
{
    int rating; 
    char movie[20]; 

    printf("Enter the name of the movie you want to rate: ");
    scanf("%s", &movie);

    printf("\nEnter the rating between 1 and 5: ");
    scanf("%d", &rating);

    if(rating<1 || rating>5){
        printf("\nInvalid rating! Please rate the movie between 1 and 5.\n");

    }else{

        printf("\nThank you for rating '%s' with a rating of %d\n", movie, rating);

        switch(rating){

            case 1:
            printf("We are sorry that you did not like the movie.\n");
            break;

            case 2:
            printf("We appreciate your feedback on the movie.\n");
            break;

            case 3:
            printf("We are glad that you found the movie average.\n");
            break;

            case 4:
            printf("We are happy that you liked the movie.\n");
            break;

            case 5:
            printf("We are honored that you loved the movie!\n");
            break;
        }
    }

    return 0;
}