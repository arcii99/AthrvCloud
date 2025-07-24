//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

void translate(char* phrase) { 
    if (strlen(phrase) == 0) {
        return; // base case
    }
    
    switch (phrase[0]) { // check first letter
        case 'c':
            printf("Meow");
            break;
        case 'a':
            printf("Purr");
            break;
        case 't':
            printf("Hiss");
            break;
        default:
            printf("Unknown");
            break;
    }

    translate(phrase+1); // recurse with rest of phrase
}

int main() {
    char* phrase = "cat";
    translate(phrase); // prints "Meow A Hiss"
    return 0;
}