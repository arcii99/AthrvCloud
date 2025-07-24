//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to sanitize the URL
char* sanitizeURL(char* url) {
    int i, j;
    char* newURL = (char*)malloc(strlen(url)*sizeof(char));

    //iterate through every character and only include alphanumeric characters
    for(i = 0, j = 0; i < strlen(url); i++) {
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9'))
            newURL[j++] = url[i];
    }
    newURL[j] = '\0'; //terminate the new string

    return newURL;
}

//main function to test the program
int main() {
    char* url = "https://www.google.com/search?q=c+url+sanitizer+example+program&rlz=1C1GCEU_enUS832US832&oq=c+url+sanitizer+example+program&aqs=chrome..69i57j69i60l3.7067j1j7&sourceid=chrome&ie=UTF-8";
    char* sanitizedURL = sanitizeURL(url);

    printf("Original URL: %s\nSanitized URL: %s\n", url, sanitizedURL);

    free(sanitizedURL); //free dynamically allocated memory

    return 0;
}