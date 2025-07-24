//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   int id[10] = {123, 456, 789, 101, 102, 103, 104, 105, 106, 107};
   char names[10][20] = {"The Great Beyond", "The Delicious Abyss", 
                         "The Majestic Sparkle", "The Cosmic Flame",
                         "The Radiant Oracle", "The Mystic Portal", 
                         "The Enormous Void", "The Glittering Blackness",
                         "The Shining Abyss", "The Blissful Universe"};
   char colors[10][20] = {"Shimmering Turquoise", "Sparkling Silver", 
                          "Glimmering Gold", "Twinkling Topaz",
                          "Radiant Ruby", "Luminous Lavender", 
                          "Blazing Bronze", "Glittering Green",
                          "Sapphire Sky", "Opulent Onyx"};
   float prices[10] = {10.00, 8.50, 12.25, 9.75, 11.00, 
                       8.00, 7.50, 15.50, 10.50, 13.75};
                           
   printf("Welcome to the Surrealist Database!\n\n");
   printf("Enter a color to search for a product:\n");
   char search[20];
   scanf("%s", search);
   
   int found = 0;
   int i;
   for(i = 0; i < 10; i++) {
       if(strcmp(search, colors[i]) == 0) {
           found = 1;
           printf("\nProduct ID: %d\n", id[i]);
           printf("Product Name: %s\n", names[i]);
           printf("Product Color: %s\n", colors[i]);
           printf("Product Price: $%.2f\n", prices[i]);
           break;
       }
   }
   
   if(!found) {
       printf("\nSorry, we couldn't find anything in that color. How about a different color?\n");
   }
 
   return 0;
}