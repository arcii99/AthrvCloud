//FormAI DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void data_recovery(char *str, int start, int end) {
    if (start >= end) {
        printf("%s\n", str);
        return;
    }

    // Check if current character is a digit
    if (isdigit(str[start])) {
        data_recovery(str, start + 1, end);
    } else {
        // Swap current character with characters to the right of it
        for (int i = start + 1; i <= end; i++) {
            if (!isdigit(str[i]) && str[start] != str[i]) {
                char temp = str[start];
                str[start] = str[i];
                str[i] = temp;
                data_recovery(str, start + 1, end);
                // Swap back to original order
                str[i] = str[start];
                str[start] = temp;
            }
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string containing digits and non-digits: ");
    scanf("%s", str);
    data_recovery(str, 0, strlen(str) - 1);
    return 0;
}