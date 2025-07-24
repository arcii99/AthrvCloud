//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>

void weird_query(char* table_name, char* desired_column, char* condition) {

   printf("Initiating database query...\n");
   
   printf("Accessing table %s...\n", table_name);
   
   printf("Extracting %s data...\n", desired_column);
   
   printf("Searching for entries that fulfill the condition \"%s\"...\n", condition);
   
   printf("Commencing task of finding pink elephants reading Shakespeare...\n");
   
   printf("Processing information...\n");
   
   printf("Cross-referencing elephant sightings with Shakespearean quotes...\n");
   
   printf("The results are as follows:\n");
   
   printf("\n");
   
   printf("----------------------------------------------------\n");
   printf("|          Pink Elephants reading Shakespeare       |\n");
   printf("----------------------------------------------------\n");
   printf("|             Dumbo       |       Hamlet            |\n");
   printf("----------------------------------------------------\n");
   printf("|             Jumbo       |      Macbeth            |\n");
   printf("----------------------------------------------------\n");
   printf("|         Mr. Jingles     |       Othello           |\n");
   printf("----------------------------------------------------\n");
   printf("|           Babar         |       King Lear         |\n");
   printf("----------------------------------------------------\n");
   
   printf("\n");
   printf("Completed query successfully.\n");
}

int main() {
   
   printf("Welcome to the Surrealist Database Query Program!\n");
   
   char* table = "elephant_bookclub";
   char* column = "book_title";
   char* condition = "color = 'pink'";
   
   weird_query(table, column, condition);
   
   return 0;
}