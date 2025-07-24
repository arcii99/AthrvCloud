//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char email[1000];
    printf("Enter your email to check for spam: ");
    scanf("%s", email);

    int at_count = 0, dot_count = 0, len = strlen(email);

    // Check if email contains '@' and '.'
    for(int i=0; i<len; i++){
        if(email[i] == '@') at_count++;
        if(email[i] == '.') dot_count++;
    }

    if(at_count == 1 && dot_count>0){
        int at_index = -1, dot_index = -1;
        int is_spam = 0;

        // Check for whitespace before and after '@' symbol
        for(int i=0; i<len; i++){
            if(email[i] == '@'){
                if(i-1 >= 0 && isspace(email[i-1])) is_spam = 1;
                if(i+1 < len && isspace(email[i+1])) is_spam = 1;
                at_index = i;
            }
        }

        // Check if domain name is valid
        char domain[1000];
        strcpy(domain, &email[at_index+1]);
        if(strstr(domain, ".com") == NULL && strstr(domain, ".org") == NULL && \
            strstr(domain, ".edu") == NULL && strstr(domain, ".gov") == NULL) is_spam = 1;

        // Check for consecutive dots in email
        for(int i=0; i<len-1; i++){
            if(email[i] == '.' && email[i+1] == '.') is_spam = 1;
        }

        if(is_spam) printf("This email is considered spam.\n");
        else printf("This email is not spam.\n");
    }
    else printf("This email is invalid.\n");

    return 0;
}