//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void printAsciiArt(char* text);

int main(){
    char text[MAX_LEN];
    printf("Enter your text: ");
    fgets(text, MAX_LEN, stdin);

    printAsciiArt(text);
    
    return 0;
}

void printAsciiArt(char* text){
    int len = strlen(text);
    int i, j;

    // Print top border
    for(i = 1; i <= 10; i++){
        for(j = 0; j < len; j++){
            if((j==0 && i==1) || (j==len-1 && i==1) || (j==0 && i==10) || (j==len-1 && i==10)){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }

    // Print text
    printf("*");
    for(i = 0; i < (len+2); i++){
        printf(" ");
    }
    printf("*\n");
    printf("* %s *\n", text);
    printf("*");
    for(i = 0; i < (len+2); i++){
        printf(" ");
    }
    printf("*\n");

    // Print bottom border
    for(i = 1; i <= 10; i++){
        for(j = 0; j < len; j++){
            if((j==0 && i==1) || (j==len-1 && i==1) || (j==0 && i==10) || (j==len-1 && i==10)){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}