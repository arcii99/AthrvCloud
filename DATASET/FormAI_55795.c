//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_SIZE 50

typedef struct {
  int id;
  char name[MAX_NAME_SIZE];
  int age;
} Record;

typedef struct {
  int id;
  int index;
} Index;

void createIndex(Record* records, Index* indexArr, int numRecords) {
  // create index based on record IDs
  for (int i = 0; i < numRecords; i++) {
    indexArr[i].id = records[i].id;
    indexArr[i].index = i;
  }
}

int binarySearch(Index* indexArr, int numRecords, int searchID) {
  // perform binary search on the index array
  int start = 0;
  int end = numRecords - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (indexArr[mid].id == searchID) {
      return indexArr[mid].index;
    } else if (indexArr[mid].id < searchID) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1; // ID not found
}

int main() {
  Record records[MAX_RECORDS] = {{1, "John", 25}, {2, "Alice", 30}, {3, "Bob", 35}};
  Index indexArr[MAX_RECORDS];
  int numRecords = 3;

  createIndex(records, indexArr, numRecords);

  int searchID = 2;
  int index = binarySearch(indexArr, numRecords, searchID);

  if (index != -1) {
    printf("Record found: %s %d\n", records[index].name, records[index].age);
  } else {
    printf("Record not found\n");
  }

  return 0;
}