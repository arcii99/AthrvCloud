//FormAI DATASET v1.0 Category: Image Classification system ; Style: medieval
#include <stdio.h>

/* Medieval Image Classification System */

int main() {
  char knight[50];
  int sword_length;
  int shield_size;

  // Get user input
  printf("Greetings adventurer! What is your name, brave knight?\n");
  scanf("%s", knight);
  printf("\nWelcome %s! Now, let us determine your sword and shield size.\n");
  printf("What is the length of your sword, in inches?\n");
  scanf("%d", &sword_length);
  printf("\nAnd what is the size of your shield, in square inches?\n");
  scanf("%d", &shield_size);

  // Image classification
  if(sword_length > 40 && shield_size > 400) {
    printf("\n%s, your sword and shield are worthy of a dragon slayer!\n", knight);
  } else if(sword_length > 30 && shield_size > 300) {
    printf("\n%s, your sword and shield are suitable for a knight errant.\n", knight);
  } else if(sword_length > 20 && shield_size > 200) {
    printf("\n%s, your sword and shield are adequate for a foot soldier.\n", knight);
  } else {
    printf("\n%s, your sword and shield are not fit for battle.\n", knight);
  }

  return 0;
}