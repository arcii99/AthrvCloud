//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
  char password[10];
  printf("Enter your password: ");
  scanf("%s", password);

  if (strcmp(password, "password123") == 0) {
    printf("Access granted.\n");
  }
  else {
    printf("Access denied.\n");

    // Detect intrusion
    FILE *fp;
    fp = fopen("intrusion_log.txt", "a"); // Open file in append mode
    if (fp == NULL) {
      printf("Error: Failed to open file.");
      return 1;
    }
    else {
      fprintf(fp, "Attempted access with password: %s\n", password);
      printf("Intrusion detected and logged.\n");
    }

    fclose(fp); // Close file
  }

  return 0;
}