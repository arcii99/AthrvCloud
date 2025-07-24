//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

struct Contact {
  char name[20];
  long int number;
};

int main()
{
    //creating a phone book with space for 10 contacts
    struct Contact phonebook[10];
    int count = 0;
    char decision;
    do {
        //adding details of a new contact to the phone book
        printf("Enter the name of the contact: ");
        scanf("%s", phonebook[count].name);
        printf("Enter the phone number of the contact: ");
        scanf("%ld", &phonebook[count].number);
        count++;

        printf("Do you want to add another contact? (Y/N)");
        scanf("%c", &decision);
    } while (decision == 'Y' || decision == 'y' && count<10);

    //printing all contacts in the phone book
    printf("\n------------PHONE BOOK-------------\n");
    for(int i=0;i<count;i++) {
        printf("Name: %s\t Number: %ld\n", phonebook[i].name, phonebook[i].number);
    }

    return 0;
}