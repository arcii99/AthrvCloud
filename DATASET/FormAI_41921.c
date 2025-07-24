//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char input_string[256];
    char output_string[256];
    int index = 0;
    
    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // remove newline character
    
    // Convert vowels to uppercase and consonants to lowercase
    for(int i=0; i<strlen(input_string); i++) {
        if(input_string[i] == 'a' || input_string[i] == 'e' || input_string[i] == 'i' || input_string[i] == 'o' || input_string[i] == 'u') {
            output_string[index++] = toupper(input_string[i]); // convert to uppercase
        } else if((input_string[i] >= 'a' && input_string[i] <= 'z') || (input_string[i] >= 'A' && input_string[i] <= 'Z')) {
            output_string[index++] = tolower(input_string[i]); // convert to lowercase
        }
    }
    
    output_string[index] = '\0'; // terminate the string after the last character
    
    printf("Output string: %s", output_string);
    
    return 0;
}