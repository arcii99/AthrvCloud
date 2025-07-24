//FormAI DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main() {
  // Introducing the Digital Diary
  printf("A digital diary doth I present,\nTo record thy thoughts and acts in print.\n");
  printf("So let us commence, for time is lent,\nAnd thy memories shall not be tint.\n\n");

  // Promoting the user to input diary entry
  printf("What say you, fair maiden or sir?\nOf what hast happened, art thou a stir?\n");
  char entry[1000];
  fgets(entry, 1000, stdin);

  //Saving the diary entry to file
  FILE* fp;
  fp = fopen("Diary.txt", "a");
  fprintf(fp, "%s\n\n", entry);
  fclose(fp);

  // Letting the user know that the entry has been recorded
  printf("\nHa! This deed is done, and thou art sated.\nBut fear not, for thine words shall be related.\n");

  return 0;
}