//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

// function to translate C Cat language into English
void translate(char *input) {
    char output[1000] = "";
    int count = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == 'm' && input[i+1] == 'e' && input[i+2] == 'o') {
            output[count] = 'c';
            output[count+1] = 'a';
            output[count+2] = 't';
            count += 3; // skip over the 'm', 'e', and 'o' characters
            i += 2;
        } else if (input[i] == 'p' && input[i+1] == 'u' && input[i+2] == 'r' && input[i+3] == 'r') {
            output[count] = 'p';
            output[count+1] = 'u';
            output[count+2] = 'r';
            output[count+3] = 'r';
            count += 4; // skip over the 'p', 'u', 'r', and 'r' characters
            i += 3;
        } else if (input[i] == 'h' && input[i+1] == 'i' && input[i+2] == 's' && input[i+3] == 's') {
            output[count] = 'h';
            output[count+1] = 'i';
            output[count+2] = 's';
            output[count+3] = 's';
            count += 4; // skip over the 'h', 'i', 's', and 's' characters
            i += 3;
        } else {
            output[count] = input[i];
            count++;
        }
    }
    printf("%s\n", output);
}

// main function
int main() {
    // test cases
    char input1[] = "meomeopurrr";
    char input2[] = "hissmeohiss";
    char input3[] = "meomeomeopurr";
    char input4[] = "meohissmeo";
    printf("Input: %s\n", input1);
    printf("Output: ");
    translate(input1);
    printf("Input: %s\n", input2);
    printf("Output: ");
    translate(input2);
    printf("Input: %s\n", input3);
    printf("Output: ");
    translate(input3);
    printf("Input: %s\n", input4);
    printf("Output: ");
    translate(input4);
    return 0;
}