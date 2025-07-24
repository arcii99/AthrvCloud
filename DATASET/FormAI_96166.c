//FormAI DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100  // maximum number of entries that can be stored
#define MAX_LEN 1000     // maximum length of an entry
#define FILENAME "diary.txt"  // name of the file where diary entries are stored

struct Entry {
  char date[20];
  char time[20];
  char text[MAX_LEN];
};

struct Diary {
  struct Entry entries[MAX_ENTRIES];
  int count;  // number of entries in the diary
};

void print_menu() {
  printf("Welcome to your Digital Diary.\n");
  printf("1. Add an entry\n");
  printf("2. View entries\n");
  printf("3. Delete an entry\n");
  printf("4. Exit\n");
}

void add_entry(struct Diary *d) {
  if (d->count == MAX_ENTRIES) {
    printf("Sorry, your diary is full.\n");
    return;
  }
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  strftime(d->entries[d->count].date, 20, "%Y-%m-%d", tm);
  strftime(d->entries[d->count].time, 20, "%H:%M:%S", tm);
  printf("Enter your diary entry (max length %d):\n", MAX_LEN);
  fgets(d->entries[d->count].text, MAX_LEN, stdin);
  strtok(d->entries[d->count].text, "\n");  // remove trailing newline
  d->count++;
  printf("Entry added.\n");
}

void view_entries(struct Diary *d) {
  if (d->count == 0) {
    printf("Your diary is empty.\n");
    return;
  }
  int i;
  for (i = 0; i < d->count; i++) {
    printf("Date: %s\n", d->entries[i].date);
    printf("Time: %s\n", d->entries[i].time);
    printf("Entry: %s\n", d->entries[i].text);
    printf("\n");
  }
}

void delete_entry(struct Diary *d) {
  if (d->count == 0) {
    printf("Your diary is empty.\n");
    return;
  }
  int i, index;
  printf("Enter the index of the entry you want to delete:\n");
  scanf("%d", &index);
  if (index < 1 || index > d->count) {
    printf("Invalid index.\n");
    return;
  }
  for (i = index - 1; i < d->count - 1; i++) {
    d->entries[i] = d->entries[i + 1];
  }
  d->count--;
  printf("Entry deleted.\n");
}

void save_entries(struct Diary *d) {
  FILE *fp;
  int i;
  fp = fopen(FILENAME, "w");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }
  fprintf(fp, "%d\n", d->count);
  for (i = 0; i < d->count; i++) {
    fprintf(fp, "%s\n%s\n%s\n", d->entries[i].date, d->entries[i].time, d->entries[i].text);
  }
  fclose(fp);
}

void load_entries(struct Diary *d) {
  FILE *fp;
  int i;
  fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    return;
  }
  fscanf(fp, "%d\n", &d->count);
  for (i = 0; i < d->count; i++) {
    fgets(d->entries[i].date, 20, fp);
    strtok(d->entries[i].date, "\n");
    fgets(d->entries[i].time, 20, fp);
    strtok(d->entries[i].time, "\n");
    fgets(d->entries[i].text, MAX_LEN, fp);
    strtok(d->entries[i].text, "\n");
  }
  fclose(fp);
}

int main() {
  struct Diary diary;
  diary.count = 0;
  load_entries(&diary);
  int selection;
  while (1) {
    print_menu();
    scanf("%d", &selection);
    getchar();  // remove trailing newline
    switch (selection) {
      case 1:
        add_entry(&diary);
        break;
      case 2:
        view_entries(&diary);
        break;
      case 3:
        delete_entry(&diary);
        break;
      case 4:
        save_entries(&diary);
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid selection.\n");
        break;
    }
  }
  return 0;
}