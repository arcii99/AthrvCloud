//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <string.h>

int main(){

    char url[1024];
    printf("Enter URL to sanitize: ");
    scanf("%s", url);

    char sanitized_url[1024];
    int j = 0;
    for(int i = 0; i < strlen(url); i++){
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '/'){

            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';

    printf("Sanitized URL: %s", sanitized_url);
    return 0;
}