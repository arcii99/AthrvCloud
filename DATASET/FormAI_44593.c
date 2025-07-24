//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Internet Speed Test App!\n");
    
    // Randomly generating download and upload speeds between 1 and 100 Mbps
    srand(time(NULL));
    int downloadSpeed = rand() % 100 + 1;
    int uploadSpeed = rand() % 100 + 1;
    
    // Displaying the generated speeds
    printf("Your download speed is %d Mbps\n", downloadSpeed);
    printf("Your upload speed is %d Mbps\n", uploadSpeed);
    
    // Determining the quality of the speeds based on industry standards
    if (downloadSpeed >= 25 && uploadSpeed >= 3) {
        printf("Your speeds are excellent! You can easily stream HD video and play online games.\n");
    }
    else if (downloadSpeed >= 10 && uploadSpeed >= 1) {
        printf("Your speeds are good! You can stream SD video and browse the web without much lag.\n");
    }
    else {
        printf("Your speeds are poor. You may experience buffering and slow load times while using the internet.\n");
    }
    
    // Prompting the user to retest their speeds or exit the program
    printf("\nWould you like to retest your speeds? (Y/N): ");
    char response;
    scanf(" %c", &response);
    
    if (response == 'Y' || response == 'y') {
        // Recursively calling the main function to retest speeds
        main();
    }
    else {
        printf("Thank you for using the Internet Speed Test App!\n");
        return 0;
    }
}