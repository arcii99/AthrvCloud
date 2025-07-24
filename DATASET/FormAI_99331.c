//FormAI DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include<stdio.h>
#include<string.h>

// Function to parse the input string
int parse_string(char *input_string) {
    // Variables to keep track of the current state
    int state = 0;
    int previous_state = 0;
    // Parse the string character-by-character
    for(int i = 0; i < strlen(input_string); i++) {
        char c = input_string[i];
        switch(state) {
            // Initial state
            case 0:
                if(c == 'i') {
                    previous_state = state;
                    state = 1;
                } else if(c == ' ') {
                    // Ignore whitespace
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'i'
            case 1:
                if(c == 'f') {
                    previous_state = state;
                    state = 2;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'if'
            case 2:
                if(c == ' ') {
                    previous_state = state;
                    state = 3;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering the whitespace after 'if'
            case 3:
                if(c == '(') {
                    previous_state = state;
                    state = 4;
                } else if(c == ' ') {
                    // Ignore whitespace
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering '('
            case 4:
                if(c == ' ') {
                    // Ignore whitespace
                } else if(c == 'i') {
                    previous_state = state;
                    state = 5;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'i' after '('
            case 5:
                if(c == 's') {
                    previous_state = state;
                    state = 6;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'is' after '('
            case 6:
                if(c == 'o') {
                    previous_state = state;
                    state = 7;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'iso' after '('
            case 7:
                if(c == 'd') {
                    previous_state = state;
                    state = 8;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'isod' after '('
            case 8:
                if(c == 'i') {
                    previous_state = state;
                    state = 9;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering 'isodi' after '('
            case 9:
                if(c == 'g') {
                    previous_state = state;
                    state = 10;
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering the complete identifier 'isodigit' after '('
            case 10:
                if(c == ')') {
                    previous_state = state;
                    state = 11;
                } else if(c == ' ') {
                    // Ignore whitespace
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
            // State after encountering ')' after the complete expression
            case 11:
                if(c == ' ') {
                    // Ignore whitespace
                } else {
                    printf("Syntax error at position %d\n", i);
                    return 0;
                }
                break;
        }
    }
    // Check if the final state is valid
    if(state == 11) {
        printf("Valid input string!\n");
        return 1;
    } else {
        printf("Syntax error at end of input string!\n");
        return 0;
    }
}

int main() {
    char input_string[50];
    printf("Enter a C syntax : ");
    scanf("%[^\n]", input_string);
    parse_string(input_string);
    return 0;
}