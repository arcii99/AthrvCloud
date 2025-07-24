//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
    char cAlienLanguage[26][4] = {   // List of c alien language words
        {"kpi"},
        {"lif"},
        {"son"},
        {"fug"},
        {"pho"},
        {"wib"},
        {"kin"},
        {"lut"},
        {"kro"},
        {"beq"},
        {"mip"},
        {"tep"},
        {"niz"},
        {"pug"},
        {"sik"},
        {"vor"},
        {"jop"},
        {"fet"},
        {"xer"},
        {"zul"},
        {"gic"},
        {"dax"},
        {"rym"},
        {"mod"},
        {"huv"},
        {"cel"}
    };

    char input[30];
    int validInput = 0;

    printf("Enter a c alien word: ");
    fgets(input, 30, stdin);
    input[strcspn(input, "\n")] = 0;    // Remove trailing newline character

    for (int i = 0; i < 26; i++) {
        if (strcmp(input, cAlienLanguage[i]) == 0) {
            validInput = 1;     // Check if input word is valid c alien word
            switch (i) {
                case 0:
                    printf("Your input '%s' translates to 'hello'\n", input);
                    break;
                case 1:
                    printf("Your input '%s' translates to 'thank you'\n", input);
                    break;
                case 2:
                    printf("Your input '%s' translates to 'help'\n", input);
                    break;
                case 3:
                    printf("Your input '%s' translates to 'food'\n", input);
                    break;
                case 4:
                    printf("Your input '%s' translates to 'water'\n", input);
                    break;
                case 5:
                    printf("Your input '%s' translates to 'weapon'\n", input);
                    break;
                case 6:
                    printf("Your input '%s' translates to 'friend'\n", input);
                    break;
                case 7:
                    printf("Your input '%s' translates to 'enemy'\n", input);
                    break;
                case 8:
                    printf("Your input '%s' translates to 'attack'\n", input);
                    break;
                case 9:
                    printf("Your input '%s' translates to 'run'\n", input);
                    break;
                case 10:
                    printf("Your input '%s' translates to 'safe'\n", input);
                    break;
                case 11:
                    printf("Your input '%s' translates to 'home'\n", input);
                    break;
                case 12:
                    printf("Your input '%s' translates to 'pray'\n", input);
                    break;
                case 13:
                    printf("Your input '%s' translates to 'hope'\n", input);
                    break;
                case 14:
                    printf("Your input '%s' translates to 'love'\n", input);
                    break;
                case 15:
                    printf("Your input '%s' translates to 'hate'\n", input);
                    break;
                case 16:
                    printf("Your input '%s' translates to 'kill'\n", input);
                    break;
                case 17:
                    printf("Your input '%s' translates to 'death'\n", input);
                    break;
                case 18:
                    printf("Your input '%s' translates to 'life'\n", input);
                    break;
                case 19:
                    printf("Your input '%s' translates to 'sad'\n", input);
                    break;
                case 20:
                    printf("Your input '%s' translates to 'happy'\n", input);
                    break;
                case 21:
                    printf("Your input '%s' translates to 'fear'\n", input);
                    break;
                case 22:
                    printf("Your input '%s' translates to 'danger'\n", input);
                    break;
                case 23:
                    printf("Your input '%s' translates to 'peace'\n", input);
                    break;
                case 24:
                    printf("Your input '%s' translates to 'war'\n", input);
                    break;
                case 25:
                    printf("Your input '%s' translates to 'hopeless'\n", input);
                    break;
                default:
                    printf("Error: Could not translate '%s'\n", input);
            }
            break;
        }
    }
    if (!validInput) {
        printf("Error: '%s' is not a valid c alien word\n", input);
    }
  
    return 0;
}