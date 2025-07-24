//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>

void printChar(char c){
    char asciiArt[8][5] = {
        "  #  ",
        " # # ",
        "#   #",
        "#####",
        "#   #",
        "#   #",
        "#   #",
        "     "
    };
    for(int i=0; i<8; i++){
        for(int j=0; j<5; j++){
            if(asciiArt[i][j] == '#'){
                printf("%c", c);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    char inputChar;
    printf("Enter a character: ");
    scanf("%c", &inputChar);
    printf("ASCII art:\n");
    printChar(inputChar);
    return 0;
}