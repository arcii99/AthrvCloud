//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>

int main()
{
    int user_rating; 
    char movie_title[50]; 

    printf("My dearest, please enter the title of the movie: ");
    scanf("%s", movie_title);

    printf("My sweet, please rate the movie on a scale of 1 to 10: ");
    scanf("%d", &user_rating);

    if (user_rating <= 3)
    {
        printf("My love, %s was not good enough for you. I am sorry.", movie_title);
    }
    else if (user_rating <= 7)
    {
        printf("My joy, %s was a decent movie for the night we spent together.\n", movie_title);
        printf("I'm glad we chose it, let's cuddle up together for more.");
    }
    else if (user_rating <= 10)
    {
        printf("My love, %s was the best movie we ever saw!\n", movie_title);
        printf("You make me so happy, let's watch more romantic movies like this!");
    }
    else
    {
        printf("My dearest, please rate the movie properly on a scale of 1 to 10.");
    }
    return 0;
}