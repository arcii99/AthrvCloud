//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Romeo declares his love for Juliet
    printf("O Juliet, my love for thee runs deep\n");

    int castles = 0;
    int any_errors = 0;

    // Juliet asks Romeo to build her a castle
    printf("Sweet Romeo, please build me a castle\n");

    // Romeo tries to build the castle
    if (castles < 1) {
        // Romeo encounters an error
        printf("Alack, I cannot build thee a castle without resources\n");
        any_errors = 1;

        // Romeo seeks help from a wise old man
        printf("I shall seek wisdom from the old man\n");
        if (rand() % 2) {
            // The old man was helpful
            printf("The old man hath provided me with materials to build thy castle\n");
            castles++;
        } else {
            // The old man could not help
            printf("The old man could not help, thy castle remains only a dream\n");
            any_errors = 1;
        }
    }

    // Juliet thanks Romeo for trying
    if (!any_errors) {
        printf("I thank thee, Romeo, for thy valiant effort\n");
    }

    return 0;
}