//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[20], search[20], line[100];
    int line_num = 0, match = 0;
    
    printf("Welcome to The Great File Hunter. Can I help you?\n\n");
    printf("Please enter the name of the file to search (e.g: clues.txt): ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Sorry , I was not able to find the file. Try again with correct file name.\n");
        return 1;
    }
    
    printf("\nWhat is the word you are looking for? ");
    scanf("%s", search);
    
    while(fgets(line, sizeof(line), file)) {
        line_num++;
        
        if(strstr(line, search) != NULL) {
            printf("\nI have found a match for '%s' in line %d.\n", search, line_num);
            printf("The sentence that matches is: %s\n", line);
            match++;
        }
    }
    
    if (match == 0) {
        printf("\nI am sorry, there is no match found for '%s'.\n", search);
    } else {
        printf("\nCongratulations, I found %d matches for '%s'.\n", match, search);
    }
    
    fclose(file);
    
    printf("\nThank you for using The Great File Hunter.\n");
    return 0;
}