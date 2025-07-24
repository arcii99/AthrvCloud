//FormAI DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    char cipher[] = "Tpnfuijoh!jt!b!xbt!gps!b!dpnnvojuz!up!dbo!opu!jodmvef";
    int key = 1;
    printf("Original Message: ");
    for (int i = 0; cipher[i] != '\0'; ++i) {
        char message = cipher[i];
        if (message >= 'a' && message <= 'z') {
            message = message + key;
            if (message > 'z') {
                message = message - 'z' + 'a' - 1;
            }
            cipher[i] = message;
        }
        else if (message >= 'A' && message <= 'Z') {
            message = message + key;
            if (message > 'Z') {
                message = message - 'Z' + 'A' - 1;
            }
            cipher[i] = message;
        }
    }

    printf("%s\n", cipher);

    return 0;
}