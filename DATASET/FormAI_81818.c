//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40

/*Ascii art array*/
char asciiArt[HEIGHT][WIDTH+1];

/*Function to print the ascii art*/
void printAsciiArt(){
    int i,j;
    for(i=0;i<HEIGHT;i++){
        printf("%s\n",asciiArt[i]);
    }
}

/*Function to clear the ascii art*/
void clearAsciiArt(){
    int i,j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            asciiArt[i][j] = ' ';
        }
        asciiArt[i][j] = '\0';
    }
}

/*Function to generate ascii art based on input string*/
void generateAsciiArt(char* inputString){
    int i,j,len;
    len = strlen(inputString);
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            asciiArt[i][j] = (i*i*j*j)%len < 8 ? inputString[(i*i*j*j)%len] : ' ';
        }
        asciiArt[i][j] = '\0';
    }
}

int main(){
    char inputString[100];
    printf("Enter a string to convert to ascii art: ");
    scanf("%[^\n]s",inputString);
    clearAsciiArt();
    generateAsciiArt(inputString);
    printAsciiArt();
    return 0;
}