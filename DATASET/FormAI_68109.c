//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char *user = NULL;
  char *group = NULL;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s [user] [group]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  user = argv[1];
  group = argv[2];

  setuid(0); // Set user ID to root

  // Create the group
  char *create_group[] = {"groupadd", group, NULL};
  execvp(create_group[0], create_group);

  // Add user to the group
  char *add_user_to_group[] = {"usermod", "-aG", group, user, NULL};
  execvp(add_user_to_group[0], add_user_to_group);

  return 0;
}