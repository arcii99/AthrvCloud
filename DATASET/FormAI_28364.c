//FormAI DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("<<=========================== FireWall by CodeFrenzy ===========================>>\n");
  printf("<<=================================================================================>>\n\n");

  int num_rules = 0;
  printf("How many firewall rules do you want to add? ");
  scanf("%d", &num_rules);

  char **rules = (char **) malloc(num_rules * sizeof(char *));
  for (int i = 0; i < num_rules; i++) {
    rules[i] = (char *) malloc(20 * sizeof(char));
    printf("Enter rule %d: ", i+1);
    scanf("%s", rules[i]);
  }

  printf("\n\n");

  char ip_address[16];
  int allowed = 0;

  while (allowed == 0) {
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    for (int i = 0; i < num_rules; i++) {
      if (strstr(rules[i], ip_address) != NULL) {
        allowed = 1;
        break;
      }
    }
    printf("\n");
    if (allowed == 0) {
      printf("Access denied, please contact your system administrator for assistance.\n");
      printf("<<--------------------------------------------------------------------------------->>\n\n");
    }
  }

  printf("Success! Firewall has allowed access to IP %s.\n", ip_address);
  printf("<<=================================================================================>>\n");

  return 0;
}