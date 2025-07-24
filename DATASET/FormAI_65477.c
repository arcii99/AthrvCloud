//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>
#include <ctype.h>

void textToAscii(char* text){
    int i, j, k, n;
    char c;
    for(i=0; text[i]!='\0'; i++){
        c = toupper(text[i]);
        n = c - 'A';
        for(j=0; j<=n; j++){
            for(k=0; k<=j; k++)
                printf("%c", c);
            printf("\n");
        }
        for(j=n-1; j>=0; j--){
            for(k=0; k<=j; k++)
                printf("%c", c);
            printf("\n");
        }
    }
}

int main(){
    char input[1000];
    printf("Enter some text: ");
    fgets(input, 1000, stdin);
    textToAscii(input);
    return 0;
}