//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char knight_name[50] = "Sir Lancelot";
    char greeting[100] = "Greetings, ";

    // Check if knight_name is longer than 10 characters
    if (strlen(knight_name) > 10) {
        strcat(greeting, "mighty ");
    } else {
        strcat(greeting, "valiant ");
    }

    // Capitalize first letter of knight_name
    knight_name[0] = toupper(knight_name[0]);

    // Concatenate knight_name to greeting
    strcat(greeting, knight_name);
    strcat(greeting, "!");

    printf("%s\n", greeting);

    // Replace "Lance" with "Arthur" in knight_name
    char *lance_ptr = strstr(knight_name, "Lance");
    char *arthur_ptr = "Arthur";
    if (lance_ptr != NULL) {
        strncpy(lance_ptr, arthur_ptr, strlen(arthur_ptr));
    }

    // Add "the Brave" to knight_name
    strcat(knight_name, " the Brave");

    printf("New knight name: %s\n", knight_name);

    return 0;
}