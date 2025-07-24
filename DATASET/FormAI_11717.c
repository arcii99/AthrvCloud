//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include<stdio.h>
#include<time.h>

//Function to print current date and time
void printDateTime(){
   time_t now;//Create time object
   time(&now);//Get time
   printf("Time: %s", ctime(&now));//Print time in readable format
}

int main(){

   char fileName[50];//To store file name
   char content[500];//To store content of diary
   FILE *fp;//File pointer


   printf("Enter file name: ");
   scanf("%s", fileName);//Get file name from user

   fp = fopen(fileName, "a");//Open file in append mode

   if(fp == NULL){//Check if file exists
      printf("Error opening file.\n");
      return 1;
   }

   printf("Enter diary contents:\n");
   scanf(" %[^\n]s", content);//Get diary content from user
   fprintf(fp, "Date: ");//Write date of diary entry
   printDateTime();
   fprintf(fp, "%s\n", content);//Write content to file
   printf("Entry added successfully!\n");
   fclose(fp);//Close file
   return 0;
}