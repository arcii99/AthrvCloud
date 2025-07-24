//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

/* Function to remove unwanted characters */
void sanitize_input(char* input_string){
    char new_string[MAX_STRING_LENGTH];
    int index = 0;
    
    for(int i = 0; input_string[i] != '\0'; i++){
        if(input_string[i] >= 'a' && input_string[i] <= 'z'){
            new_string[index] = input_string[i];
            index++;
        }else if(input_string[i] >= 'A' && input_string[i] <= 'Z'){
            new_string[index] = input_string[i] + 32;
            index++;
        }else if(input_string[i] >= '0' && input_string[i] <= '9'){
            new_string[index] = input_string[i];
            index++;
        }else{
            /* ignore */
        }
    }
    new_string[index] = '\0';   // Add end of string character
    
    /* Copy sanitized input string back to input_string */
    strcpy(input_string, new_string);
}

int main(){
    char input[MAX_STRING_LENGTH];
    printf("Enter input string: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    
    // Print original input
    printf("Original input: %s\n", input);
    
    // Sanitize input
    sanitize_input(input);
    
    // Print sanitized input
    printf("Sanitized input: %s\n", input);
    
    return 0;
}