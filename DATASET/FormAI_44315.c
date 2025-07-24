//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <string.h>

void sanitize_url(char* url) {
    int i, j, len;
    char temp[1000];
    len = strlen(url);
    j = 0;
    for (i = 0; i < len; i++) {
        if (url[i] == '<' || url[i] == '>' || url[i] == '(' || url[i] == ')' || url[i] == '\'' || url[i] == '\"' || url[i] == '\\' || url[i] == ';' || url[i] == '#' || url[i] == '&' || url[i] == '+' || url[i] == '%' || url[i] == '@' || url[i] == '$') {
            // skip these characters
        } else {
            temp[j] = url[i];
            j++;
        }
    }
    temp[j] = '\0'; // set null terminator
    strcpy(url, temp); // copy sanitized string back into original string
}

int main() {
    char url[1000];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}