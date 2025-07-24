//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>

int main() {
    int rows, cols;
    char userIn[50];
    char toPrint[10000];
    printf("Welcome to the ASCII Art Generator!\n");
    printf("Please enter your favorite word/phrase: ");
    scanf("%s", userIn);
    printf("\n");
    printf("Now, please enter the number of rows: ");
    scanf("%d", &rows);
    printf("\n");
    printf("Finally, please enter the number of columns: ");
    scanf("%d", &cols);
    printf("\n");
    printf("Computing Art...");
    int index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (userIn[index] == '\0') {
                index = 0;
            }
            toPrint[i * cols + j] = userIn[index];
            index++;
        }
    }
    printf("\n");
    printf("Art Generated!\n");
    printf("\n");
    printf("Here is your ASCII Art:\n");
    printf("\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c", toPrint[i * cols + j]);
        }
        printf("\n");
    }
    return 0;
}