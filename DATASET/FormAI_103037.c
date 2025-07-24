//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

void convertToMorse(char word[], int len);

int main() {
    char message[100];
    int len;
    
    printf("Ah, yes! Another intriguing case for me to work on. What do we have here?\n");
    printf("Pray, what is the message that needs to be deciphered into Morse code?\n");
    scanf("%[^\n]", message);
    
    len = strlen(message);
    printf("Hmmm... %d characters, eh? Let me see what I can do...\n", len);
    
    convertToMorse(message, len);
    
    printf("There you have it, my dear friend! The message has been converted into Morse code. Elementary.\n");
    
    return 0;
}

void convertToMorse(char word[], int len) {
    char morse[26][10] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}
    };
    
    for(int i = 0; i < len; i++) {
        if(word[i] == ' ') {
            printf("  ");
        }
        else if(word[i] >= 'a' && word[i] <= 'z') {
            printf("%s ", morse[word[i] - 97]);
        }
        else if(word[i] >= 'A' && word[i] <= 'Z') {
            printf("%s ", morse[word[i] - 65]);
        }
        else {
            printf(" * ");
        }
    }
}