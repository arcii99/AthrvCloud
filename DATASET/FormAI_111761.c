//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: beginner-friendly
#include<stdio.h>

void main(){

    char str[1000], c;
    int i, j, k;

    printf("Enter the text you want to convert to ASCII art:\n");
    scanf("%[^\n]s", str);

    // Converting to uppercase
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }

    // Printing ASCII art of the text
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            printf("\n\n");
        }
        else{
            c = str[i];
            for(j = 1; j <= 5; j++){
                for(k = 1; k <= 5; k++){
                    if((j == 1 && k == 1) || (j == 1 && k == 5) || (j == 3 && k == 3) || (j == 5 && k == 1) || (j == 5 && k == 5)){
                        printf(" ");
                    }
                    else{
                        printf("%c", c);
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}