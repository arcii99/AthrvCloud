//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min = 1, max = 20, num1, num2, answer, guess;
    char name[20];
    srand(time(0));

    printf("Hark! Greetings noble sir/madam! I am the Court Mathematician. Pray, what shall I call thee? ");
    scanf("%s", name);

    printf("\nWelcome to our medieval math game, %s. Today, we are going to test your skills in addition! \n", name);
    printf("But fret not, for we shall work with numbers that are not too grand for a knight of your caliber. \n\n");

    printf("I shall choose two numbers from %d to %d and thou shall tell me the sum of the two! Ready?\n\n", min, max);

    while(1) {
        num1 = rand() % (max - min + 1) + min;
        num2 = rand() % (max - min + 1) + min;
        answer = num1 + num2;

        printf("What is %d + %d, %s?\n", num1, num2, name);
        scanf("%d", &guess);

        if(guess == answer) {
            printf("\nWell done, %s! Thou art indeed a master of numbers!\n", name);
            break;
        }
        else {
            printf("\nAlas, thou art mistaken. The correct answer is %d. Try once more!\n\n", answer);
        }
    }

    printf("\nThou art a great addition to our kingdom, %s! Until our next game!\n\n", name);
    return 0;
}