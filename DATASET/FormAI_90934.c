//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
/* We start with a tale of two inputs,
   One pure and innocent, the other corrupt and vexed
   Our hero, the User Input Sanitizer, must set things right,
   And keep our program safe from any fright. */

#include <stdio.h>
#include <ctype.h> // For the isalnum() function

// Function to sanitize the user input
void sanitize_input(char *input_string){
    int i = 0;
    while(input_string[i]){
        // Replace any non-alphanumeric characters with a space
        if(!isalnum(input_string[i])) {
            input_string[i] = ' ';
        }

        // Convert any uppercase characters to lowercase
        input_string[i] = tolower(input_string[i]);

        i++;
    }
}

int main(){
    char user_input[100]; // Assume maximum input length is 100 characters

    printf("Good morrow, fair user. Pray tell, what be thy name?\n");
    scanf("%s", user_input); // Get user input

    printf("Ah, %s, a sweet name indeed. But, I must ask, doth thy name contain any unsavory characters?\n", user_input);

    sanitize_input(user_input); // Sanitize the user input

    printf("Fear not, fair %s, thy name is now pure and sanitized. Thou may proceed with our program without a care.\n", user_input);

    return 0;
}