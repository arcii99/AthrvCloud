//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main()
{
    char email[1000];
    char spamWords[10][20] = {"buy now", "earn money", "limited time offer", "act fast", "click here", "100% free", "make money", "work from home", "cash prize", "exclusive offer"};
    int count = 0, i, j;

    printf("Please enter your email:\n");
    gets(email);

    for(i=0; i<10; i++){
        for(j=0; j<strlen(email); j++){
            if(email[j] == ' ' || email[j] == ',' || email[j] == '.' || email[j] == '\0' || email[j] == '\n'){
                if(strncmp(&email[j-count], spamWords[i], count) == 0){
                    printf("This email seems like spam!\n");
                    return 0;
                }
                count = 0;
            }
            else{
                count++;
            }
        }
    }

    printf("This email is not considered as spam.\n");

    return 0;
}