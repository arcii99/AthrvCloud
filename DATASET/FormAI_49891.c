//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>

int main() {
    int rating, sum=0, count=0;
    float average;
    char movie[50];

    printf("Enter the name of the movie: ");
    scanf("%[^\n]s", movie);

    printf("\nEnter the rating for %s (Enter -1 to stop): ", movie);
    scanf("%d", &rating);

    while(rating != -1) {
        sum += rating;
        count++;

        printf("Enter the rating for %s (Enter -1 to stop): ", movie);
        scanf("%d", &rating);
    }

    if(count == 0) {
        printf("\nNo rating given for %s.", movie);
    } else {
        average = (float) sum / count;
        printf("\nThe average rating for %s is %.2f.", movie, average);
    }

    return 0;
}