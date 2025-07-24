//FormAI DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 100: ");
    scanf("%d", &rating);
    
    if (rating <= 20) {
        printf("Oh no... this movie was a dumpster fire. We cannot recommend it.\n");
    } else if (rating <= 50) {
        printf("This movie was okay, but nothing worth writing home about.\n");
    } else if (rating <= 80) {
        printf("This movie was good, and definitely worth a watch.\n");
    } else if (rating <= 90) {
        printf("This movie was excellent! We highly recommend it!\n");
    } else {
        printf("Wow! This movie was a masterpiece. You cannot miss it!\n");
    }

    return 0;
}