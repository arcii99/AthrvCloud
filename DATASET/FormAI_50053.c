//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int count = 0;
    float time_taken, typing_speed;

    printf("Welcome to the Typing Speed Test Program!\n\n");
    printf("You will be given 10 random words to type as quickly and accurately as possible.\n");
    printf("Press enter to begin...\n");
    getchar();
    system("clear"); // clears the screen

    srand(time(0)); // initializing random number generator with time as seed

    char words[10][20] = {"programming", "decentralized", "innovation", "blockchain", "cryptocurrency", "smart contracts", "dapps", "peer-to-peer", "transparency", "distributed"};

    for(int i = 0; i < 10; i++) { // loop to go through the words array
        printf("Type: %s\n", words[i]);

        time_t start = time(0); // recording the start time
        char user_input[20];
        scanf("%s", user_input);
        time_t end = time(0); // recording the end time

        if(strcmp(words[i], user_input) == 0) {
            printf("Correct!\n\n");
            count++; // incrementing the count of correct words
        } else {
            printf("Incorrect.\n\n");
        }

        time_taken += difftime(end, start); // calculating the time taken for the user to input the word
        sleep(1); // pausing for 1 second before moving on to the next word
        system("clear"); // clears the screen
    }

    printf("You completed the test in %.2f seconds.\n\n", time_taken);
    printf("You typed %d out of 10 words correctly.\n\n", count);

    typing_speed = (float)count / (time_taken / 60); // calculating the typing speed in words per minute

    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}