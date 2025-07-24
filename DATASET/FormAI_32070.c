//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

int main(){
    int totalMovies = 0;
    float totalRating = 0.0;
    float averageRating = 0.0;
    char movieName[50];
    int movieRating = 0;
    char goOn = 'y';

    printf("Welcome to the Unique C Movie Rating System!\n");

    while(goOn == 'y'){
        printf("Enter the name of the movie:\n");
        fgets(movieName, 50, stdin);

        printf("Enter your rating from 1 to 10:\n");
        scanf("%d", &movieRating);
        getchar();

        if(movieRating < 1 || movieRating > 10){
            printf("Invalid rating. Please enter a rating between 1 and 10.\n");
            continue;
        }

        totalMovies++;
        totalRating += movieRating;

        printf("Do you want to rate another movie? (y/n)\n");
        scanf("%c", &goOn);
        getchar();
    }

    if(totalMovies == 0){
        printf("You did not rate any movies.\n");
    } else {
        averageRating = totalRating / totalMovies;
        printf("Thank you for rating %d movies!\n", totalMovies);
        printf("The average rating is %.2f.\n", averageRating);
    }

    return 0;
}