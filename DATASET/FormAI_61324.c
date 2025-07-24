//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
  char name[20];
  int account_number;
  float balance;
};

struct Record createRecord(char name[20], int account_number, float balance) {
  struct Record record;
  strcpy(record.name, name);
  record.account_number = account_number;
  record.balance = balance;
  return record;
}

void showRecord(struct Record record) {
  printf("\nName: %s\nAccount number: %d\nBalance: $%.2f\n", record.name, record.account_number, record.balance);
}

int main() {
  printf("Welcome to the Funny C Banking Record System!\n");

  struct Record records[10];

  records[0] = createRecord("Tom", 12345, 100.2);
  records[1] = createRecord("Jerry", 54321, 23.9);
  records[2] = createRecord("Scooby", 98765, 55.6);
  records[3] = createRecord("Shaggy", 45678, 77.7);
  records[4] = createRecord("Fred", 13579, 88.8);

  int num_records = 5;

  int choice;
  do {
    printf("\n\nMenu:\n1. Add a record\n2. Remove a record\n3. View records\n4. Exit\nEnter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        if (num_records >= 10) {
          printf("\nSorry, can't add more than 10 records!\n");
          break;
        }
        printf("\nEnter name: ");
        char name[20];
        scanf("%s", name);
        printf("Enter account number: ");
        int account_number;
        scanf("%d", &account_number);
        printf("Enter balance: ");
        float balance;
        scanf("%f", &balance);
        records[num_records] = createRecord(name, account_number, balance);
        num_records++;
        printf("\nRecord added successfully!\n");
        break;
      }
      case 2: {
        if (num_records == 0) {
          printf("\nSorry, no records to remove!\n");
          break;
        }
        printf("\nEnter account number to remove: ");
        int account_number;
        scanf("%d", &account_number);
        int index = -1;
        for (int i = 0; i < num_records; i++) {
          if (records[i].account_number == account_number) {
            index = i;
            break;
          }
        }
        if (index == -1) {
          printf("\nSorry, no record found with account number %d!\n", account_number);
          break;
        } else {
          for (int i = index; i < num_records-1; i++) {
            records[i] = records[i+1];
          }
          num_records--;
          printf("\nRecord removed successfully!\n");
        }
        break;
      }
      case 3: {
        if (num_records == 0) {
          printf("\nSorry, no records to show!\n");
          break;
        }
        printf("\nRecords:\n");
        for (int i = 0; i < num_records; i++) {
          showRecord(records[i]);
        }
        break;
      }
      case 4: {
        printf("\nGoodbye! Thanks for using the Funny C Banking Record System!\n");
        break;
      }
      default: {
        printf("\nInvalid choice, please try again!\n");
      }
    }
  } while (choice != 4);

  return 0;
}