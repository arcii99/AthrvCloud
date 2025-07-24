//FormAI DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

// function to remove spaces and tabs from a string
void remove_spaces_and_tabs(char *str) {
    int j = 0, i;
    
    for(i = 0; str[i]; i++) {
        if(str[i] != ' ' && str[i] != '\t')
            str[j++] = str[i];
    }
    
    str[j] = '\0';
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    // remove all spaces and tabs from the string
    remove_spaces_and_tabs(str);
    
    // print the modified string
    printf("Modified String: %s\n", str);

    return 0;
}