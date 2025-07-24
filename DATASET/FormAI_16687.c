//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h> 

int main() {
   FILE *fp;
   char str[50];
   
   /* Write to file */
   fp = fopen("sherlock.txt", "w+");
   fprintf(fp, "Sherlock Holmes was created by Sir Arthur Conan Doyle in 1887.");
   fclose(fp);

   /* Read from file */
   fp = fopen("sherlock.txt", "r");
   fscanf(fp, "%[^\n]", str);
   printf("%s\n", str);
   fclose(fp);

   /* Append to file */
   fp = fopen("sherlock.txt", "a+");
   fprintf(fp, "The famous detective has become a cultural icon and has been portrayed in countless adaptations, including in movies, TV shows, and video games.");
   fclose(fp);

   /* Read from file again */
   fp = fopen("sherlock.txt", "r");
   fscanf(fp, "%[^\n]", str);
   printf("%s\n", str);
   fclose(fp);
   
   return 0;
}