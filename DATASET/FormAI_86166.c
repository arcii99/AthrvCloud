//FormAI DATASET v1.0 Category: DOS detector ; Style: dynamic
#include<stdio.h>
#include<string.h>

int main() {
    char name[50];
    int age;
    int detected = 0;
    char virus[10][10] = {"dos", "trojan", "worm"}; // list of commonly known DOS viruses
    char *ptr;

    printf("Welcome to our DOS detector program!\n");
    printf("Please enter your name: ");
    fgets(name, 50, stdin); // read user input
    name[strcspn(name, "\n")] = 0; // remove newline character

    printf("Hello %s, please enter your age: ", name);
    scanf("%d", &age); // read user input

    printf("Thank you for providing your information.\n");
    printf("We will now scan your device for any DOS viruses...\n\n");

    // perform virus scan for each virus in the list
    for(int i = 0; i < sizeof(virus)/sizeof(virus[0]); i++) {
        ptr = strstr(name, virus[i]); // check if virus name exists in user's name
        if(ptr != NULL) {
            detected = 1; // set detected flag to true
            break; // stop scanning if virus is detected
        }
    }

    if(detected == 1) {
        printf("ALERT: We have detected a possible DOS virus in your name!\n");
    } else {
        printf("No DOS viruses detected. Your device is safe.\n");
    }

    return 0;
}