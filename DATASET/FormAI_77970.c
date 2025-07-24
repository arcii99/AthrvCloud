//FormAI DATASET v1.0 Category: Spell checking ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

void checkSpelling(char *input) {
    char words[MAX_LENGTH][MAX_LENGTH];   //array to store words from dictionary
    char *result = strtok(input, " ");    //split the input based on space
    int i = 0, flag = 0;
  
    //reading words from dictionary.txt and storing in array
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Dictionary not found");
        exit(0);
    }
    while (fgets(words[i], MAX_LENGTH, file)) {
        words[i][strlen(words[i]) - 1] = '\0';  //removing \n from string
        i++;
    }
    fclose(file);
  
    //checking words from input with the words in dictionary
    while (result != NULL) {
        flag = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(result, words[j]) == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            printf("Spelling error: %s\n", result);
        }
        result = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter text: ");
    fgets(input, MAX_LENGTH, stdin);   //reading user input
    input[strcspn(input, "\n")] = 0;
  
    checkSpelling(input);    //checking spelling of input
  
    return 0;
}