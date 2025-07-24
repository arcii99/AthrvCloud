//FormAI DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize variables
  char entry[1024];
  time_t current_time;
  struct tm * time_info;

  // get current time
  time(&current_time);
  time_info = localtime(&current_time);

  // print welcome message and ask for user input
  printf("Welcome to your digital diary!\n");
  printf("Please make your entry for today:\n");
  fgets(entry, 1024, stdin);

  // open file and append entry
  FILE *fp;
  fp = fopen("diary.txt", "a");
  fprintf(fp, "%02d/%02d/%04d - %02d:%02d:%02d\n", time_info->tm_mday, time_info->tm_mon + 1, time_info->tm_year + 1900, time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
  fprintf(fp, "%s\n\n", entry);
  fclose(fp);

  // print success message
  printf("Entry successfully added to your digital diary!\n");

  return 0;
}