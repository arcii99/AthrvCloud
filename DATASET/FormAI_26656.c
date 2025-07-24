//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include<stdio.h>

int main(){
    char text[100];
    int i, j, k;

    //Get input text from user
    printf("Enter text to convert to ASCII Art:\n");
    scanf("%s",text);

    //Loop through each character in the input text
    for(i=0; text[i] != '\0'; i++){
        //Print the ASCII representation of the character in ASCII Art format
        for(j=0; j < 8; j++){
            for(k=0; k < 8; k++){
                if((text[i] >> k) & 0x01){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}