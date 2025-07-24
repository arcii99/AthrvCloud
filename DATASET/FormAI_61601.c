//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>

struct file {
   char fileName[100];
   char fileType[10];
   int fileSize;
};

struct folder {
   char folderName[100];
   int numFiles;
   struct file files[50];
};

struct drive {
   char driveName[10];
   int numFolders;
   struct folder folders[50];
};

int main() {
   int choice, countDrives = 0, countFolders = 0, countFiles = 0;
   struct drive drives[10];

   do {
      printf("1. Create New Drive\n2. Create New Folder\n3. Create New File\n4. Display\n5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Enter name for new drive: ");
            scanf("%s", drives[countDrives].driveName);
            countFolders = 0;
            countFiles = 0;
            countDrives++;
            break;

         case 2:
            printf("Enter name for new folder: ");
            scanf("%s", drives[countDrives-1].folders[countFolders].folderName);
            drives[countDrives-1].numFolders++;
            countFiles = 0;
            countFolders++;
            break;

         case 3:
            printf("Enter name for new file: ");
            scanf("%s", drives[countDrives-1].folders[countFolders-1].files[countFiles].fileName);
            printf("Enter file type: ");
            scanf("%s", drives[countDrives-1].folders[countFolders-1].files[countFiles].fileType);
            printf("Enter file size: ");
            scanf("%d", &drives[countDrives-1].folders[countFolders-1].files[countFiles].fileSize);
            drives[countDrives-1].folders[countFolders-1].numFiles++;
            countFiles++;
            break;

         case 4:
            printf("Drives:\n");
            for(int i = 0; i < countDrives; i++) {
               printf("- %s\n", drives[i].driveName);
            }
            printf("\n");

            printf("Folders in %s:\n", drives[countDrives-1].driveName);
            for(int i = 0; i < countFolders; i++) {
               printf("- %s\n", drives[countDrives-1].folders[i].folderName);
            }
            printf("\n");

            printf("Files in %s:\n", drives[countDrives-1].folders[countFolders-1].folderName);
            for(int i = 0; i < countFiles; i++) {
               printf("- %s.%s (%d bytes)\n", drives[countDrives-1].folders[countFolders-1].files[i].fileName, drives[countDrives-1].folders[countFolders-1].files[i].fileType, drives[countDrives-1].folders[countFolders-1].files[i].fileSize);
            }
            printf("\n");
            break;

         case 5:
            printf("Exiting...\n");
            break;

         default:
            printf("Invalid choice. Try again.\n");
            break;
      }
   } while(choice != 5);

   return 0;
}