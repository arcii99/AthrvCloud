//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rating;
    char movie[50];
    printf("Welcome to our unique C Movie Rating System!\n\n");
    printf("Please enter the name of the movie you want to rate: ");
    fgets(movie, 50, stdin);
    printf("\nThank you for choosing '%s'%s!\n\n", movie, ". Let's start rating!");
    printf("Please give a rating from 0 to 10: ");
    scanf("%d", &rating);

    if(rating >= 0 && rating <= 3){
        printf("\nYour rating is %d. Sorry to hear that you did not enjoy the movie.\n", rating);
    }
    else if(rating > 3 && rating <=6){
        printf("\nYour rating is %d. Looks like the movie was not bad.\n", rating);
    }
    else if(rating > 6 && rating <=8){
        printf("\nYour rating is %d. Great to know that you liked the movie!\n", rating);
    }
    else if(rating > 8 && rating <= 10){
        printf("\nYour rating is %d. Excellent! Seems like this movie is one of your favourites!\n", rating);
    }
    else{
        printf("\nInvalid rating. Please enter a number between 0 and 10.\n");
    }

    printf("\nThank you for using our Movie Rating System. Hope to see you again soon!\n");

    return 0;
}