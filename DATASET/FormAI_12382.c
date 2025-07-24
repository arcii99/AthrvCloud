//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <string.h>

char *sanitize_url(char *url) {
    char *new_url = malloc(strlen(url) + 1); // allocate memory for new url
    int j = 0; // initialize counter j
    for (int i = 0; url[i] != '\0'; i++) { // loop through each character in url
        if (url[i] == ' ') { // if character is whitespace
            new_url[j++] = '%'; // add % to new url
            new_url[j++] = '2';
            new_url[j++] = '0';
        }
        else if (url[i] == '<' || url[i] == '>' || url[i] == '(' || url[i] == ')' || url[i] == '{' || url[i] == '}' || url[i] == '|' || url[i] == '[' || url[i] == ']' || url[i] == '\\' || url[i] == '^' || url[i] == '`' || url[i] == ';' || url[i] == '\'' || url[i] == '\"' || url[i] == ':' || url[i] == '@' || url[i] == '&' || url[i] == '=' || url[i] == '+' || url[i] == '$' || url[i] == ',' || url[i] == '#' || url[i] == '%' || url[i] == '?' || url[i] == '/' || url[i] == '\\') { // if character is a special character
            new_url[j++] = '%'; // add % to new url
            char c1 = url[i] / 16; // divide character's hex value by 16
            char c2 = url[i] % 16; // get modulo of character's hex value
            if (c1 < 10)
                new_url[j++] = c1 + '0'; // add ASCII value of c1 to new url
            else
                new_url[j++] = c1 - 10 + 'A'; // add ASCII value of c1 to new url
            if (c2 < 10)
                new_url[j++] = c2 + '0'; // add ASCII value of c2 to new url
            else
                new_url[j++] = c2 - 10 + 'A'; // add ASCII value of c2 to new url
        }
        else { // if the character doesn't need to be sanitized
            new_url[j++] = url[i]; // add the character to new url
        }
    }
    new_url[j] = '\0'; // add null character to end of new url
    return new_url; // return the sanitized url
}

int main() {
    char url[100];
    printf("Enter a URL:\n");
    fgets(url, sizeof(url), stdin); // get url input from user
    char *new_url = sanitize_url(url); // sanitize url
    printf("Sanitized URL: %s", new_url); // print sanitized url
    free(new_url); // free memory allocated for new url
    return 0;
}