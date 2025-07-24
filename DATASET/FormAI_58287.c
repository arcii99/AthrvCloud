//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char english[1000], cat[1000], ch;
    int i, j;

    // Cat Dictionary
    char *dictionary[26] = {
        "Meow", // A -> Meow
        "Purr", // B -> Purr
        "Hiss", // C -> Hiss
        "Kitten", // D -> Kitten
        "Scratch", // E -> Scratch
        "Fur", // F -> Fur
        "Whiskers", // G -> Whiskers
        "Milk", // H -> Milk
        "Mouse", // I -> Mouse
        "Claw", // J -> Claw
        "Lick", // K -> Lick
        "Tail", // L -> Tail
        "Paw", // M -> Paw
        "Nap", // N -> Nap
        "Rat", // O -> Rat
        "Yarn", // P -> Yarn
        "Tree", // Q -> Tree
        "Fish", // R -> Fish
        "Tongue", // S -> Tongue
        "Feline", // T -> Feline
        "Vet", // U -> Vet
        "Toy", // V -> Toy
        "Mews", // W -> Mews
        "Nip", // X -> Nip
        "Zzz", // Y -> Zzz
        "Kitty" // Z -> Kitty
    };

    printf("Enter text to translate: ");
    fgets(english, sizeof(english), stdin);

    // Convert to Cat Language
    for (i = 0, j = 0; i < strlen(english); i++) {
        ch = english[i];
        if (ch >= 'A' && ch <= 'Z') { // Uppercase Letters
            cat[j++] = dictionary[ch - 'A'][0];
            cat[j++] = dictionary[ch - 'A'][1];
            cat[j++] = dictionary[ch - 'A'][2];
            cat[j++] = ' ';
        } else if (ch >= 'a' && ch <= 'z') { // Lowercase Letters
            cat[j++] = dictionary[ch - 'a'][0];
            cat[j++] = dictionary[ch - 'a'][1];
            cat[j++] = dictionary[ch - 'a'][2];
            cat[j++] = ' ';
        } else {
            cat[j++] = ch;
        }
    }

    printf("\nCat translated text: %s", cat);

    return 0;
}