//FormAI DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    char name[20], entry[500];
    int date, month, year;

    printf("Welcome to your digital diary!\n");
    printf("Please enter today's date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &date, &month, &year);
    printf("Hi there! What's your name? ");
    scanf("%s", &name);
    printf("Hello %s! What would you like to write about today?\n", name);
    printf("Please type your entry below (press enter twice to exit):\n");

    // Reading entire line
    char c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
    fgets(entry, 500, stdin);

    printf("Great! Here's your entry for %d-%d-%d:\n\n", date, month, year);
    printf("%s", entry);

    printf("\nThank you for using your digital diary! Goodbye!");

    return 0;
}