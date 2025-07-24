//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all non-alphanumeric characters from a string
void sanitize(char* str){
    int len = strlen(str);
    char* temp = (char*) malloc (sizeof(char) * (len + 1)); // allocate memory to temporary string variable

    int j = 0;
    for(int i = 0; str[i]; i++){
        if((str[i] >= 'a' && str[i] <= 'z') || 
           (str[i] >= 'A' && str[i] <= 'Z') || 
           (str[i] >= '0' && str[i] <= '9')){ // check if the character is alphanumeric
            temp[j++] = str[i]; // add the character to the temporary variable if alphanumeric
        }
    }
    temp[j] = '\0'; // add null character to the end of sanitized string
    strcpy(str, temp); // copy the sanitized string back to original string
    free(temp); // free the memory allocated to temporary variable
}

int main(){
    char url[] = "https://www.example.com?q1=hello&$^q2=world*"; // sample url with non-alphanumeric characters
    printf("Before sanitization: %s\n", url);

    sanitize(url); // call the function to sanitize the url

    printf("After sanitization: %s\n", url);

    return 0;
}