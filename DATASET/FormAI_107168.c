//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
   char fileName[20],buff[1024];
   FILE *fp;
   int row=0,col=0;

   printf("Hey there, let's build a CSV reader program that's sure to make you laugh!\n\n");

   printf("Enter the name of the file you want to read (Don't forget the .csv extension): ");
   scanf("%s",fileName);

   fp=fopen(fileName,"r"); // open file

   if(fp==NULL){
      printf("Oops! Could not open file.\n");
      exit(EXIT_FAILURE);
   }
   printf("Great, the file is open!\n\n");

   printf("Reading the contents of the file...\n\n");
   while(fgets(buff,1024,fp)){  // read file
         row++;
         printf("Row %d : ",row);

         for(col=0;col<strlen(buff);col++){
            printf("%c",buff[col]);

            if(buff[col]==',') // joke time
            printf(" *winks* ");
         }
         putchar('\n');
   }

   fclose(fp);  // close file
   printf("\nFile has been successfully read and closed.\n\n");

   return 0;
}