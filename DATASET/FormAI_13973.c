//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printIntro() {
    printf("Welcome to the Surrealist Date Converter! This program is designed to take a date in Natural Language and convert it into a unique surrealist date.\n\n");
}

void printInstructions() {
    printf("To enter a date please type it in Natural Language and press Enter:\n");
}

void convertDate(char* date) {
    char* surrealistDate;
    surrealistDate = malloc(100 * sizeof(char));
    
    // Use surrealistic language to convert the date
    sprintf(surrealistDate, "The %s sky was ablaze with %d %s, the perfect day for a surrealist date!", "purple", 3, "moons");
    
    printf("\nYour Surrealist Date is:\n%s\n", surrealistDate);
}

int main() {
    printIntro();
    
    while(1) {  
        printInstructions();
        char naturalDate[100];
        fgets(naturalDate, 100, stdin);

        if(strlen(naturalDate) <= 1) {
            printf("Please enter a valid date.\n\n");
        } else {
            char* nlPointer = strchr(naturalDate, '\n');
            if(nlPointer != NULL) {
                *nlPointer = '\0';
            }
            convertDate(naturalDate);
            break;
        }
    }
    return 0;
}