//FormAI DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int size_of_input;
    int spam_count = 0;
    float spam_percentage;

    printf("Enter your message:\n");
    fgets(input, sizeof(input), stdin);

    size_of_input = strlen(input);

    for(int i = 0; i < size_of_input; i++) {
        if(input[i] == 's' && input[i+1] == 'p' && input[i+2] == 'a' && input[i+3] == 'm') {
            spam_count++;
        }
    }

    spam_percentage = (float)spam_count / ((float)size_of_input / 4) * 100;

    if(spam_percentage > 5) {
        printf("Warning: This message may contain spam!\n");
    } else {
        printf("This message is safe to send.\n");
    }

    return 0;
}