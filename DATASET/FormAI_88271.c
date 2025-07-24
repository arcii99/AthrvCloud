//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records and fields
#define MAX_RECORDS 1000
#define MAX_FIELDS 10

// Define the data structure for a record
typedef struct {
  char fields[MAX_FIELDS][50];
} Record;

int main() {
  // Declare variables to hold record and field data
  Record records[MAX_RECORDS];
  char field_names[MAX_FIELDS][50];
  int num_fields = 0;
  int num_records = 0;

  // Read in the field names from the user
  printf("Enter field names (separated by commas):\n");
  char field_input[500];
  fgets(field_input, 500, stdin);

  // Parse the input string to extract the field names
  char* token = strtok(field_input, ",");
  while(token != NULL) {
    strcpy(field_names[num_fields], token);
    num_fields++;
    token = strtok(NULL, ",");
  }

  // Read in the record data from a file
  FILE* data_file = fopen("data.txt", "r");
  if(data_file == NULL) {
    printf("Unable to read data file!\n");
    return 1;
  }
  char buffer[500];
  while(fgets(buffer, 500, data_file)) {
    // Parse the input string to extract the field values
    token = strtok(buffer, ",");
    int i = 0;
    while(token != NULL) {
      strcpy(records[num_records].fields[i], token);
      i++;
      token = strtok(NULL, ",");
    }
    num_records++;
  }
  fclose(data_file);

  // Print out the data table
  printf("\n%s\n", "===========================");
  for(int i=0; i<num_fields; i++) {
    printf("%-20s", field_names[i]);
  }
  printf("\n%s\n", "===========================");
  for(int i=0; i<num_records; i++) {
    for(int j=0; j<num_fields; j++) {
      printf("%-20s", records[i].fields[j]);
    }
    printf("\n");
  }
  printf("%s\n", "===========================");

  // Find the average value for a specified field
  char search_field[50];
  printf("Enter field name to calculate average:\n");
  scanf("%s", search_field);
  int field_index = -1;
  for(int i=0; i<num_fields; i++) {
    if(strcmp(field_names[i], search_field) == 0) {
      field_index = i;
      break;
    }
  }
  if(field_index == -1) {
    printf("Invalid field name!\n");
    return 1;
  }
  double sum = 0.0;
  for(int i=0; i<num_records; i++) {
    sum += atof(records[i].fields[field_index]);
  }
  double average = sum / num_records;
  printf("The average value of %s is %lf\n", search_field, average);

  return 0;
}