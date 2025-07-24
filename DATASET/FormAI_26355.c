//FormAI DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Surrealist File Backup System */

int main(){

    srand(time(0));

    /* Define file names */
    char *file1 = "The_Toms_Dilemma.txt";
    char *file2 = "The_Art_of_Selling_Elevator_Music.mp3";
    char *file3 = "The_Mouse_Experiment.csv";
    char *file4 = "The_Dream_of_the_Lost_Sock.docx";
    char *file5 = "The_Last_Slice_of_Pizza.jpg";

    /* Define folder names */
    char *folder1 = "The_Road_to_Nowhere";
    char *folder2 = "The_Lost_City_of_Atlantis";
    char *folder3 = "The_Maze_of_Mirrors";
    char *folder4 = "The_Tunnel_of_Love";

    /* Create random backup folder names */
    char backup1[20];
    char backup2[20];
    char backup3[20];

    int random1 = rand()%1000;
    int random2 = rand()%1000;
    int random3 = rand()%1000;

    sprintf(backup1, "Backup_%d", random1);
    sprintf(backup2, "Backup_%d", random2);
    sprintf(backup3, "Backup_%d", random3);

    printf("Creating backup folders...\n");
    printf("%s\n%s\n%s\n", backup1, backup2, backup3);

    /* Create folder structures */

    /* Backup 1 */
    printf("Creating folder structure for backup 1...\n");
    char command[100];
    sprintf(command, "mkdir \"%s/%s\"", backup1, folder1);
    system(command);

    sprintf(command, "mkdir \"%s/%s\"", backup1, folder2);
    system(command);

    sprintf(command, "mkdir \"%s/%s\"", backup1, folder3);
    system(command);

    sprintf(command, "mkdir \"%s/%s/%s\"", backup1, folder4, folder3);
    system(command);

    /* Backup 2 */
    printf("Creating folder structure for backup 2...\n");
    sprintf(command, "mkdir \"%s/%s\"", backup2, folder1, folder2);
    system(command);

    sprintf(command, "mkdir \"%s/%s\"", backup2, folder2);
    system(command);

    sprintf(command, "mkdir \"%s/%s/%s\"", backup2, folder3, folder4);
    system(command);

    /* Backup 3 */
    printf("Creating folder structure for backup 3...\n");
    sprintf(command, "mkdir \"%s/%s/%s/%s\"", backup3, folder2, folder3, folder4);
    system(command);

    /* Create backup files */

    printf("Backing up files...\n");

    /* Backup 1 */
    sprintf(command, "cp \"%s\" \"%s/%s/\"", file1, backup1, folder1);
    system(command);

    sprintf(command, "cp \"%s\" \"%s/%s/\"", file2, backup1, folder2);
    system(command);

    sprintf(command, "cp \"%s\" \"%s/%s/\"", file3, backup1, folder3);
    system(command);

    sprintf(command, "cp \"%s\" \"%s/%s/%s/\"", file4, backup1, folder4, folder3);
    system(command);

    /* Backup 2 */
    sprintf(command, "cp \"%s\" \"%s/%s/%s/\"", file1, backup2, folder1, folder2);
    system(command);

    sprintf(command, "cp \"%s\" \"%s/%s/\"", file2, backup2, folder2);
    system(command);

    sprintf(command, "cp \"%s\" \"%s/%s/%s/\"", file3, backup2, folder3, folder4);
    system(command);

    /* Backup 3 */
    sprintf(command, "cp \"%s\" \"%s/%s/%s/%s/\"", file5, backup3, folder2, folder3, folder4);
    system(command);

    printf("Backup complete.\n");

    return 0;
}