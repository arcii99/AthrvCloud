//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

typedef struct {
   int id;
   char name[20];
   char address[50];
} Record;

typedef struct {
   Record arr[MAX];
   int last;  
} Index;

void addRecord(Index *index, Record record) {
   if(index->last == MAX-1) {
      printf("Error: Database is full.\n");
      return;
   }
   index->last++;
   index->arr[index->last] = record;
}

int searchById(Index index, int id) {
   for(int i=0; i<=index.last; i++) {
      if(index.arr[i].id == id) {
         return i;
      }
   }
   return -1;
}

void displayRecord(Record record) {
   printf("%-5d%-20s%-50s\n", record.id, record.name, record.address);
}

void displayIndex(Index index) {
   printf("%-5s%-20s%-50s\n", "ID", "Name", "Address");
   for(int i=0; i<=index.last; i++) {
      displayRecord(index.arr[i]);
   }
}

int main() {
   Index index = {.last=-1};
   int choice, id, indexPos;
   Record record;
   
   while(1) {
      printf("\nPlease select an option:\n");
      printf("1. Add a record\n2. Search by ID\n3. Display all records\n4. Exit\n>");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            printf("Enter ID, Name, and Address (separated by commas):\n>");
            scanf("%d %[^,] %*c %[^\n]", &record.id, record.name, record.address);
            addRecord(&index, record);
            break;
         case 2:
            printf("Enter an ID to search:\n>");
            scanf("%d", &id);
            indexPos = searchById(index, id);
            if(indexPos == -1) {
               printf("No record with ID %d\n", id);
            } else {
               displayRecord(index.arr[indexPos]);
            }
            break;
         case 3:
            displayIndex(index);
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid choice. Please try again.\n");
      }
   }
   
   return 0;
}