//FormAI DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fptr;
    char name[20], date[30], entry[500];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date in the format (dd-mm-yyyy): ");
    scanf("%s", date);

    // Opening the file
    fptr = fopen("digital_diary.txt", "a");

    if (fptr == NULL) {
        printf("Error opening the file.\n");
        return -1;
    }

    printf("Enter your entry for the day: \n");
    getchar(); // Clear buffer
    fgets(entry, 500, stdin); // Getting the entire line including spaces

    // Encrypting the entry
    for (int i = 0; i < strlen(entry); i++) {
        if (entry[i] >= 'a' && entry[i] <= 'z') {
            entry[i] = 'z' - (entry[i] - 'a');
        } else if (entry[i] >= 'A' && entry[i] <= 'Z') {
            entry[i] = 'Z' - (entry[i] - 'A');
        }
    }

    // Writing the entry to the file
    fprintf(fptr, "%s, %s: %s\n", name, date, entry);

    printf("Entry recorded successfully in your digital diary.\n");

    // Closing the file
    fclose(fptr);

    return 0;
}