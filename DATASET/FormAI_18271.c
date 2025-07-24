//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void shift_case(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = *(str + i);
        if (islower(c)) {
            *(str + i) = toupper(c);
        } else if (isupper(c)) {
            *(str + i) = tolower(c);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a sentence:\n");
    fgets(str, 100, stdin);
    printf("Original sentence: %s", str);
    shift_case(str);
    printf("Shapeshifted sentence: %s", str);
    return 0;
}