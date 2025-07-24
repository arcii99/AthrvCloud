//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int randomNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // seed the random number generator
    srand(time(0));
    int num;
    
    // loop to ask user for input
    while (1) {
        printf("What is your question? (press q to quit)\n");
        char str[100];
        scanf("%s", str);

        if (str[0] == 'q' && str[1] == '\0') {
            break;
        }
        
        // generate a random number between 0 and 4
        num = randomNum(0, 4);

        // switch statement to output a response based on the random number generated
        switch (num) {
            case 0:
                printf("It is certain.\n");
                break;
            case 1:
                printf("Without a doubt.\n");
                break;
            case 2:
                printf("Reply hazy, try again.\n");
                break;
            case 3:
                printf("Don't count on it.\n");
                break;
            case 4:
                printf("Very doubtful.\n");
                break;
        }
    }

    return 0;
}