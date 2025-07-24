//FormAI DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

struct PhoneBook {
    char name[50];
    char number[20];
};

int main() {
    int numEntries, i;
    struct PhoneBook entries[100];
    char searchName[50];
    
    printf("Enter the number of entries: ");
    scanf("%d", &numEntries);

    // Populate the phone book
    for (i = 0; i < numEntries; i++) {
        printf("\nEnter Name: ");
        scanf("%s", entries[i].name);
        printf("Enter Phone Number: ");
        scanf("%s", entries[i].number);
    }

    // Search for a specific name
    printf("\nEnter the name to search for: ");
    scanf("%s", searchName);
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("\n%s: %s", entries[i].name, entries[i].number);
            break;
        }
    }
    if (i == numEntries) {
        printf("\n%s not found in phone book.", searchName);
    }

    return 0;
}