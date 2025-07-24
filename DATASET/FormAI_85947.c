//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100]; 

    printf("Enter some text to generate ASCII art: ");
    scanf("%s", input);

    int i, j; 

    for (i=0; input[i]!='\0'; i++) {
        printf("+");
        for (j=0; j<5; j++) {
            printf("-");
        }
        printf("+ ");
    }
    printf("\n");

    for (i=0; input[i]!='\0'; i++) {
        printf("|    %c    ", input[i]);
    }
    printf("|\n");

    for (i=0; input[i]!='\0'; i++) {
        printf("+");
        for (j=0; j<5; j++) {
            printf("-");
        }
        printf("+ ");
    }
    printf("\n");

    return 0;
}