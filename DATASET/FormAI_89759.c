//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[100];
    char output[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    int input_length = strlen(input);
    int output_length = 0;
    for(int i = 0; i < input_length; i++){
        if(input[i] == ' '){
            output[output_length] = input[i];
            output_length++;
            continue;
        }
        if((input[i] >= 'a' && input[i] <= 'm') || (input[i] >= 'A' && input[i] <= 'M')){
            output[output_length] = input[i] + 13;
        }
        else{
            output[output_length] = input[i] - 13;
        }
        output_length++;
    }
    output[output_length] = '\0';
    printf("Rot13 Transform: %s", output);
    return 0;
}