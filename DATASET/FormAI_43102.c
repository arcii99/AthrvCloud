//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {

    char input[1000];
    char morse[26][6]= { {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, 
                        {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, 
                        {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, 
                        {"-.--"}, {"--.."}
                      };

    printf("Enter Text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Input Text in Morse Code\n");

    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            printf(" ");
        }
        else {
            int index = input[i] - 'a';
            printf("%s ", morse[index]);
        }
    }

    return 0;
}