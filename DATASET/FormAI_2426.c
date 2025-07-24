//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

int check_for_intrusion(char *line);

int main() {
  char line[MAX_LENGTH];
  int intrusion_flag = 0;
  
  while (fgets(line, MAX_LENGTH, stdin)) {
    intrusion_flag = check_for_intrusion(line);
    if (intrusion_flag) {
      printf("Intrusion detected!\n");
      break;
    }
  }

  if (!intrusion_flag) {
    printf("No intrusion detected.\n");
  }

  return 0;
}

int check_for_intrusion(char *line) {
  char *intrusion_words[] = {"hack", "attack", "virus", "malware", "trojan"};
  int num_words = sizeof(intrusion_words) / sizeof(intrusion_words[0]);

  for (int i = 0; i < num_words; i++) {
    if (strstr(line, intrusion_words[i])) {
      return 1;
    }
  }

  return 0;
}