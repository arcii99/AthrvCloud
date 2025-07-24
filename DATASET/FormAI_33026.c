//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readQRCode(char* qrContent){
    printf("Please scan the QR code: ");
    scanf("%s", qrContent);
    printf("Analyzing the QR code...\n");
    int len = strlen(qrContent);
    if (len < 3){
        printf("The QR code is too short to be a valid clue.\n");
        return 0;
    }
    else{
        int i, j, k;
        for (i = 0; i < len; i++){
            if (qrContent[i] == 'C' || qrContent[i] == 'c'){
                for (j = i+1; j < len; j++){
                    if (qrContent[j] == 'O' || qrContent[j] == 'o'){
                        for (k = j+1; k < len; k++){
                            if (qrContent[k] == 'D' || qrContent[k] == 'd'){
                                printf("The QR code reveals a code: ");
                                int code = 0;
                                for (int m = k+1; m < len; m++){
                                    if (qrContent[m] >= '0' && qrContent[m] <= '9'){
                                        code = (code * 10) + (qrContent[m] - '0');
                                    }
                                }
                                printf("%d\n", code);
                                return code;
                            }
                        }
                    }
                }
            }
        }
        printf("The QR code does not contain any useful information.\n");
        return 0;
    }
}

int main(){
    printf("Welcome to the QR code reader program, Mr. Holmes.\n");
    char qrContent[100];
    int clue1 = readQRCode(qrContent);
    if (clue1 == 0){
        printf("Sorry, we cannot proceed without the first clue.\n");
    }
    else{
        printf("Excellent! The first clue leads us to the ");
        if (clue1 % 2 == 0){
            printf("east ");
        }
        else{
            printf("west ");
        }
        printf("of the city. Let's move on to the next clue, shall we?\n");
        int clue2 = readQRCode(qrContent);
        if (clue2 == 0){
            printf("Sorry, we cannot proceed without the second clue.\n");
        }
        else{
            printf("Great job, Mr. Holmes! The second clue points to the ");
            if (clue2 > 50){
                printf("north ");
            }
            else{
                printf("south ");
            }
            printf("of the city. Now we are getting somewhere.\n");
            int clue3 = readQRCode(qrContent);
            if (clue3 == 0){
                printf("Sorry, we cannot proceed without the third clue.\n");
            }
            else{
                printf("Fantastic, Mr. Holmes! The third clue is a numeric code: %d\n", clue3);
                printf("Let's see if it matches the combination lock of the warehouse.\n");
                if (clue3 == 2219){
                    printf("Bingo! We have found the stolen diamonds. You always amaze me, Mr. Holmes.\n");
                }
                else{
                    printf("Alas, the code does not match. We have to keep looking.\n");
                }
            }
        }
    }
    return 0;
}