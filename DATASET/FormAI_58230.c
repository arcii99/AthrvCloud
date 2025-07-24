//FormAI DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LENGTH 100
 
int main(){
    char input[MAX_LENGTH];
    char output[MAX_LENGTH*2]; // Double the length to be safe
    int input_length, output_length = 0;
    char curr_char, prev_char;
    int count = 1, i;
 
    printf("Enter the string to be compressed:\n");
    fgets(input, MAX_LENGTH, stdin);
 
    input_length = strlen(input);
 
    prev_char = input[0];
 
    for(i = 1; i < input_length; i++){
        curr_char = input[i];
 
        if(curr_char == prev_char){
            count++;
        }
        else{
            // Write the previous character and count to the output string
            output[output_length++] = prev_char;
            sprintf(output + output_length, "%d", count);
            output_length = strlen(output);
 
            count = 1;
            prev_char = curr_char;
        }
    }
 
    // Write the last character and count to the output string
    output[output_length++] = prev_char;
    sprintf(output + output_length, "%d", count);
    output_length = strlen(output);
 
    printf("Compressed string: %s\n", output);
 
    return 0;
}