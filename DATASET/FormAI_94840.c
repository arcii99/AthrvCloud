//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

struct Member {
   int id;
   char name[50];
   int age;
   float salary;
};

int main() {
   struct Member member1;
   member1.id = 1;
   strcpy(member1.name, "John Smith");
   member1.age = 35;
   member1.salary = 5000.00;

   struct Member member2;
   member2.id = 2;
   strcpy(member2.name, "Mary Johnson");
   member2.age = 28;
   member2.salary = 3500.00;

   struct Member member3;
   member3.id = 3;
   strcpy(member3.name, "Bill Wilson");
   member3.age = 42;
   member3.salary = 7000.00;

   // Saving members to a database
   FILE *file;
   file = fopen("members.db", "wb");
   if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
   }
   fwrite(&member1, sizeof(struct Member), 1, file);
   fwrite(&member2, sizeof(struct Member), 1, file);
   fwrite(&member3, sizeof(struct Member), 1, file);
   fclose(file);

   // Retrieving members from the database
   file = fopen("members.db", "rb");
   if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
   }
   struct Member members[3];
   fread(members, sizeof(struct Member), 3, file);
   fclose(file);

   // Printing all members
   printf("All members:\n");
   for (int i = 0; i < 3; i++) {
      printf("ID: %d\n", members[i].id);
      printf("Name: %s\n", members[i].name);
      printf("Age: %d\n", members[i].age);
      printf("Salary: %.2f\n", members[i].salary);
      printf("\n");
   }

   // Finding a member by ID
   int memberId = 2;
   struct Member foundMember;
   for (int i = 0; i < 3; i++) {
      if (members[i].id == memberId) {
         foundMember = members[i];
         break;
      }
   }
   printf("Found member:\n");
   printf("ID: %d\n", foundMember.id);
   printf("Name: %s\n", foundMember.name);
   printf("Age: %d\n", foundMember.age);
   printf("Salary: %.2f\n", foundMember.salary);
   printf("\n");

   // Updating a member
   memberId = 1;
   for (int i = 0; i < 3; i++) {
      if (members[i].id == memberId) {
         members[i].salary = 5500.00;
         break;
      }
   }

   // Saving updated members to the database
   file = fopen("members.db", "wb");
   if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
   }
   fwrite(members, sizeof(struct Member), 3, file);
   fclose(file);

   // Printing all members after update
   printf("All members after update:\n");
   for (int i = 0; i < 3; i++) {
      printf("ID: %d\n", members[i].id);
      printf("Name: %s\n", members[i].name);
      printf("Age: %d\n", members[i].age);
      printf("Salary: %.2f\n", members[i].salary);
      printf("\n");
   }

   return 0;
}