//FormAI DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

void readString(char *str) {
    fgets(str, MAX_STR_LEN, stdin);
    
    // Remove newline character
    char *pos = strchr(str, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    readString(str);
    
    // Convert to uppercase
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    
    // Replace " " with "_"
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
    
    // Print result
    printf("Result: %s", str);
    
    return 0;
}