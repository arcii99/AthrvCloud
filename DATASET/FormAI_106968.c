//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_string(char* str){
    int len = strlen(str);
    char* new_str = (char*)calloc(len + 1, sizeof(char));
    int index = 0;

    // traverse the original string
    for(int i=0; i<len; i++){
        // check if the character is alphanumeric or space
        if(isalnum(str[i]) || isspace(str[i])){
            new_str[index++] = str[i];
        }
    }

    // add null terminator at the end
    new_str[index] = '\0';

    // copy back the sanitized string to original string
    strcpy(str, new_str);

    // free the memory allocated for new_str
    free(new_str);
}

int main(){
    char user_input[100];

    printf("Enter a string:\n");
    fgets(user_input, sizeof(user_input), stdin);

    // trim newline character
    user_input[strcspn(user_input, "\n")] = '\0';

    printf("Original string: %s\n", user_input);

    sanitize_string(user_input);

    printf("Sanitized string: %s\n", user_input);

    return 0;
}