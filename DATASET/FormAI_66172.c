//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include<stdio.h>

int main() {
    char message[100];
    int checksum=0,i;

    printf("Enter message to calculate checksum\n");
    fgets(message, 100, stdin);

    for(i=0;message[i]!='\0';i++) {
        checksum += message[i];
    }

    printf("Checksum: %d",checksum);

    return 0;
}