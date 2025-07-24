//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    for (int i=0; i<len; i++) {
        int ascii_val = (int)input[i];
        printf(" ___  \n");
        printf("| %c | \n", input[i]);
        printf("|_%d_| \n", ascii_val);
    }
    return 0;
}