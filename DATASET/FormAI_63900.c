//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *message = argv[1];
    int i = 0, j = 0, count = 0;

    while (message[i] != '\0') {

        if (message[i] == 'c') {

            j++;

            if (j == 3) {
                count++;
                j = 0;
            }

        } else {
            j = 0;
        }

        i++;

    }

    if (count >= 3) {
        printf("This message appears to be spam!\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;

}