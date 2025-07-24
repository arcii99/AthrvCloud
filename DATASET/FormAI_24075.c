//FormAI DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void remove_duplicates(char *str) {
    int len = strlen(str);
    int tail = 1;
    for (int i = 1; i < len; ++i) {
        int j;
        for (j = 0; j < tail; ++j) {
            if (str[i] == str[j]) break;
        }
        if (j == tail) {
            str[tail++] = str[i];
        }
    }
    str[tail] = '\0';
}

int main() {
    char str1[] = "Hello World";
    printf("%s\n", str1);

    // Reverse the string
    reverse(str1);
    printf("%s\n", str1);

    // Remove duplicates
    char str2[] = "abbcddeeffgh";
    remove_duplicates(str2);
    printf("%s\n", str2);

    return 0;
}