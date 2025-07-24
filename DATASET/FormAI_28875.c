//FormAI DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <ctype.h>

int recursive_count(char* str) {
    if (*str == '\0') {
        return 0;
    }
    if (isspace(*str)) {
        return recursive_count(str + 1);
    }
    int count = 1;
    while (*str != '\0' && !isspace(*str)) {
        count++;
        str++;
    }
    return count + recursive_count(str);
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    int count = recursive_count(str);
    printf("Word count: %d", count);
    return 0;
}