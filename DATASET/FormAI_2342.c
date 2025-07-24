//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {

    char text[1000];
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);
    
    // Convert all letters to uppercase
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 32;
        }
    }
    printf("Uppercase Text: %s", text);
    
    // Count total vowels
    int vowelCount = 0;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            vowelCount++;
        }
    }
    printf("\nTotal vowels in text: %d", vowelCount);
    
    // Replace all occurrences of a substring
    char search[50];
    printf("\nEnter a substring to replace: ");
    scanf("%s", search);
    char replace[50];
    printf("Enter replacement string: ");
    scanf("%s", replace);
    
    char *result;
    result = strstr(text, search);
    while (result != NULL) {
        strncpy(result, replace, strlen(replace));
        result = strstr(text, search);
    }
    printf("Modified text: %s", text);

    return 0;
}