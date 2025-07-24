//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    char keyword[50];
    int count = 0, flag;

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    printf("\nEnter a keyword to count: ");
    scanf("%s", keyword);

    // Remove trailing newline character from string
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    // Convert string to lowercase
    for(int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);

    // Convert keyword to lowercase
    for(int i = 0; keyword[i]; i++)
        keyword[i] = tolower(keyword[i]);
    
    // Count occurrences of keyword in string
    for(int i = 0; i < strlen(str); i++) {
        flag = 1;
        for(int j = 0; j < strlen(keyword); j++) {
            if(str[i+j] != keyword[j]) {
                flag = 0;
                break;
            }
        }
        if(flag)
            count++;
    }

    // Print the result
    printf("\nNumber of occurrences of '%s': %d\n", keyword, count);
    
    return 0;
}