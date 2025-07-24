//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include<stdio.h>
#include<string.h>

#define MAX_CHARS 500

//Function to convert ASCII value of a character to binary
char* toBinary(int num){
    char *binary = malloc(sizeof(char)*8);
    int mask = 128, i;
    for(i=0; i<8; i++){
        binary[i] = (num & mask)? '1' : '0';
        mask >>= 1;
    }
    binary[i] = '\0';
    return binary;
}

//Function to convert a string to ASCII art
void toASCIIArt(char* text){
    int len = strlen(text), i, j, k;
    char binary[MAX_CHARS][8];
    for(i=0; i<len; i++){
        strcpy(binary[i], toBinary(text[i]));
    }

    //Printing the ASCII art
    for(i=0; i<8; i++){
        for(j=0; j<len; j++){
            for(k=0; k<8; k++){
                printf("%c", binary[j][k]=='1'? '#' :' ');
            }
            printf("  ");
        }
        printf("\n");
    }
}

int main(){
    char text[MAX_CHARS];
    printf("Enter the text to be converted to ASCII art:\n");
    fgets(text, MAX_CHARS, stdin);
    printf("The ASCII art representation of the text is:\n");
    toASCIIArt(text);
    return 0; 
}