//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {

  char password[20];
  printf("Enter your password to access your digital diary: ");
  scanf("%s", password); // Read user input for password

  if (strcmp(password, "mysecretpassword") == 0) { // Check if password matches
    printf("Welcome to your digital diary!\n");
    printf("Enter your thoughts for today:\n");

    char diary[1000];
    scanf(" %[^\n]s", diary); // Read user input for diary entry

    FILE *file = fopen("diary.txt", "a"); // Open diary file
    fprintf(file, "%s\n", diary); // Write diary entry to file
    fclose(file); // Close diary file

    printf("Your thoughts have been successfully recorded in your digital diary.\n");
  }
  else { // Password does not match
    printf("Access denied. The password you entered is incorrect.\n");
  }

  return 0;
}