//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include<stdio.h>

int main() {
    char input[100];
    printf("Enter the text to convert to ASCII art: ");
    scanf("%[^\n]", input);

    printf("+---------------------------------------+\n");
    printf("|                 _         _           |\n");
    printf("|      __ _  ___| |_      (_) ___      |\n");
    printf("|     / _` |/ __| __\\ __ _| |/ __|     |\n");
    printf("|    | (_| | (__| || (_| | | (__      |\n");
    printf("|     \\__,_|\\___|\\__\\__,_|_|\\___|     |\n");
    printf("+---------------------------------------+\n");

    printf("Here's the fancy ASCII art for the text input:\n");
    printf("+");
    for(int i=0;i<(int)(strlen(input)+2);i++) { printf("-"); }
    printf("+\n");

    for(int i=0;i<strlen(input);i++) {
        printf("| %c |", input[i]);
        printf("\n");
    }

    printf("+");
    for(int i=0;i<(int)(strlen(input)+2);i++) { printf("-"); }
    printf("+\n");

    return 0;
}