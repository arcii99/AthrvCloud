//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, flag = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '{') {
            flag++;
        }
        else if (str[i] == '}') {
            flag--;
        }
    }

    if (flag == 0) {
        printf("Valid syntax\n");
    }
    else {
        printf("Invalid syntax\n");
    }

    return 0;
}