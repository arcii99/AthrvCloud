//FormAI DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include <stdio.h>

int main() {
    /* User Input */
    printf("Enter a C Program:\n");
    char code[1000];
    fgets(code, 1000, stdin);

    /* Syntax Parsing */
    int line_count = 1;
    int curly_bracket_count = 0;
    int round_bracket_count = 0;
    int square_bracket_count = 0;
    int angle_bracket_count = 0;
    int single_quote_count = 0;
    int double_quote_count = 0;
    for(int i=0; i<strlen(code); i++) {
        char current_char = code[i];

        /* Counting Line Numbers */
        if(current_char == '\n') {
            line_count++;
        }

        /* Counting Brackets */
        if(current_char == '{') {
            curly_bracket_count++;
        } else if(current_char == '}') {
            curly_bracket_count--;
            if(curly_bracket_count < 0) {
                printf("Error: Found extra closing curly bracket on line %d\n", line_count);
                return 0;
            }
        } else if(current_char == '(') {
            round_bracket_count++;
        } else if(current_char == ')') {
            round_bracket_count--;
            if(round_bracket_count < 0) {
                printf("Error: Found extra closing round bracket on line %d\n", line_count);
                return 0;
            }
        } else if(current_char == '[') {
            square_bracket_count++;
        } else if(current_char == ']') {
            square_bracket_count--;
            if(square_bracket_count < 0) {
                printf("Error: Found extra closing square bracket on line %d\n", line_count);
                return 0;
            }
        } else if(current_char == '<') {
            angle_bracket_count++;
        } else if(current_char == '>') {
            angle_bracket_count--;
            if(angle_bracket_count < 0) {
                printf("Error: Found extra closing angle bracket on line %d\n", line_count);
                return 0;
            }
        }

        /* Counting Quotes */
        if(current_char == '\'') {
            if(single_quote_count == 0) {
                single_quote_count++;
            } else {
                single_quote_count--;
            }
        } else if(current_char == '\"') {
            if(double_quote_count == 0) {
                double_quote_count++;
            } else {
                double_quote_count--;
            }
        }
    }

    /* Checking Bracket Mismatch */
    if(curly_bracket_count != 0) {
        printf("Error: Missing %d closing curly brackets\n", abs(curly_bracket_count));
        return 0;
    } else if(round_bracket_count != 0) {
        printf("Error: Missing %d closing round brackets\n", abs(round_bracket_count));
        return 0;
    } else if(square_bracket_count != 0) {
        printf("Error: Missing %d closing square brackets\n", abs(square_bracket_count));
        return 0;
    } else if(angle_bracket_count != 0) {
        printf("Error: Missing %d closing angle brackets\n", abs(angle_bracket_count));
        return 0;
    }

    /* Checking Quote Mismatch */
    if(single_quote_count != 0) {
        printf("Error: Missing %d closing single quotes\n", abs(single_quote_count));
        return 0;
    } else if(double_quote_count != 0) {
        printf("Error: Missing %d closing double quotes\n", abs(double_quote_count));
        return 0;
    }

    /* If no errors found, print success message */
    printf("Syntax check for C Program successful!\n");

    return 0;
}