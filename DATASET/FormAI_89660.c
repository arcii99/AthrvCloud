//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include<stdio.h>
#include<string.h>

// function to print a character in ASCII art
void printChar(char c){
     switch(c){
         case 'A': 
              printf("  /\\    \n /  \\   \n/    \\  \n/------\\\n/        \\\n\n");
              break;
         case 'B':
              printf("/------\\\n| |_/   \n| | \\   \n| |_/   \n|___/   \n\n");
              break;  
         case 'C':
              printf(" /------\\\n/        \n/        \n/        \n \\------/\n\n");
              break;
         // add more cases for other characters
         // ...
         default:
              printf("Invalid character!\n");
     } 
}

int main(){
    char text[50];
    printf("Enter a string: ");
    scanf("%s", text);
    int len = strlen(text);
    printf("ASCII art for the entered text:\n");
    for(int i=0; i<len; i++){
        printChar(text[i]);
    }
    return 0;
}