//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: irregular
#include<stdio.h>
#include<string.h>

char* santize_url(char* url){  // A function to sanitize the URL
    char* new_url = (char*)malloc(1024 * sizeof(char));  // Allocate memory for 1024 characters
    memset(new_url, '\0', sizeof(new_url));  // Initialize memory to all null characters
    int j = 0;
    for(int i=0; i<strlen(url); i++){  // Loop through the entire string
        if(url[i] == ' '){  // If current character is space, replace it with %20
            new_url[j] = '%';
            new_url[j+1] = '2';
            new_url[j+2] = '0';
            j = j+3;
        }
        else if((url[i]>=48 && url[i]<=57) || (url[i]>=65 && url[i]<=90) || (url[i]>=97 && url[i]<=122)){  // If current character is alphanumeric, copy it to the new string
            new_url[j] = url[i];
            j++;
        }
        else{  // If current character is not alphanumeric and not a space, ignore it
            continue;
        }
    }
    new_url[j] = '\0';  // Add null character to terminate the string
    return new_url;
}

int main(){
    char url[] = "https://www.google.com/search?q=the+world+is+full+of+surprises&rlz=1C1GCEA_enUS832US832&oq=the+world+is+full+of+surprises&aqs=chrome..69i57j0l5.3963j0j7&sourceid=chrome&ie=UTF-8";
    char* sanitized_url = santize_url(url);  // Call the santize_url function
    printf("%s\n", sanitized_url);  // Print the sanitized URL
    free(sanitized_url);  // Free the allocated memory
    return 0;
}