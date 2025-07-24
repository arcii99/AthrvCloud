//FormAI DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    
    char spam_words[5][20]={"offer", "prize", "free", "discount", "win"}; // a list of spam words
    char email[200], temp[100]; // input email and temporary variable for string manipulation
    int i, j, flag; // loop counters and flag variable
    
    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter your email:\n");
    scanf("%[^\n]s", email); // read input string from user
    
    // convert email to lowercase
    for(i=0; email[i]!='\0'; i++) {
        if(email[i]>='A' && email[i]<='Z')
            email[i] = email[i] + 32;
    }
    
    // check if any spam word is present in the email
    flag = 0;
    for(i=0; email[i]!='\0'; i++) {
        if(email[i]==' ' || email[i]=='\t' || email[i]=='\r' || email[i]=='\n') {
            temp[j] = '\0';
            for(j=0; j<5; j++) {
                if(strcmp(temp, spam_words[j])==0) {
                    flag = 1; // spam detected
                    break;
                }
            }
            j=0;
        }
        else {
            temp[j++] = email[i];
        }
    }
    
    // output result
    if(flag==1) {
        printf("Warning: This email contains spam!\n");
        printf("Please do not respond to this email.\n");
    }
    else {
        printf("Congratulations! This email is genuine.\n");
        printf("Please feel free to respond to this email.\n");
    }
    
    return 0; // end program
}