//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record {
   int id;
   char name[20];
   char address[50];
   int age;
};

struct index {
   int key;
   int rec_no;
} index_table[50];

int main() {

   struct record records[50];
   int i, j, n = 0;

   // Populate records
   for(i = 0; i < 50; i++) {
      records[i].id = i + 1;
      sprintf(records[i].name, "Name%d", i + 1);
      sprintf(records[i].address, "Address%d", i + 1);
      records[i].age = 20 + i;
      n++;
   }

   // Initialize index table
   for(i = 0; i < n; i++) {
      index_table[i].key = records[i].id;
      index_table[i].rec_no = i;
   }

   // Sort index table
   for(i = 0; i < n-1; i++)
      for(j = i+1; j < n; j++)
         if(index_table[i].key > index_table[j].key) {
            struct index temp = index_table[i];
            index_table[i] = index_table[j];
            index_table[j] = temp;
         }

   int key;
   printf("Enter the ID to search: ");
   scanf("%d", &key);

   // Binary search
   int low = 0, high = n-1, mid, found = 0;
   while(low <= high) {
      mid = (low + high) / 2;
      if(key == index_table[mid].key) {
         printf("Record found:\n");
         printf("ID: %d\n", records[index_table[mid].rec_no].id);
         printf("Name: %s\n", records[index_table[mid].rec_no].name);
         printf("Address: %s\n", records[index_table[mid].rec_no].address);
         printf("Age: %d\n", records[index_table[mid].rec_no].age);
         found = 1;
         break;
      }
      else if(key > index_table[mid].key)
         low = mid + 1;
      else
         high = mid - 1;
   }

   if(!found)
      printf("Record not found!\n");

   return 0;
}