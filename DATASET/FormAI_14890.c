//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {
    char greeting[] = "Hello world!";
    char name[20];
    printf("%s\n", greeting);
    printf("What is your name?\n");
    scanf("%s", name);

    // Remove vowels from the name
    char new_name[20];
    int j = 0;
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] != 'a' && name[i] != 'e' && name[i] != 'i'
            && name[i] != 'o' && name[i] != 'u') {
            new_name[j] = name[i];
            j++;
        }
    }
    new_name[j] = '\0';

    // Capitalize the first letter of the new name
    char final_name[20];
    final_name[0] = toupper(new_name[0]);
    for (int i = 1; i < strlen(new_name); i++) {
        final_name[i] = new_name[i];
    }
    final_name[strlen(new_name)] = '\0';

    // Concatenate the greeting and the final name
    char final_greeting[50];
    strcpy(final_greeting, greeting);
    strcat(final_greeting, ", ");
    strcat(final_greeting, final_name);
    strcat(final_greeting, "!");

    printf("%s\n", final_greeting);

    return 0;
}