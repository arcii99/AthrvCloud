//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include<stdio.h>
#include<string.h>

//Function to remove leading and trailing whitespaces in user input
char* trim(char *str) {
    int i = 0;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') 
        i++;
    if(i == strlen(str))
        return "";
    str += i;
    int len = strlen(str);
    while(len > 0 && (str[len-1] == ' ' || str[len-1] == '\t' || str[len-1] == '\n'))
        str[--len] = 0;
    return str;
}

int main() {
    char buffer[1000];
    char sanitized[100];
    printf("Please enter a string to be sanitized: \n");
    fgets(buffer, 1000, stdin);
    char *input = trim(buffer);
    int i=0, j=0;
    while(input[i] != '\0') {
        if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || input[i] == ' ') {
            sanitized[j] = input[i];
            j++;
        }
        i++;
    }
    sanitized[j] = '\0';
    printf("Sanitized string: %s\n", sanitized);
    return 0;
}