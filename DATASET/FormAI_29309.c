//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Medieval Movie Rating System!\n");
    int rating;
    char movie_title[50];
    char reviewer_name[50];

    printf("\nEnter the movie title: ");
    scanf("%s", movie_title);

    printf("\nEnter the name of the reviewer: ");
    scanf("%s", reviewer_name);

    printf("\nEnter your rating (1-5): ");
    scanf("%d", &rating);

    if (rating == 1) {
        printf("Hark! %s doth declare thou shall not waste thy time upon this film! Verily, it is foul!", reviewer_name);
    } else if (rating == 2) {
        printf("Methinks %s found this movie to be somewhat average. Thou mayest watch it, or pass it over without concern.", reviewer_name);
    } else if (rating == 3) {
        printf("Lo! %s hast deemed this movie to be good. Thou mayest enjoy it with a merry heart.", reviewer_name);
    } else if (rating == 4) {
        printf("Prithee, %s declareth this film to be excellent! Verily, it is a must-see!", reviewer_name);
    } else if (rating == 5) {
        printf("By Saint George, %s hast seen the light! This movie is a masterpiece, thou must see it at once!", reviewer_name);
    } else {
        printf("Alas! Thou hast entered an invalid rating. Please enter a number between 1-5.");
        return 1;
    }

    printf("\nThank you for using the Medieval Movie Rating System! Fare thee well!\n");

    return 0;
}