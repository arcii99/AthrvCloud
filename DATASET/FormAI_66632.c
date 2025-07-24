//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include<stdio.h>
#include<string.h>

void sanitizer(char *url, char *new_url) {
    int i, j = 0;
    int len = strlen(url);

    for(i = 0; i < len; i++) {
        if(url[i] == ' ') {
            new_url[j++] = '%';
            new_url[j++] = '2';
            new_url[j++] = '0';
        } 
        else if(url[i] == '\\') {
            new_url[j++] = '%';
            new_url[j++] = '5';
            new_url[j++] = 'C';
        } 
        else if(url[i] == '/') {
            new_url[j++] = '%';
            new_url[j++] = '2';
            new_url[j++] = 'F';
        }
        else {
            new_url[j++] = url[i];
        }
    }
    new_url[j] = '\0';
}

int main() {
    char url[100] = "https://google.com/search?q=C URL Sanitizer Example";
    char new_url[100];

    sanitizer(url, new_url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", new_url);

    return 0;
}