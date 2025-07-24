//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle(char* array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main()
{
    char inputbuf[256];
    char testbuf[256] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int urtime, cptime, lasttime, tcount, correctcount, speed;
    int timedelta, totaltime, totalmsgs;
    int idx, i;
    char c;

    printf("Hello! Welcome to the Typing Speed Test program!\n");
    printf("The object of the game is to type out the characters as fast as possible.\n");
    printf("Are you ready? Press Enter to begin.\n");
    fgets(inputbuf, 256, stdin);

    srand(time(NULL)); 
    totaltime = 0;
    totalmsgs = 0;
    while (1) {
        tcount = 0;
        correctcount = 0;

        shuffle(testbuf, strlen(testbuf));
        testbuf[strlen(testbuf)-1] = '\0';
        lasttime = time(NULL);
        printf("\nType this as fast as you can:\n%s\n\n", testbuf);

        while ((c = getchar()) != '\n' && (c != EOF)) {
            if (c == testbuf[tcount]) {
                ++correctcount;
            }
            ++tcount;
        }

        cptime = time(NULL);
        if (correctcount == strlen(testbuf)) {
            printf("Good job! You typed the message perfectly!\n");
        }
        else {
            printf("Sorry, you made %d errors.\n", strlen(testbuf) - correctcount);
        }

        totaltime += (timedelta = cptime - lasttime);
        ++totalmsgs;
        speed = (correctcount * 60) / timedelta;
        printf("Your typing speed was %d characters per minute! \n", speed);
        printf("Press Enter to continue, or type \"quit\" to quit.\n");
        fgets(inputbuf, 256, stdin);
        if (!strncmp(inputbuf, "quit", 4)) {
            break;
        }
    }

    printf("Thanks for playing. You typed an average of %d characters per minute in %d tests.\n", (totalmsgs * strlen(testbuf) * 60) / totaltime, totalmsgs);
    return 0;
}