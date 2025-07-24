//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
/* 
Ah, what light through yonder window breaks?
It is the CSV Reader, and Juliet is the file name!

*/

#include <stdio.h>
#include <string.h>

struct record {
  char name[20];
  int age;
  char city[20];
};

int main() {

  // declare file pointer
  FILE *fp;

  // declare record structure and buffer
  struct record r;
  char buffer[100];

  // open file for reading
  fp = fopen("juliet.csv", "r");

  if (fp == NULL) {
    printf("Alas! Could not open file.\n");
    return 1;
  } else {
    printf("O happy dagger! File open successful.\n");
  }

  // read and print each line of the CSV file
  while (fgets(buffer, 100, fp)) {
    sscanf(buffer, "%[^,],%d,%[^,\n]", r.name, &r.age, r.city);
    printf("Fair maiden %s, from %s, aged %d summers.\n", r.name, r.city, r.age);
  }

  // close file and bid the program adieu
  fclose(fp);
  printf("Parting is such sweet sorrow, until we meet again.\n");
  return 0;
}