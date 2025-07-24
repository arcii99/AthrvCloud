//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include<stdio.h>

void main(){
    char message[100];
    printf("Enter a message to convert to ASCII art: ");
    fgets(message, 100, stdin);
    printf("\nASCII Art:\n\n");

    int i,j;
    for(i=0; i<strlen(message); i++){
        if(message[i]==' '){
            printf("      ");
        }else{
            for(j = 0; j < 7; j++){
                printf("%c",message[i]);
            }
        }
        printf("\n");
    }
}