//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct clue {
    char location[100];
    char evidence[200];
};

void createFile(struct clue *tempClue) {
    FILE *fptr;
    fptr = fopen("clues.txt", "w");

    if(fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(fptr, "Location: %s\nEvidence: %s", tempClue->location, tempClue->evidence);
    fclose(fptr);
}

void readFile() {
    FILE *fptr;
    char c;

    fptr = fopen("clues.txt", "r");

    if(fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\nClue found: \n\n");

    while((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }

    fclose(fptr);
}

int main() {
    printf("Welcome to the Sherlock Holmes File Handling program.\n\n");

    struct clue newClue;

    printf("Enter the location of the clue: ");
    fgets(newClue.location, 100, stdin);

    printf("Enter the evidence found: ");
    fgets(newClue.evidence, 200, stdin);

    createFile(&newClue);

    printf("\nNew Clue created and saved to file.\n\n");

    char ans[3];

    printf("Do you want to view the clue? (yes or no) ");
    fgets(ans, 3, stdin);

    if(strcmp(ans, "yes") == 0) {
        readFile();
    }

    return 0;
}