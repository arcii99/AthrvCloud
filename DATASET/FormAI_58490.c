//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    //initialize variables
    char text[100];
    int i, j;
    
    //ask user for input
    printf("Enter text in Cat language: ");
    scanf("%[^\n]", text);
    
    //convert to regular English
    for(i=0,j=0;i<strlen(text);i++) {
        if(text[i] == 'M') {
            if(text[i+1] == 'e' && text[i+2] == 'o' && text[i+3] == 'w') {
                printf("Hello ");
                i+=3;
            }
            else if(text[i+1] == 'o' && text[i+2] == 'w') {
                printf("Yes ");
                i+=2;
            }
            else if(text[i+1] == 'e' && text[i+2] == 'r' && text[i+3] == 'r' && text[i+4] == 'r' && text[i+5] == 'r') {
                printf("No ");
                i+=5;
            }
            else {
                printf("%c", text[i]);
            }
            j++;
        }
        else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}