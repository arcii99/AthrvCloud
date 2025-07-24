//FormAI DATASET v1.0 Category: File system simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Welcome to the hilarious C File System Simulation Example Program
// This program simulates a file system that is completely disorganized.

// First, let's define our file struct
typedef struct file {
    char* name;
    int size;
} File;

// Now, let's define our main method
int main() {

    // Let's declare our file system with an arbitrary number of files
    File files[10];
    
    // Let's assign some random file names and sizes
    files[0].name = "cat_video.mp4";
    files[0].size = 100;

    files[1].name = "homework.docx";
    files[1].size = 50;

    files[2].name = "selfie.png";
    files[2].size = 20;

    files[3].name = "pizza_recipe.txt";
    files[3].size = 5;

    files[4].name = "poetry_collection.txt";
    files[4].size = 200;

    files[5].name = "game.exe";
    files[5].size = 150;

    files[6].name = "taxes.xlsx";
    files[6].size = 75;

    files[7].name = "art_gallery.psd";
    files[7].size = 300;

    files[8].name = "instagram_filter.png";
    files[8].size = 10;

    files[9].name = "grocery_list.doc";
    files[9].size = 5;

    // Now, let's randomly shuffle the file system to simulate disorganization
    for(int i = 0; i < 10; i++) {
        int randomIndex = rand() % 10;
        File tempFile = files[randomIndex];
        files[randomIndex] = files[i];
        files[i] = tempFile;
    }

    // Now, let's print out our disorganized file system
    printf("Welcome to the Disorganized File System!\n");
    for(int i = 0; i < 10; i++) {
        printf("File %d: %s (%d bytes)\n", i+1, files[i].name, files[i].size);
    }

    // Uh oh, our file system is completely disorganized! Good luck finding what you need!

    return 0;
}