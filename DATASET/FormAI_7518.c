//FormAI DATASET v1.0 Category: File handling ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main(){
   FILE *fp1, *fp2;
   char fname1[20], fname2[20], ch;

   printf("Enter the name of file 1 (with extension): ");
   scanf("%s",fname1);

   fp1 = fopen(fname1,"r");
   if(fp1 == NULL){
      printf("Error in opening file 1!");
      exit(1);
   }

   printf("Enter the name of file 2 (with extension): ");
   scanf("%s",fname2);

   fp2 = fopen(fname2,"w");
   if(fp2 == NULL){
      printf("Error in opening file 2!");
      exit(1);
   }

   while((ch=fgetc(fp1))!=EOF){
      fputc(ch,fp2);
   }

   printf("\nContent of file '%s' has been copied to '%s'.\n", fname1, fname2);

   fclose(fp1);
   fclose(fp2);

   return 0;
}