//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>

#define MAX_CHARS 80
#define MAX_ROWS 10

void printArt(char art[MAX_ROWS][MAX_CHARS], int rows){
    for(int i = 0; i < rows; i++){
        printf("%s\n", art[i]);
    }
}

void generateArt(char *text, char art[MAX_ROWS][MAX_CHARS], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; text[j] != '\0'; j++){
            if(text[j] == ' '){
                art[i][j] = ' ';
            }else{
                art[i][j] = '-';
            }
        }
    }
}

int main(){
    char text[MAX_CHARS];
    printf("Enter text (max 80 chars): ");
    fgets(text, MAX_CHARS, stdin);
    
    char art[MAX_ROWS][MAX_CHARS];
    generateArt(text, art, MAX_ROWS);

    printf("\nASCII Art:\n");
    printArt(art, MAX_ROWS);

    return 0;
}