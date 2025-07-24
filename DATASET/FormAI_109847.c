//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <string.h>
#define ROWS 9
#define COLUMNS 6

/* Configurable ASCII art style */
char asciiArt[ROWS][COLUMNS] = {
    {' ', '_', '_', '_', ' ', ' '},
    {'|', ' ', ' ', ' ', '|', ' '},
    {'|', ' ', ' ', ' ', '|', ' '},
    {'|', ' ', ' ', '_', '|', '_'},
    {'|', ' ', ' ', ' ', '|', ' '},
    {'|', ' ', ' ', ' ', '|', ' '},
    {'|', '_', '_', '_', '|', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}
};

void printAsciiArt(char* text);

int main(){
    char* text = "HELLO";
    printAsciiArt(text);
    return 0;
}

/* Function to print ASCII art of given text in configurable style */
void printAsciiArt(char* text){
    int len = strlen(text);
    int i, j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<len*COLUMNS; j++){
            if(j%COLUMNS == 0){
                printf("%c", asciiArt[i][j/COLUMNS]);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}