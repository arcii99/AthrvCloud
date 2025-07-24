//FormAI DATASET v1.0 Category: Syntax parsing ; Style: genious
#include<stdio.h>
#include<stdlib.h>

// custom structure to represent a syntax rule
typedef struct {
    char *name; // name of the rule
    char **keywords; // keywords that form the rule
    int num_keywords; // number of keywords in the rule
} SyntaxRule;

// function to parse a line of code and return the matched syntax rule
// returns null if no matching rule
SyntaxRule* parse_line(char *line, SyntaxRule *syntax_rules, int num_rules) {
    for(int i=0; i<num_rules; i++) {
        SyntaxRule *rule = &syntax_rules[i];
        int matched = 1;
        // check if each keyword in the rule is present in the line
        for(int j=0; j<rule->num_keywords; j++) {
            char *keyword = rule->keywords[j];
            if(strstr(line, keyword) == NULL) { 
                matched = 0; 
                break; 
            }
        }
        if(matched == 1) { return rule; } // return the matched syntax rule
    }
    return NULL; // no matching rule found
}

int main() {
    // define syntax rules
    SyntaxRule syntax_rules[] = {
        {"for loop", (char*[]){"for", "(", ")", "{"}, 4},
        {"if statement", (char*[]){"if", "(", ")", "{"}, 4},
        {"function declaration", (char*[]){"void", "(", ")", "{"}, 4},
        {"return statement", (char*[]){"return", ";"}, 2},
        {"printf statement", (char*[]){"printf", "(", ")", ";"}, 4}
    };
    int num_rules = sizeof(syntax_rules)/sizeof(syntax_rules[0]);
    
    // parse each line of code
    char line[100];
    while(fgets(line, sizeof line, stdin)) {
        SyntaxRule *matched_rule = parse_line(line, syntax_rules, num_rules);
        if(matched_rule != NULL) {
            printf("Matched syntax rule: %s\n", matched_rule->name);
        }
    }

    return 0;
}