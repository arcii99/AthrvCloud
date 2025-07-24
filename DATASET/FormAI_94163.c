//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char* input = malloc(sizeof(char)*50); //Allocate memory for input
    printf("Enter your input: ");
    scanf("%s",input); //Read input
    int length = strlen(input);
    char* sanitized = malloc(sizeof(char)*(length+1)); //Allocate memory for sanitized input
    int flag = 0; //Variable to check for bad characters

    //Iterate through the input and check for bad characters
    for(int i=0;i<length;i++){
        if(input[i]>='0' && input[i]<='9'){ //Allow digits
            sanitized[i] = input[i];
        }
        else if(input[i]>='a' && input[i]<='z'){ //Allow lowercase letters
            sanitized[i] = input[i];
        }
        else if(input[i]>='A' && input[i]<='Z'){ //Allow uppercase letters
            sanitized[i] = input[i];
        }
        else{ //All other characters are not allowed
            sanitized[i] = ' ';
            flag = 1;
        }
    }

    sanitized[length] = '\0'; //Add null terminator
    if(flag){ //Print warning message if bad characters were found
        printf("Warning: Input contains bad characters. Sanitized input: %s\n",sanitized);
    }
    else{ //Print sanitized input if no bad characters were found
        printf("Sanitized input: %s\n",sanitized);
    }

    free(input); //Free memory
    free(sanitized);

    return 0;
}