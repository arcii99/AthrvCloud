//FormAI DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

void create_index_file(char *filename, int *data)
{
  FILE *fp;

  // Create the index file
  fp = fopen(filename, "w");

  if(fp == NULL)
  {
    printf("Error creating the index file!\n");
    exit(1);
  }

  // Write the data to the index file
  for(int i = 0; i < SIZE; i++)
  {
    fprintf(fp, "%d\n", data[i]);
  }

  fclose(fp);
}

void create_mirror_file(char *filename, int *data)
{
  FILE *fp;

  // Create the mirror file
  fp = fopen(filename, "w");

  if(fp == NULL)
  {
    printf("Error creating the mirror file!\n");
    exit(1);
  }

  // Write the data to the mirror file
  for(int i = 0; i < SIZE; i++)
  {
    fprintf(fp, "%d\n", data[i]);
  }

  fclose(fp);
}

void read_index_file(char *filename, int *data)
{
  FILE *fp;
  char buffer[100];

  // Open the index file
  fp = fopen(filename, "r");

  if(fp == NULL)
  {
    printf("Error opening the index file!\n");
    exit(1);
  }

  // Read the data from the index file
  int i = 0;
  while(fgets(buffer, sizeof(buffer), fp) != NULL)
  {
    data[i++] = atoi(buffer);
  }

  fclose(fp);
}

void read_mirror_file(char *filename, int *data)
{
  FILE *fp;
  char buffer[100];

  // Open the mirror file
  fp = fopen(filename, "r");

  if(fp == NULL)
  {
    printf("Error opening the mirror file!\n");
    exit(1);
  }

  // Read the data from the mirror file
  int i = 0;
  while(fgets(buffer, sizeof(buffer), fp) != NULL)
  {
    data[i++] = atoi(buffer);
  }

  fclose(fp);
}

int main()
{
  int data[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  // Create the index file and the mirror file
  create_index_file("data.txt", data);
  create_mirror_file("data_mirror.txt", data);

  int index_data[SIZE];
  int mirror_data[SIZE];

  // Read the data from the index file and the mirror file
  read_index_file("data.txt", index_data);
  read_mirror_file("data_mirror.txt", mirror_data);

  // Compare the data in the index file and the mirror file
  for(int i = 0; i < SIZE; i++)
  {
    if(index_data[i] != mirror_data[i])
    {
      printf("Data in index file has been tampered with!\n");
      exit(1);
    }
  }

  printf("Data in index file is valid.\n");

  return 0;
}