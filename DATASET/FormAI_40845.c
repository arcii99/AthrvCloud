//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print ASCII art based on given text
void print_art(char* text){
    int i, j;
    int len = strlen(text);
    int art_len = 9*(len+2);
    char* art = (char*)malloc(art_len*sizeof(char));
    
    // Make top border of ASCII art
    for(i=0; i<art_len; i++){
        if(i%9 == 0 || i%9 == 8) art[i] = '+';
        else art[i] = '-';
    }
    art[art_len] = '\0';
    printf("%s\n", art);
    
    // Make middle part of ASCII art
    for(i=0; i<5; i++){
        for(j=0; j<art_len; j++){
            if(j%9 == 0 || j%9 == 8) art[j] = '|';
            else if(j%9 == 4) art[j] = *text++;
            else art[j] = ' ';
        }
        art[art_len] = '\0';
        printf("%s\n", art);
    }
    
    // Make bottom border of ASCII art
    for(i=0; i<art_len; i++){
        if(i%9 == 0 || i%9 == 8) art[i] = '+';
        else art[i] = '-';
    }
    art[art_len] = '\0';
    printf("%s\n", art);
}

int main(){
    char input[50];
    printf("Enter text: ");
    fgets(input, 50, stdin);
    strtok(input, "\n");
    print_art(input);
    return 0;
}