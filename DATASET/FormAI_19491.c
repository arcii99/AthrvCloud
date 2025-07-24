//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_HOBBIES_LEN 200
#define MAX_QUERY_LEN 50

typedef struct {
   int id;
   char name[MAX_NAME_LEN+1];
   char hobbies[MAX_HOBBIES_LEN+1];
} Person;

int main() {
   Person people[MAX_RECORDS];
   int num_records = 0;
   char query[MAX_QUERY_LEN+1];

   // Populating the database.
   printf("Populating the database...\n");
   for (int i = 0; i < MAX_RECORDS; i++) {
      Person p;
      p.id = i;
      sprintf(p.name, "Person %d", i+1);
      for (int j = 0; j < 5; j++) {
         char hobby[MAX_HOBBIES_LEN/5+1];
         sprintf(hobby, "Hobby %d", j+1);
         strcat(p.hobbies, hobby);
         if (j != 4) {
            strcat(p.hobbies, ", ");
         }
      }
      people[i] = p;
      num_records++;
   }
   printf("Database successfully populated.\n\n");

   // Getting queries from the user.
   while (1) {
      printf("Enter a query (or type \"exit\" to quit): ");
      fgets(query, MAX_QUERY_LEN+1, stdin);
      query[strlen(query)-1] = '\0';

      if (strcmp(query, "exit") == 0) {
         printf("Exiting program...\n");
         break;
      }

      printf("\nSearching for \"%s\"...\n", query);
      int result_count = 0;
      clock_t start_time = clock();
      for (int i = 0; i < num_records; i++) {
         if (strstr(people[i].name, query) != NULL ||
            strstr(people[i].hobbies, query) != NULL) {
            printf("Match found!\n");
            printf("ID: %d\n", people[i].id);
            printf("Name: %s\n", people[i].name);
            printf("Hobbies: %s\n\n", people[i].hobbies);
            result_count++;
         }
      }
      clock_t end_time = clock();

      if (result_count == 0) {
         printf("No matches found.\n");
      } else {
         printf("Search complete. Found %d matches in %.2f seconds.\n\n",
            result_count, (double)(end_time - start_time) / CLOCKS_PER_SEC);
      }
   }

   return 0;
}