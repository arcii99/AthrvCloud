//FormAI DATASET v1.0 Category: Ebook reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {

   char book_title[50];
   int num_of_chapters, chapter_num, i;
   int *book_pages;

   printf("Enter the title of the book: ");
   scanf("%s", book_title);

   printf("Enter the number of chapters in the book: ");
   scanf("%d", &num_of_chapters);

   book_pages = (int*) malloc(num_of_chapters * sizeof(int));

   for(i = 0; i < num_of_chapters; i++) {
      printf("Enter the number of pages in chapter %d: ", i+1);
      scanf("%d", &book_pages[i]);
   }

   printf("Which chapter would you like to read (1-%d): ", num_of_chapters);
   scanf("%d", &chapter_num);

   printf("You have chosen chapter %d\n", chapter_num);
   printf("Reading the first %d page(s)...\n\n", book_pages[chapter_num-1]);

   return 0;
}