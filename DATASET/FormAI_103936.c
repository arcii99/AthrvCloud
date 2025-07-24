//FormAI DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct record {
  char name[20];
  int age;
  double salary;
} Record;

int main() {
  Record records[3] = {
    {"John Doe", 25, 25000.00},
    {"Jane Smith", 30, 35000.00},
    {"Bob Johnson", 40, 45000.00}
  };

  // Writing records to file
  FILE* file = fopen("records.dat", "wb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fwrite(records, sizeof(Record), 3, file);
  fclose(file);

  // Reading records from file
  file = fopen("records.dat", "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  Record retrieved_records[3];

  fread(retrieved_records, sizeof(Record), 3, file);
  fclose(file);

  // Printing retrieved records
  for (int i = 0; i < 3; i++) {
    printf("Record %d:\n", i + 1);
    printf("Name: %s\n", retrieved_records[i].name);
    printf("Age: %d\n", retrieved_records[i].age);
    printf("Salary: %.2f\n", retrieved_records[i].salary);
    printf("\n");
  }

  return 0;
}