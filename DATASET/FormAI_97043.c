//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    char url[1000];
    printf("Enter URL: ");
    scanf("%s", url);
    
    int i, j = 0;
    char cleaned_url[1000];
    for (i = 0; i < strlen(url); i++) {
        if (url[i] == ' ') {
            cleaned_url[j++] = '%';
            cleaned_url[j++] = '2';
            cleaned_url[j++] = '0';
        } else if (url[i] == '+') {
            cleaned_url[j++] = '%';
            cleaned_url[j++] = '2';
            cleaned_url[j++] = 'B';
        } else {
            cleaned_url[j++] = url[i];
        }
    }
    cleaned_url[j] = '\0'; 
    
    printf("Cleaned URL: %s", cleaned_url);
    
    return 0;
}