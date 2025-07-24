//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the exciting C Checksum Calculator!\n");
    printf("This program will generate a unique checksum for your input.\n");
    printf("Please enter your input:\n");

    char input[100];
    scanf("%s", input);

    int sum = 0;
    int n = strlen(input);

    for(int i=0; i<n; i++){
        sum += (int) input[i];
    }

    int checksum = sum%256;

    printf("Your checksum is: %d\n", checksum);

    printf("Thank you for using the C Checksum Calculator! Want to try again? Y/N\n");

    char response[1];
    scanf("%s", response);

    if(response[0] == 'Y' || response[0] == 'y'){
        system("clear");
        main();
    }else{
        printf("Goodbye!\n");
    }

    return 0;
}