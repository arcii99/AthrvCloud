//FormAI DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100]; // Declare input string
    char output_string[100]; // Declare output string
    int string_length, i, j = 0, k = 0; // Declare variables
    
    printf("Enter a string to manipulate: ");
    scanf("%s", input_string); // Take user input
    
    string_length = strlen(input_string); // Find length of input string
    
    // Copy every alternate character to output string
    for(i=0;i<string_length;i++){
        if(i%2==0){
            output_string[j] = input_string[i];
            j++;
        }
    }
    output_string[j] = '\0'; // Add null character at the end of output string
    
    printf("Output string: %s\n", output_string); // Display the output string
    
    // Capitalize every alternate character in output string
    for(i=0;i<=j;i++){
        // Check if the character is an alphabet and is at an odd index
        if(i%2==1 && (output_string[i]>='a' && output_string[i]<='z')){
            output_string[i] = output_string[i]-32; // Capitalize the character
        }
    }
    
    printf("Manipulated string: %s\n", output_string); // Display the manipulated string
    
    // Reverse the manipulated string
    for(i=0;i<=j/2;i++){
        char temp = output_string[i]; // Store character in temporary variable
        output_string[i] = output_string[j-i]; // Replace character with its opposite character
        output_string[j-i] = temp; // Replace opposite character with stored character
    }
    
    printf("Reversed string: %s\n", output_string); // Display the reversed string
    
    return 0;
}