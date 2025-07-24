//FormAI DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rating;
    char movieTitle[50];

    printf("Welcome to the Unique C Movie Rating System\n");
    printf("Please enter the title of the movie you want to rate (Max. 50 characters):\n");
    scanf("%[^\n]", movieTitle);
    fflush(stdin);

    printf("Please enter your rating for %s (0-100):\n", movieTitle);
    scanf("%d", &rating);

    if(rating >= 0 && rating <= 20){
        printf("Oops! Seems like %s is not worth watching. Your rating is %d%%.\n", movieTitle, rating);
    }
    else if(rating > 20 && rating <= 40){
        printf("Hmmm.. %s might not be the best movie out there. Your rating is %d%%.\n", movieTitle, rating);
    }
    else if(rating > 40 && rating <= 60){
        printf("Not too bad! %s is an average movie according to you. Your rating is %d%%.\n", movieTitle, rating);
    }
    else if(rating > 60 && rating <= 80){
        printf("Great! You really enjoyed %s. Your rating is %d%%.\n", movieTitle, rating);
    }
    else if(rating > 80 && rating <= 100){
        printf("Wow! %s is a masterpiece. Your rating is %d%%.\n", movieTitle, rating);
    }
    else{
        printf("Please enter a rating between 0-100.\n");
        exit(0);
    }

    printf("Thank you for rating %s!\n", movieTitle);

    return 0;
}