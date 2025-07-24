//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int rating;
    char movie_name[50], response;
    printf("Welcome to the Post-Apocalyptic Movie Rating System!\n");
    do {
        printf("Please enter the name of the movie (no spaces): ");
        scanf("%s", movie_name);
        printf("Please rate the movie out of 10: ");
        scanf("%d", &rating);
        if(rating >= 8){
            printf("The movie %s has been deemed excellent, and has been added to our list of recommended movies.\n", movie_name);
            FILE *file = fopen("excellent_movies.txt", "a");
            fprintf(file, "%s\n", movie_name);
            fclose(file);
        }
        else if(rating >= 5 && rating < 8){
            printf("The movie %s has been deemed average, and has been added to our list of watchable movies.\n", movie_name);
            FILE *file = fopen("average_movies.txt", "a");
            fprintf(file, "%s\n", movie_name);
            fclose(file);
        }
        else{
            printf("The movie %s has been deemed terrible, and will not be added to our list of recommended movies.\n", movie_name);
        }
        
        printf("Do you want to rate another movie? (Y/N): ");
        scanf(" %c", &response);
    } while(response == 'Y' || response == 'y');
    printf("Thanks for using our Post-Apocalyptic Movie Rating System!");
    return 0;
}