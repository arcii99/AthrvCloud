//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert character to ascii art
void charToASCII(char ch){
    //ASCII art for capital letters
    if(ch>='A' && ch<='Z'){
        printf("   / _____ \\ \n");
        printf("  / /     \\ \\ \n");
        printf(" / /_______\\ \\ \n");
        printf("/___________\\\n\n");
    }
    //ASCII art for small letters
    else if(ch>='a' && ch<='z'){
        printf("   ___________ \n");
        printf(" /           \\\n");
        printf("/_____________\\\n");
    }
    //ASCII art for numerical digits
    else if(ch>='0' && ch<='9'){
        printf("  ___ \n");
        printf(" /   \\\n");
        printf("/_____\\\n\n");
    }
    //other ASCII art symbols
    else{
        printf("\n");
    }
}

int main(){
    char text[100];
    int len, i;
    printf("Enter a text to convert to ASCII art:\n");
    fgets(text, sizeof(text), stdin);
    len=strlen(text);
    printf("\n");

    for(i=0;i<len;i++){
        charToASCII(text[i]);
    }

    return 0;
}