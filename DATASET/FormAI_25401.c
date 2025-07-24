//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {

    char input[255];
    int i, j;
    printf("Enter a string with special characters: ");
    fgets(input, 255, stdin);
   
    for(i = 0; input[i] != '\0'; ++i) {
        
        while (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))) {
            for (j = i; input[j] != '\0'; ++j) {
                input[j] = input[j+1];
            }
            input[j] = '\0';
        }
    }
   
    printf("Sanitized Input: %s", input);

   return 0;
}