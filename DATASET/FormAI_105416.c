//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rating;
    printf("Welcome to our unique movie rating system!\n");
    printf("Please enter your rating for the movie (out of 5):\n");
    scanf("%d", &rating);
    if(rating == 0){
        printf("What?! You didn't like the movie? Did you even watch it or did you just fall asleep?? Try again...\n");
        main();
    } else if(rating == 1){
        printf("Oof, just one star? That's rough buddy. We'll make sure to recommend you some better movies next time.\n");
    } else if(rating == 2){
        printf("A two-star rating? That's like giving a pebble in your shoe two thumbs up. You sure about that? \n");
    } else if(rating == 3){
        printf("A classic 3-star rating. Not too shabby, but not exactly amazing. Kind of like when you get plain popcorn at the movies. It does the job.\n");
    } else if(rating == 4){
        printf("Four stars? That's impressive! This movie must have really resonated with you. Or maybe you just really like the lead actor's hair.\n");
    } else if(rating == 5){
        printf("Woah, maximum rating! You're either a super fan of this movie or you were just highly influenced by the buttery movie theater popcorn. Either way, we're not judging.\n");
    } else{
        printf("Hmm, we're not quite sure what to do with that rating. Did you enter a number between 0-5? Try again...\n");
        main();
    }
    return 0;
}