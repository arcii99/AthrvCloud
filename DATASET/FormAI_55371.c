//FormAI DATASET v1.0 Category: Data validation ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to my data validation program!\n");

  int age;
  printf("Please enter your age: ");
  scanf("%d", &age);

  if (age >= 18 && age <=120) {
    printf("Great! You are eligible to create an account.\n");
    char username[20];
    printf("Please enter a username (max 20 characters): ");
    scanf("%s", username);

    int password;
    printf("Please enter a numeric password (4 digits): ");
    scanf("%d", &password);

    if (password >= 1000 && password <= 9999) {
      printf("Congratulations! You have successfully created an account with username %s and password %d.\n", username, password);
    } else {
      printf("Sorry, your password must be a 4-digit number.\n");
    }
  } else {
    printf("Sorry, you must be at least 18 years old to create an account.\n");
  }

  return 0;
}