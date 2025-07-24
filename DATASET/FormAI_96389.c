//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAsciiArt(char* text);

int main(){
    char input[100];

    printf("Enter text to convert to ASCII art: ");
    fgets(input, 100, stdin);

    printAsciiArt(input);
    return 0;
}

void printAsciiArt(char* text){
    int length = strlen(text);
    printf("\n");

    for (int i = 0; i < length; i++){
        if(text[i] == ' '){
            printf("            ");
        }else if(text[i] == '\n'){
            printf("     \n");
        }else if(text[i] == '\r'){ //to handle DOS-formatted file
            continue;
        }else if(text[i] >= 'A' && text[i] <= 'Z'){
            printf(" _   _\n");
            printf("| | | |\n");
            printf("| |_| | __ _ %c\n", text[i]);
            printf("|  _  |/ _` |\n");
            printf("| | | | (_| |\n");
            printf("|_| |_|\__,_|\n");
        }else if(text[i] >= 'a' && text[i] <= 'z'){
            printf(" _   _\n");
            printf("| | | |\n");
            printf("| |_| |/ _` | %c\n", text[i]);
            printf("|  _  | (_| |\n");
            printf("|_| |_|\__,_|\n");
        }else if(text[i] >= '0' && text[i] <= '9'){
            printf("  ___\n");
            printf(" / _ \\\n");
            printf("| | | | %c\n", text[i]);
            printf("| |_| |\n");
            printf(" \\___/ \n");
        }else{
            printf("Character not supported: %c\n", text[i]);
            continue;
        }
        printf("\n");
    }
}