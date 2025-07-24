//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include<stdio.h>
#include<string.h>

int main() {
    char email[100], spamWords[10][20] = {"viagra", "lottery", "money", "free", "rich", "alert", "urgent", "cc", "click", "income"};
    int i, j, flag=0;
    
    printf("Enter the email: ");
    scanf("%s", email);
    
    for(i=0; i<strlen(email); i++) {
        email[i] = tolower(email[i]); //converting email to lowercase
    }
    
    for(i=0; i<strlen(email); i++) {
        if(email[i] == '@') { // if @ is reached, break from loop
            break;
        } 
        else {
            for(j=0; j<10; j++) {
                if(email[i] == spamWords[j][0]) {
                    if(strncmp(&email[i], spamWords[j], strlen(spamWords[j])) == 0) {
                        flag = 1; // if spam word found, set flag to 1
                    }
                }
            }
        }
    }
    
    if(flag == 1) {
        printf("This email may be a spam.\n");
    }
    else {
        printf("This email is not a spam.\n");
    }
    
    return 0;
}