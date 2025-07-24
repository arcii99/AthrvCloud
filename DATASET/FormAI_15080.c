//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include<stdio.h>
#include<string.h>

// Function to print ASCII art for the given input text
void printArt(char text[]) {
    int len = strlen(text);
    int i, j;
    
    // Array to store ASCII art
    char art[5][100];

    // Initialize art
    strcpy(art[0], "  /\\_/\\      ____       \n");
    strcpy(art[1], " ( o.o )   /___/\\_\\_    \n");
    strcpy(art[2], "  > ^ <    \\ \\ \\_\\ \\   \n");
    strcpy(art[3], " /_/ \\_\\    \\ \\____/   \n");
    strcpy(art[4], " \n");

    // Print ASCII art for each letter in the input text
    for(i=0; i<len; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            j = text[i] - 'a';
            printf("%s", art[j]);
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            j = text[i] - 'A';
            printf("%s", art[j]);
        }
        else {
            printf("%s", art[4]);
        }
    }
}

int main() {
    char text[100];

    // Get input text from user
    printf("Enter some text: ");
    scanf("%s", text);

    // Print ASCII art for the given text
    printArt(text);

    return 0;
}