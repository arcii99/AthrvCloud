//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to check if there is an intrusion
int check_intrusion(char* input) {

  // Define the strings for the attack patterns
  char* pattern1 = "rm -rf";
  char* pattern2 = "sudo";
  char* pattern3 = "perl";
  char* pattern4 = "bash";

  // Check for the presence of each pattern in the input
  if (strstr(input, pattern1) != NULL || strstr(input, pattern2) != NULL ||
      strstr(input, pattern3) != NULL || strstr(input, pattern4) != NULL) {

    // If any of the patterns are found, return 1 (intrusion detected)
    return 1;
  }

  // If none of the patterns are found, return 0 (no intrusion detected)
  return 0;
}

int main() {

  // Define a buffer for the user input
  char input[100];

  // Read user input
  printf("Enter a command: ");
  fgets(input, 100, stdin);

  // Check for intrusion
  if (check_intrusion(input)) {
    printf("Intrusion detected!\n");
  } else {
    printf("No intrusion detected.\n");
  }

  return 0;
}