//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

//sanitize function
void sanitize(char* url) {
    regex_t regStruct;
    int regResult;
    char* pattern = "^https?://[a-zA-Z0-9.]+.[a-zA-Z]{2,3}/?.*$";

    //compiling the regular expression
    regResult = regcomp(&regStruct, pattern, REG_EXTENDED);

    if (regResult != 0) {
        printf("Could not compile regular expression\n");
        exit(1);
    }

    size_t nMatch = 1;
    regmatch_t match[nMatch];

    //searching the regular expression in the string
    regResult = regexec(&regStruct, url, nMatch, match, 0);

    if (regResult == REG_NOMATCH) {
        printf("Not a valid URL\n");
        exit(1);
    }
    else if (regResult != 0) {
        printf("Could not search for regular expression\n");
        exit(1);
    }

    //freeing up the memory
    regfree(&regStruct);
}

int main() {
    char url[1000];
    printf("Enter the url: ");
    fgets(url, sizeof(url), stdin);

    //removing the newline character
    url[strcspn(url, "\n")] = 0;

    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}