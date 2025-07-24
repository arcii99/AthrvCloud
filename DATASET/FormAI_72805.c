//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char greeting[] = "Hello, World!";
    char name[20];
    char newName[20];
    int nameLength, vowels = 0, consonants = 0;

    printf("%s\n", greeting);
    printf("What is your name?\n");
    scanf("%s", name);

    nameLength = strlen(name);

    printf("Nice to meet you, %s! Let's play with your name a bit.\n", name);

    for (int i = 0; i < nameLength; i++) {
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' ||
            name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U') {
            vowels++;
        } else if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')) {
            consonants++;
        }
    }

    printf("Your name has %d vowels and %d consonants. Let's swap some letters around!\n", vowels, consonants);

    for (int i = 0; i < nameLength; i++) {
        if (i % 2 == 0 && name[i+1] != '\0') {
            newName[i] = name[i+1];
            newName[i+1] = name[i];
        } else {
            newName[i] = name[i];
        }
    }

    printf("Your new name is: %s\n", newName);

    return 0;
}