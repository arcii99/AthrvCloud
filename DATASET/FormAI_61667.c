//FormAI DATASET v1.0 Category: Digital Diary ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ENTRIES 100

struct diary_entry {
   int day;
   int month;
   int year;
   char entry_text[100];
};

struct diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

int main() {
   int choice;
   while(1) {
      printf("\n\n\n");
      printf("Welcome to My Digital Diary! \n");
      printf("What do you want to do? \n");
      printf("\t1. Add an entry\n");
      printf("\t2. Read entries\n");
      printf("\t3. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);

      switch(choice) {
         case 1:
            add_entry();
            break;
         case 2:
            read_entries();
            break;
         case 3:        
            printf("Goodbye.\n");
            exit(0);
         default:
            printf("Invalid choice. Try again.");
      }
   }
}

void add_entry() {
   printf("\n\n\n");
   printf("Enter Date (dd mm yyyy): ");
   scanf("%d%d%d",&diary[num_entries].day,&diary[num_entries].month,&diary[num_entries].year);
   printf("Enter Diary Entry (max 100 characters): ");
   scanf("%s",diary[num_entries].entry_text);
   num_entries++;
}

void read_entries() {
   printf("\n\n\n");
   printf("All Entries:\n");
   printf("==================================================\n");
   printf("\t%-12s %-19s %s\n","Date","Time","Entry");
   printf("==================================================\n");
   for(int i=0;i<num_entries;i++) {
      printf("\t%-2d/%-2d/%-4d  ",diary[i].day,diary[i].month,diary[i].year);
      print_time();
      printf("%s\n",diary[i].entry_text);
   }
   printf("==================================================\n");
   printf("Press any key to continue.");
   getchar();  
}

void print_time() {
   time_t rawtime;
   struct tm * timeinfo;
   char buffer [20];
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   strftime (buffer,20,"%H:%M:%S",timeinfo);
   printf("%s ",buffer);
}