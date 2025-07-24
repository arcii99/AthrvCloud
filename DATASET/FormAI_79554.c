//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>

int main() {

    int rating;
    printf("What is your movie rating? (1-5)\n");
    scanf("%d", &rating);

    switch(rating) {
        case 1:
            printf("One star? Ouch.\n");
            break;
        case 2:
            printf("Two stars? I've seen worse.\n");
            break;
        case 3:
            printf("Three stars? Not bad, not bad.\n");
            break;
        case 4:
            printf("Four stars? Nice job, Hollywood.\n");
            break;
        case 5:
            printf("Five stars? Now that's what I call a movie!\n");
            break;
        default:
            printf("Sorry, that's not a valid rating.\n");
            break;
    }

    return 0;
}