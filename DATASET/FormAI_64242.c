//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include<stdio.h>
#include<string.h>

/* Function to reverse a string */
void reverse_string(char* str) {
   int len = strlen(str), i; // Declare variables
 
   /* Loop through half of string and swap chars */
   for(i=0;i<len/2;i++) {
       char temp = str[i];
       str[i] = str[len-i-1];
       str[len-i-1] = temp;
   }
   printf("Your reversed string is: %s\n", str);
}

/* Function to add text to a string */
void add_text(char* str) {
    int len = strlen(str); // Declare variable
    strncat(str, ", but wait there's more!", 22); // Add text to string
    printf("Your modified string is: %s\n", str);
}

int main() {
    char str[100]; // Declare variable
    printf("Hi there! Give me a string to manipulate: ");
 
    fgets(str, 100, stdin); // Input string
 
    /* Remove newline character from input */
    if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
        str[strlen(str) - 1] = '\0';

    printf("Your original string is: %s\n", str);

    /* Reverse the input string */
    reverse_string(str);

    /* Add text to the input string */
    add_text(str);

    printf("Thanks for letting me manipulate your string, have a great day!\n");
    return 0;
}