//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voter {
  char name[30];
  int uid;
  char password[20];
};

int main() {
  FILE *fp;
  char file_name[20] = "voters.txt";
  fp = fopen(file_name, "w");
  if (fp == NULL) {
    printf("File error!\n");
    exit(0);
  }

  struct voter v1, v2, v3, v4;

  strcpy(v1.name, "Alice");
  v1.uid = 1001;
  strcpy(v1.password, "pa55w0rd");

  strcpy(v2.name, "Bob");
  v2.uid = 1002;
  strcpy(v2.password, "secure");

  strcpy(v3.name, "Charlie");
  v3.uid = 1003;
  strcpy(v3.password, "myspace");

  strcpy(v4.name, "Dave");
  v4.uid = 1004;
  strcpy(v4.password, "password");

  fwrite(&v1, sizeof(v1), 1, fp);
  fwrite(&v2, sizeof(v2), 1, fp);
  fwrite(&v3, sizeof(v3), 1, fp);
  fwrite(&v4, sizeof(v4), 1, fp);

  fclose(fp);
  
  return 0;
}