//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URL
void sanitize_url(char url[]){
    int i, j;
    char temp[strlen(url)];

    for(i = 0, j = 0; url[i]; ++i){
        if(url[i] == ' '){
            temp[j++] = '%';
            temp[j++] = '2';
            temp[j] = '0';
        }
        else{
            temp[j] = url[i];
        }
        ++j;
    }

    temp[j] = '\0';
    strcpy(url, temp);
}

int main(){
    char url[100];

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0;

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}