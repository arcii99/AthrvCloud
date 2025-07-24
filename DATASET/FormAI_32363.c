//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include<stdio.h>
#include<string.h>

int spam_detection(char *message) {
    int i, uppercase_letters = 0, lowercase_letters = 0, digits = 0, spaces = 0, special_characters = 0;
    int spam_score = 0;
    float uppercase_percentage, lowercase_percentage, digit_percentage, space_percentage, special_percentage;
    int message_length = strlen(message);
    
    // Count the number of uppercase letters, lowercase letters, digits, spaces and special characters
    for(i=0; i<message_length; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            uppercase_letters++;
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            lowercase_letters++;
        }
        else if(message[i] >= '0' && message[i] <= '9') {
            digits++;
        }
        else if(message[i] == ' ') {
            spaces++;
        }
        else {
            special_characters++;
        }
    }
    
    // Calculate the percentages of each type of characters in the message
    uppercase_percentage = (float)uppercase_letters / message_length;
    lowercase_percentage = (float)lowercase_letters / message_length;
    digit_percentage = (float)digits / message_length;
    space_percentage = (float)spaces / message_length;
    special_percentage = (float)special_characters / message_length;
    
    // Count the spam score based on the type and percentage of characters in the message
    if(uppercase_percentage > 0.4 || lowercase_percentage > 0.4) {
        spam_score += 2;
    }
    if(digit_percentage > 0.3) {
        spam_score += 1;
    }
    if(space_percentage > 0.5) {
        spam_score += 1;
    }
    if(special_percentage > 0.2) {
        spam_score += 2;
    }
    
    return spam_score;
}

int main() {
    char message[200];
    
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    int spam_score = spam_detection(message);
    
    if(spam_score >= 4) {
        printf("This message is classified as spam\n");
    }
    else {
        printf("This message is not spam\n");
    }
    
    return 0;
}