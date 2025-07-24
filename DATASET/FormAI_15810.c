//FormAI DATASET v1.0 Category: Random ; Style: energetic
/* Get ready for some wild randomization! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Hold on to your hats folks, because we're about to get random!\n");

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 0 and 99
    int rand_num = rand() % 100;

    printf("Our lucky number for today is... %d!\n", rand_num);

    // Let's roll some dice!
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    printf("We rolled a %d and a %d!\n", dice1, dice2);

    // Flip a coin
    int flip = rand() % 2;

    if (flip) {
        printf("The coin landed on heads!\n");
    } else {
        printf("The coin landed on tails!\n");
    }

    // Generate a random RGB color
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    printf("Our random color is RGB(%d, %d, %d)!\n", r, g, b);

    // Now let's generate a random string of letters
    char letters[11];
    const char* alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 10; i++) {
        char letter = alphabet[rand() % 26];
        letters[i] = letter;
    }

    letters[10] = '\0';
    printf("Our random string is %s!\n", letters);

    // Okay, now let's end this randomness with a random quote
    const char* quotes[5] = {
        "The best way to predict the future is to invent it. -Alan Kay",
        "The best time to plant a tree was 20 years ago. The second best time is now. -Chinese Proverb",
        "Imagination is more important than knowledge. -Albert Einstein",
        "Everything you can imagine is real. -Pablo Picasso",
        "Believe you can and you're halfway there. -Theodore Roosevelt"
    };

    int index = rand() % 5;
    printf("And let's leave you on this thought: \"%s\"\n", quotes[index]);

    return 0;
}