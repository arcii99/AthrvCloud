//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include<stdio.h>
#include<string.h>

int main() {
    char url[100], sanitized[100];
    int i, j;

    printf("Enter a URL: ");
    scanf("%s", url);

    for(i=0,j=0;i<strlen(url);i++) {
        if((url[i]>='a' && url[i]<='z') || (url[i]>='A' && url[i]<='Z') || (url[i]>='0' && url[i]<='9') || url[i]=='.' || url[i]=='-' || url[i]=='/' || url[i]==':') {
            sanitized[j] = url[i];
            j++;
        }
    }
    sanitized[j] = '\0';

    printf("Sanitized URL: %s\n", sanitized);
    return 0;
}