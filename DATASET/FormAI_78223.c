//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Banking Record System!\n");
  int num_customers = 0;
  while (num_customers < 10) {
    printf("Enter the name of customer %d: ", num_customers + 1);
    char name[50];
    scanf("%s", name);
    printf("Enter the account balance of customer %d: $", num_customers + 1);
    double balance;
    scanf("%lf", &balance);
    FILE *fptr;
    fptr = fopen("banking_records.txt", "a");
    fprintf(fptr, "Customer %d: %s has a balance of $%.2lf\n", num_customers + 1, name, balance);
    fclose(fptr);
    printf("Customer record saved!\n");
    num_customers++;
    if (num_customers == 10) {
      printf("Max capacity reached. Exiting program.\n");
    } else {
      printf("Would you like to enter another customer record? (y/n)");
      char choice;
      scanf(" %c", &choice);
      if (choice == 'n') {
        printf("Exiting program.\n");
        break;
      }
    }
  }
  return 0;
}