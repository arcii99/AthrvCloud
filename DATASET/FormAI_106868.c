//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int count = 0;
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    // Removing newline character from the end of string
    message[strcspn(message, "\n")] = 0;
 
    char* spamWords[5] = {"offer", "credit", "free", "income", "money"};
  
    char* word = strtok(message, " ");
    while (word != NULL) {
        for(int i=0; i<5; i++) {
            if(strstr(word, spamWords[i]) != NULL){
                printf("Spam word detected: %s\n", word);
                count++;
            }
        }
        word = strtok(NULL, " ");
    }
    if(count >= 2) {
        printf("This message is classified as spam.\n");
    }
    else {
        printf("This message is not spam.\n");
    }
    return 0;
}