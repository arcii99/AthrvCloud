//FormAI DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   char file[100],nfile[100], c;
   FILE *fptr1, *fptr2;
   
   printf("Enter the file name: ");
   fgets(file, 100, stdin);
   
   file[strcspn(file, "\n")] = 0; //removing newline char
   
   fptr1 = fopen(file, "r");
   if (fptr1 == NULL) {
      printf("Error! File doesn't exist.");
      exit(1);
   }

   printf("Enter the new file name: ");
   fgets(nfile, 100, stdin);
   nfile[strcspn(nfile, "\n")] = 0;
   fptr2 = fopen(nfile, "w");

   while ((c = fgetc(fptr1)) != EOF) {
      fputc(c, fptr2);
   }

   printf("\nCopying contents of %s to %s", file, nfile);
   
   fclose(fptr1);
   fclose(fptr2);

   printf("\nFile copied!");

   printf("\n\nChanging permissions of %s to 777\n",nfile);
   chmod(nfile, 0777);

   printf("\nChecking file size of %s",file);
   printf("\nSize of %s : ", file);
   system("wc -c < file"); //system call

   printf("\nChanging owner of %s to root\n",nfile);
   chown(nfile, 0, 0);

   printf("\nCreating a hard link for %s\n",file);
   char cmd[100];
   sprintf(cmd, "ln %s %s.link", file, file);
   system(cmd);

   printf("\nCopying the file %s to /usr/bin\n",file);
   char cmd1[100];
   sprintf(cmd1, "sudo cp %s /usr/bin", file);
   system(cmd1);

   printf("\nCreating a symbolic link for %s\n", file);
   char cmd2[100];
   sprintf(cmd2, "sudo ln -s %s testlink", file);
   system(cmd2);

   return 0;
}