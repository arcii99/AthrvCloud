//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include<stdio.h>

int main() {

    char c[1000];

    printf("Enter text to convert to ASCII art:\n");
    fgets(c, sizeof(c), stdin);

    for(int i=0; c[i] != '\0'; i++) {
        if(c[i] == ' ')
            printf("      ");
        else if(c[i] == '\n')
            continue;
        else
            printf(" _%c_ ", c[i]);
    }

    printf("\n");

    return 0;
}