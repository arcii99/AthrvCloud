//FormAI DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *clue;
    int line_number;
} Error;

void investigate(int clue_number) {
    char *clues[] = {
        "The suspect was last seen near the location of the error.",
        "The suspect left a trail of incorrect data types.",
        "The suspect attempted to access a NULL pointer.",
        "The suspect used an unitialized variable.",
        "The suspect left their fingerprints in the code.",
        "The suspect left a typo as evidence."
    };
    printf("Investigating clue #%d...\n", clue_number);
    printf("Clue found: %s\n", clues[clue_number-1]);
}

void interrogate(char *suspect) {
    if (strcmp(suspect, "SyntaxError") == 0) {
        printf("It appears %s has been caught in the act of causing chaos in our code.\n", suspect);
    } else if (strcmp(suspect, "TypeError") == 0) {
        printf("%s, we have reason to suspect you may be involved in the error at line %d.\n", suspect, __LINE__);
    } else if (strcmp(suspect, "SegmentationFault") == 0) {
        printf("%s, you cannot escape justice for the crime you have committed.\n", suspect);
    } else {
        printf("%s, you are a suspect in our investigation. What do you have to say for yourself?\n", suspect);
    }
}

void arrest(Error *e) {
    printf("There has been an error at line %d:\n", e->line_number);
    printf("%s\n", e->clue);
    printf("The suspect is being apprehended.\n");
    exit(1);
}

int main() {
    Error e = {"Mismatched data types", 29};
    arrest(&e);
    return 0;
}