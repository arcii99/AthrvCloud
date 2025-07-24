//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main(void) {
    char movie[100];
    int rating = 0;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter the name of the movie: ");
    fgets(movie, 100, stdin);

    printf("Please rate the movie from 1 to 5: ");
    scanf("%d", &rating);

    switch(rating) {
        case 1:
            printf("Sorry to hear that you didn't enjoy %s\n", movie);
            break;
        case 2:
            printf("%s was just okay, huh?\n", movie);
            break;
        case 3:
            printf("Glad to hear you liked %s\n", movie);
            break;
        case 4:
            printf("Wow, %s really impressed you, didn't it?\n", movie);
            break;
        case 5:
            printf("We're so happy to hear that you loved %s!\n", movie);
            break;
        default:
            printf("Sorry, your rating of %d is not valid.\n", rating);
    }

    return 0;
}