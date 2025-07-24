//FormAI DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char clue[10];
    int num_of_clues = 0;
    printf("Welcome Detective, let's find the culprit!\n");
    printf("Enter the number of clues we have: ");
    scanf("%d", &num_of_clues);
    char** clues = malloc(num_of_clues * sizeof(char*));
    for(int i = 0; i < num_of_clues; i++) {
        printf("Enter the clue number %d: ", i+1);
        scanf("%s", clue);
        clues[i] = malloc((strlen(clue)+1) * sizeof(char));
        strcpy(clues[i], clue);
    }
    printf("\nThe clues we have are:\n");
    for(int i = 0; i < num_of_clues; i++) {
        printf("%d. %s\n", i+1, clues[i]);
    }
    printf("\nLet's sort the clues in alphabetical order...\n");
    
    int i, j;
    char* temp;
    for(i = 0; i < num_of_clues-1; i++) {
        for(j = i+1; j < num_of_clues; j++) {
            if(strcmp(clues[i], clues[j]) > 0) {
                temp = clues[i];
                clues[i] = clues[j];
                clues[j] = temp;
            }
        }
    }
    
    printf("\nThe clues sorted in alphabetical order are:\n");
    for(int i = 0; i < num_of_clues; i++) {
        printf("%d. %s\n", i+1, clues[i]);
    }
    
    printf("\nThank you Detective for your help, the culprit will be caught soon!\n");
    
    for(int i = 0; i < num_of_clues; i++) {
        free(clues[i]);
    }
    free(clues);
    return 0;
}