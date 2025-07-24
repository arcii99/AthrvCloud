//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int n, count = 0;

    printf("Enter some text: ");
    fgets(text, 100, stdin);

    printf("Enter the size of the string to extract: ");
    scanf("%d", &n);

    printf("The %d characters long substring(s) in the text is/are: \n", n);
    for (int i = 0; i <= strlen(text) - n; i++) {
        char substring[100];
        strncpy(substring, text+i, n);
        substring[n] = '\0';
        printf("%s\n", substring);
        count++;
    }

    printf("Total number of %d characters long substring(s) is: %d", n, count);

    return 0;
}