//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
// This is a Mathematical Style Intrusion Detection System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_LEN 1024

int main(int argc, char** argv) {

    // initialize variables
    int count = 0;
    char buf[MAX_BUF_LEN];

    // prompt user for input
    printf("Please enter the password: ");

    // read input from user
    fgets(buf, MAX_BUF_LEN, stdin);

    // strip newline character from input
    buf[strlen(buf)-1] = '\0';

    // apply mathematical formula to input
    for (int i = 0; i < strlen(buf); i++) {
        count += ((int)buf[i] * 31) ^ (i+1);
    }

    // check if input matches correct password
    if (count == 203614328) {
        printf("Access granted!\n");
    } else {
        printf("Access denied!\n");
    }

    // exit program
    return 0;
}