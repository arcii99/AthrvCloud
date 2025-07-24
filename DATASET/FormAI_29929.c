//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *virus[] = {"trojan", "worm", "spyware", "ransomware", "adware"};
  int count = 0;
  
  if (argc != 2) {
    printf("Incorrect usage. Correct usage: %s <filename>\n", argv[0]);
    exit(1);
  }
 
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: Could not open file\n");
    exit(1);
  }

  char line[100];
  while(fgets(line, 100, fp) != NULL) {
    for(int i=0; i<5; i++) {
      if(strstr(line, virus[i])) {
        printf("Virus detected: %s\n", virus[i]);
        count++;
        break;
      }
    }
  }

  if(count == 0) {
    printf("No viruses detected in file.\n");
  } else {
    printf("%d viruses detected in file.\n", count);
  }

  fclose(fp);
  return 0;
}