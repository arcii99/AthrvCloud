//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Brave Internet Speed Test App!\n");
    printf("Testing your internet speed...\n");
    srand(time(NULL)); // seed the random number generator with the current time
    
    int download = rand() % 101; // generate a random download speed between 0 and 100 Mbps
    int upload = rand() % 101; // generate a random upload speed between 0 and 100 Mbps
    int ping = rand() % 101; // generate a random ping time between 0 and 100 ms
    
    printf("Download Speed: %d Mbps\n", download);
    printf("Upload Speed: %d Mbps\n", upload);
    printf("Ping Time: %d ms\n", ping);
    
    printf("Do you want to save your results? (y/n): ");
    char save;
    scanf("%c", &save); // get user input for whether they want to save their results or not
    
    if (save == 'y' || save == 'Y') {
        printf("Please enter a file name to save your results: ");
        char file_name[100];
        scanf("%s", file_name); // get user input for the file name to save the results
        
        FILE *fp = fopen(file_name, "w"); // open the file for writing
        
        if (fp != NULL) {
            fprintf(fp, "Download Speed: %d Mbps\n", download);
            fprintf(fp, "Upload Speed: %d Mbps\n", upload);
            fprintf(fp, "Ping Time: %d ms\n", ping);
            fclose(fp); // close the file
            printf("Results saved to file: %s.\n", file_name);
        } else {
            printf("Error opening file.\n");
        }
    }
    
    printf("Thank you for using the Brave Internet Speed Test App!\n");
    return 0;
}