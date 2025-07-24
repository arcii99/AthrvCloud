//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1024

int main() {
    char *messages[] = {"The birds fly south",
                        "I like apples",
                        "Buy a new car now!",
                        "This is not spam",
                        "Free money",
                        "click here for a chance to win!",
                        "You have won a prize!",
                        "This is not a scam",
                        "We have a limited time offer for you",
                        "Refinance your home now",
                        "Make money quick"};

    int num_messages = sizeof(messages) / sizeof(messages[0]);
    int i, j, k, l, flag;
    char msg[MAX_MSG_LEN], chk[MAX_MSG_LEN];

    printf("Enter your message: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0';

    for (i = 0; i <= strlen(msg); i++) {
        for (j = i + 1; j <= strlen(msg); j++) {
            k = 0;
            for (l = i; l < j; l++) {
                chk[k++] = msg[l];
            }
            chk[k] = '\0';

            flag = 0;
            for (k = 0; k < num_messages; k++) {
                if (strcmp(chk, messages[k]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                printf("SPAM DETECTED!!!\n");
                exit(0);
            }
        }
    }

    printf("This is not a spam message.\n");

    return 0;
}