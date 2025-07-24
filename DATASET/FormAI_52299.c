//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct Bank_record {
  char name[50];
  int account_number;
  float balance;
};

typedef struct Bank_record bank_record;

int main() {
  int num_of_records, i;
  printf("Enter the number of records: ");
  scanf("%d", &num_of_records);

  bank_record* records = malloc(sizeof(bank_record) * num_of_records);

  for (i = 0; i < num_of_records; i++) {
    printf("Enter record %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", &records[i].name);
    printf("Account number: ");
    scanf("%d", &records[i].account_number);
    printf("Balance: ");
    scanf("%f", &records[i].balance);
  }

  printf("\nRecords:\n");

  for (i = 0; i < num_of_records; i++) {
    printf("Record %d:\n", i + 1);
    printf("Name: %s\n", records[i].name);
    printf("Account number: %d\n", records[i].account_number);

    if (records[i].balance < 0) {
      printf("Balance: -$%0.2f\n", records[i].balance * -1);
    } else {
      printf("Balance: $%0.2f\n", records[i].balance);
    }
  }

  free(records);
  
  return 0;
}