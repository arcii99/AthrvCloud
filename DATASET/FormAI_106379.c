//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System\n\n");

    while(1) {
        printf("Please enter your rating (1-5) or 0 to exit: ");
        scanf("%d", &rating);
        if(rating == 0) {
            printf("\nThank you for using the Unique C Movie Rating System\n");
            break;
        }
        else if(rating < 1 || rating > 5) {
            printf("Invalid rating! Please enter a rating between 1-5.\n");
            continue;
        }
        else {
            switch(rating) {
                case 1:
                    printf("You rated the movie as: Terrible\n");
                    break;
                case 2:
                    printf("You rated the movie as: Poor\n");
                    break;
                case 3:
                    printf("You rated the movie as: Average\n");
                    break;
                case 4:
                    printf("You rated the movie as: Good\n");
                    break;
                case 5:
                    printf("You rated the movie as: Excellent\n");
                    break;
            }
        }
    }

    return 0;
}