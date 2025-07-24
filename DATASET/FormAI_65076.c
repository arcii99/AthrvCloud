//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

// Our code-breaking expert
int sherlockHolmes(char message[]) {
    int i, j;
    int length = strlen(message);
    int letterCount = 0;
    int numberCount = 0;
    int specialCount = 0;
    
    // Check each character in the message
    for(i=0; i<length; i++) {
        // Check if the character is a letter
        if((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z')) {
            letterCount++;
        }
        // Check if the character is a number
        else if(message[i] >= '0' && message[i] <= '9') {
            numberCount++;
        }
        // Check if the character is a special character
        else if(message[i] == ' ' || message[i] == '.' || message[i] == ',' || message[i] == '!' || message[i] == '?' || message[i] == '$' || message[i] == '#' || message[i] == '@') {
            specialCount++;
        }
    }
    
    // Determine if the message is spam or not based on the counts
    if(letterCount > 5 && numberCount < 3 && specialCount < 2) {
        printf("This message appears to be legitimate.\n");
        return 0;
    }
    else {
        printf("This message appears to be spam. Sherlock is on the case!\n");
        int spamScore = letterCount + 2*numberCount + 3*specialCount;
        printf("Sherlock has determined that the spam score for this message is %d.\n", spamScore);
        printf("It would be wise to delete this message before further harm is done!\n");
        return 1;
    }
}

// The main function where we'll test our code-breaking expert
int main() {
    // Test messages
    char message1[] = "Hello, this is just a test message.";
    char message2[] = "Make money fast! Click here to learn more!";
    char message3[] = "QWERTYUIOP ASDFGHJKL ZXCVBNM";
    
    // Let's see if Sherlock can detect spam
    int result1 = sherlockHolmes(message1);
    int result2 = sherlockHolmes(message2);
    int result3 = sherlockHolmes(message3);
    
    // Print results
    printf("\nTesting complete! Results: \n");
    printf("Message 1: %d\n", result1);
    printf("Message 2: %d\n", result2);
    printf("Message 3: %d\n", result3);
    
    return 0;
}