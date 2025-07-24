//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>

int calculateChecksum(char* message, int messageSize){
    int checksum = 0;
    for(int i=0;i<messageSize;i++){
        checksum += message[i];
    }
    return checksum;
}

int main(){
    char message[] = {'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
    int messageSize = sizeof(message)/sizeof(message[0]);
    int checksum = calculateChecksum(message, messageSize);
    printf("Checksum for message '%s' is %d", message, checksum);
    return 0;
}