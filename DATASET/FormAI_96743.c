//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void sig_handler(int signo) {
  if (signo == SIGINT)
    printf("Received SIGINT, exiting...\n");
  exit(0);
}

int main(int argc, char *argv[]) {
  signal(SIGINT, sig_handler);

  char *cmd = (char *) malloc(sizeof(char) * 1024);
  char *bad_words[] = {"rm", "sudo", "reboot", "halt"};
  int num_bad_words = sizeof(bad_words)/sizeof(bad_words[0]);

  while (1) {
    printf("> ");
    fgets(cmd, 1024, stdin);
    cmd[strcspn(cmd, "\n")] = '\0'; 

    for (int i=0; i<num_bad_words; i++) {
      if (strstr(cmd, bad_words[i]) != NULL) {
        printf("Intrusion detected! Attempted command: %s\n", cmd);
        exit(1);
      }
    }

    system(cmd);
  }

  free(cmd);
  return 0;
}