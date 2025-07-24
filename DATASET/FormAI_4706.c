//FormAI DATASET v1.0 Category: Random ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my extremely exciting C random example program!\n");
    printf("Are you ready for some crazy random numbers? Let's go!\n");

    // Generate and print 10 random integers between 1 and 100
    printf("Random integers: ");
    for(int i=0; i<10; i++) {
        printf("%d ", (rand() % 100) + 1);
    }

    // Generate and print 10 random floats between 0 and 1
    printf("\nRandom floats: ");
    for(int i=0; i<10; i++) {
        printf("%.2f ", ((float) rand() / RAND_MAX));
    }

    // Generate and print 10 random characters between 'a' and 'z'
    printf("\nRandom characters: ");
    for(int i=0; i<10; i++) {
        printf("%c ", ((rand() % 26) + 'a'));
    }

    printf("\nWow, isn't that exciting? But wait, there's more!\n");

    // Generate and print a random password consisting of 8 characters (upper and lowercase letters and digits)
    printf("\nRandom password: ");
    for(int i=0; i<8; i++) {
        int random_num = rand() % 62;
        char random_char;
        if(random_num < 26) {
            random_char = (char) (random_num + 'a');
        } else if(random_num < 52) {
            random_char = (char) (random_num - 26 + 'A');
        } else {
            random_char = (char) (random_num - 52 + '0');
        }
        printf("%c", random_char);
    }

    printf("\nI bet you've never seen such an exciting program before!\n");

    return 0;
}