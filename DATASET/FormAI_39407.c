//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 1000

int main(){
    char input_url[MAX_URL_LENGTH], output_url[MAX_URL_LENGTH];
    printf("Hello! I am the happy URL sanitizer bot!\n");
    printf("Please enter a URL to be sanitized: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);

    int i, j=0;
    for(i=0; i<strlen(input_url); i++) {
        if (input_url[i] == ' ') {
            output_url[j++] = '%';
            output_url[j++] = '2';
            output_url[j++] = '0';
        } else if (input_url[i] == '<' || input_url[i] == '>' || input_url[i] == '"' || input_url[i] == '\'') {
            continue;
        } else {
            output_url[j++] = input_url[i];
        }
    }
    output_url[j] = '\0';
    printf("Your sanitized URL is: %s\n", output_url);
    printf("Hurray! Your URL is now safe to use!\n");
    return 0;
}