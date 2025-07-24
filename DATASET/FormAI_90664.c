//FormAI DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>

int main() {
    char str[100], word[20];
    int i, j, count = 0, flag;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';  // Removing the newline character from fgets 
    
    printf("Enter the word to be counted: ");
    scanf("%s", word);
    
    for (i = 0; str[i] != '\0'; i++) {
        flag = 1;
        for (j = 0; word[j] != '\0'; j++) {
            if (str[i+j] != word[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && (str[i+j] == ' ' || str[i+j] == '\0')) {
            count++;
        }
    }
    
    printf("The word '%s' appeared %d time(s) in the string.\n", word, count);
    return 0;
}