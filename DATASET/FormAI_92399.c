//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct csv_data {
  char name[100];
  char address[100];
  char phone_num[50];
};

struct csv_data parse_csv_line(char* line) {
  struct csv_data data;

  char* token = strtok(line, ",");
  strcpy(data.name, token);

  token = strtok(NULL, ",");
  strcpy(data.address, token);

  token = strtok(NULL, ",");
  strcpy(data.phone_num, token);

  return data;
}

int main() {
  FILE* fp = fopen("data.csv", "r");
  char line[150];
  struct csv_data data;

  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  printf("Name\t Address\t Phone Number\n");
  printf("------------------------------------------\n");

  // reading csv file line by line
  while (fgets(line, 150, fp) != NULL) {
    // parse csv data into struct
    data = parse_csv_line(line);
    // print the data
    printf("%s\t %s\t %s\n", data.name, data.address, data.phone_num);
  }

  fclose(fp);
  return 0;
}