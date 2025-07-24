//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    int len, i, count;

    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);  // read user input
    len = strlen(input);

    count = 0;
    for (i = 0; i < len; i++) {
        if (input[i] == '(') {
            count ++;
        } else if (input[i] == ')') {
            count --;
        }
        if (count < 0) {
            printf("Intrusion detected!\n"); // intrusion detected if count < 0
            exit(1);
        }
    }

    if (count == 0) {
        printf("No intrusion detected.\n");
    } else {
        printf("Intrusion detected!\n"); // more opening parentheses than closing
        exit(1);
    }

    return 0;
}