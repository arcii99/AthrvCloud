//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    typedef struct {
        char name[50];
        char phone[20];
    } Entry;

    Entry phonebook[100];
    int i = 0;

    while (1) {
        char input[50];

        printf("Enter name and phone number in the format \"name number\" or \"quit\" to exit: ");
        fgets(input, 50, stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        char *name = strtok(input, " ");
        char *phone = strtok(NULL, "\n");

        if (phone == NULL) {
            printf("Invalid input\n");
            continue;
        }

        strcpy(phonebook[i].name, name);
        strcpy(phonebook[i].phone, phone);

        i++;
    }

    printf("\nPhonebook:\n");

    for (int j = 0; j < i; j++) {
        printf("%s\t%s\n", phonebook[j].name, phonebook[j].phone);
    }

    return 0;
}