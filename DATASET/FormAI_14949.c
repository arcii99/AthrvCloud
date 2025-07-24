//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 200

int main() {
    char msg[MAX_MSG_LEN];

    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    int len = strlen(msg);
    int count = 0;

    for (int i = 0; i < len; i++) {
        // Check for consecutive occurrences of the character 'c'
        if (msg[i] == 'c' || msg[i] == 'C') { // Case-insensitive check
            count++;

            if (count >= 3) { // Spam detected!
                printf("WARNING: Possible spam message detected\n");
                break;
            }
        } else {
            count = 0;
        }
    }

    printf("Message: %s", msg);

    return 0;
}