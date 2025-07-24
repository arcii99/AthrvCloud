//FormAI DATASET v1.0 Category: File system simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILES 20

struct file {
   char name[20];
   char data[MAX_FILE_SIZE];
};

struct file_system {
   struct file files[MAX_FILES];
   int num_files;
};

void clear_input() {
   int c;
   while((c = getchar()) != '\n' && c != EOF);
}

void create_file(struct file_system *fs) {
   if(fs->num_files == MAX_FILES) {
      printf("File system is full, cannot create more files.\n");
      return;
   }

   printf("Enter file name: ");
   char name[20];
   fgets(name, 20, stdin);
   name[strcspn(name, "\n")] = 0;

   for(int i=0; i<fs->num_files; i++) {
      if(strcmp(fs->files[i].name, name) == 0) {
         printf("A file with this name already exists.\n");
         return;
      }
   }

   printf("Enter file data: ");
   fgets(fs->files[fs->num_files].data, MAX_FILE_SIZE, stdin);
   fs->files[fs->num_files].data[strcspn(fs->files[fs->num_files].data, "\n")] = 0;

   strncpy(fs->files[fs->num_files].name, name, 20);
   printf("File created successfully.\n");
   fs->num_files += 1;
}

void delete_file(struct file_system *fs) {
   printf("Enter file name to delete: ");
   char name[20];
   fgets(name, 20, stdin);
   name[strcspn(name, "\n")] = 0;

   for(int i=0; i<fs->num_files; i++) {
      if(strcmp(fs->files[i].name, name) == 0) {
         for(int j=i; j<fs->num_files-1; j++) {
            fs->files[j] = fs->files[j+1];
         }
         fs->num_files -= 1;
         printf("File deleted successfully.\n");
         return;
      }
   }
   printf("File not found.\n");
}

void display_files(struct file_system *fs) {
   if(fs->num_files == 0) {
      printf("No files found.\n");
      return;
   }

   for(int i=0; i<fs->num_files; i++) {
      printf("%s: %s\n", fs->files[i].name, fs->files[i].data);
   }
}

int main() {
   struct file_system fs = {0};
   printf("Welcome to the file system simulator.\n");
   char command = '\0';

   while(command != 'q') {
      printf("Enter a command (c - create a file, d - delete a file, l - list files, q - quit): ");
      scanf("%c", &command);
      clear_input();

      switch(command) {
         case 'c':
            create_file(&fs);
            break;
         case 'd':
            delete_file(&fs);
            break;
         case 'l':
            display_files(&fs);
            break;
         case 'q':
            printf("Quitting program.\n");
            break;
         default:
            printf("Invalid command.\n");
            break;
      }
   }
   return 0;
}