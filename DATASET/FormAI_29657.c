//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char text[200], word[20], replace[20], temp[200];
    int i = 0, j = 0, k, flag = 0;
    
    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter the word you want to replace:\n");
    scanf("%s", word);
    
    printf("Enter the word to replace with:\n");
    scanf("%s", replace);

    while (text[i] != '\0') {
        if (text[i] == ' ' || text[i] == '\n') {
            temp[j] = '\0';
            if (strcmp(temp, word) == 0) {
                flag = 1;
                printf("%s ", replace);
            } else {
                printf("%s ", temp);
            }
            j = 0;
        } else {
            temp[j++] = text[i];
        }
        i++;
    }

    temp[j] = '\0';
    if (strcmp(temp, word) == 0) {
        flag = 1;
        printf("%s", replace);
    } else {
        printf("%s", temp);
    }

    if (flag == 0) {
        printf("\nSorry, %s not found.\n", word);
    }

    return 0;
}