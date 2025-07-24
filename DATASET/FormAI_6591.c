//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(){
    char input_string[100];
    scanf("%s", input_string);
    int input_length = strlen(input_string);
    char new_string[100];
    int index = 0;

    for(int i=0; i<input_length; i++){
        if(input_string[i] == ' '){
            new_string[index++] = '-';
        }
        else{
            new_string[index++] = tolower(input_string[i]);
        }
    }

    new_string[index] = '\0';

    printf("Your new string is: %s\n\n", new_string);
    printf("Medieval Style:\n");

    for(int i=0; i<index; i++){
        if(new_string[i] == '-'){
            printf(".");
        }
        else if(i%2 == 0){
            printf("%c",toupper(new_string[i]));
        }
        else{
            printf("%c",new_string[i]);
        }
    }

    printf("\n\n");
    return 0;
}