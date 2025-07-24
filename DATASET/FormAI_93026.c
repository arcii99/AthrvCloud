//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char html[1000]; // declare string variable for input
    char beautifiedHtml[1000] = ""; // declare string variable for output
    int indentLevel = 0; // start indentation level at 0
    
    printf("Enter your HTML code:\n"); // prompt user for input
    fgets(html, 1000, stdin); // get input from user and store in html variable
    
    char *tok = strtok(html, "<>"); // tokenize html string by angle brackets
    
    while (tok != NULL) { // loop through tokens
        if (strlen(tok) > 0) { // make sure token is not an empty string
            if (tok[0] == '/') { // if closing tag
                indentLevel--; // decrease indent level
                strcat(beautifiedHtml, "\n"); // add newline character to output
            }
            for (int i = 0; i < indentLevel; i++) { // for loop to indent output based on current indent level
                strcat(beautifiedHtml, "\t"); // add a tab character to output for each indentation level
            }
            if (tok[0] != '/') { // if opening tag
                strcat(beautifiedHtml, "\n"); // add newline character to output
                for (int i = 0; i < indentLevel; i++) { // for loop to indent output based on current indent level
                    strcat(beautifiedHtml, "\t"); // add a tab character to output for each indentation level
                }
                indentLevel++; // increase indent level
            }
            strcat(beautifiedHtml, "<"); // add opening angle bracket to output
            strcat(beautifiedHtml, tok); // add token to output
            if (tok[0] != '/') { // if opening tag
                strcat(beautifiedHtml, ">"); // add closing angle bracket to output
            }
        }
        tok = strtok(NULL, "<>"); // get next token
    }
    
    printf("\nYour beautified HTML code is:\n%s", beautifiedHtml); // output beautified HTML code
    
    return 0; // end program
}