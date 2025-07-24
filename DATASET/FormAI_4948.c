//FormAI DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    
    printf("Greetings! Welcome to the land of C Syntax Parsing!\n");
    printf("What is thy name, adventurer?\n");
    
    scanf("%s", input);
    printf("Ah, well met %s!\n", input);

    printf("Pray tell, what code dost thou bring before me?\n");
    printf("Enter it now:\n");
    
    fgets(input, 100, stdin); // read input including spaces
    
    char* token = strtok(input, " ();{}"); // split string at these delimiters
    
    printf("Ah, I see that thou hast brought:\n");
    while (token != NULL) {
        if (token[0] == 'i' && token[1] == 'n' && token[2] == 't') { // proclaim if it's an integer declaration
            printf("Hark! %s is an integer declaration!\n", token);
        } else if (token[0] == 'f' && token[1] == 'l' && token[2] == 'o' && token[3] == 'a' && token[4] == 't') { // proclaim if it's a float declaration
            printf("Forsooth! %s is a float declaration!\n", token);
        } else if (token[0] == 'c' && token[1] == 'h' && token[2] == 'a' && token[3] == 'r') { // proclaim if it's a character declaration
            printf("Verily! %s is a character declaration!\n", token);
        } else if (token[0] == 'v' && token[1] == 'o' && token[2] == 'i' && token[3] == 'd') { // proclaim if it's a void declaration
            printf("Ha! %s is a void declaration!\n", token);
        }
        token = strtok(NULL, " ();{}");
    }
    
    printf("Thy code hath been parsed, %s. Fare thee well!\n", input);
    
    return 0;
}