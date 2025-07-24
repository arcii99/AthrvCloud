//FormAI DATASET v1.0 Category: QR code reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_CODE_MAX_SIZE 1000    // set a maximum size for the input QR code to prevent buffer overflow

/* function to check if the input QR code has a valid format */
bool isValidQRCodeFormat(char* qrCode) {
    int len = strlen(qrCode);
    if (len < 21 || len > QR_CODE_MAX_SIZE) {    // QR code should have at least 21 characters and less than 1000 characters 
        return false;
    }
    
    if (qrCode[0] != '{' || qrCode[len-1] != '}') {    // QR code should start and end with {}
        return false;
    }
    
    bool formatCheck = true;
    int i = 1;
    while (i < len-1) {
        if (qrCode[i] != ':') {    // each key-value pair in the QR code should be separated by :
            formatCheck = false;
            break;
        }
        int j = i+1;
        while (j < len-1 && qrCode[j] != ':') {
            if (qrCode[j] < '0' || qrCode[j] > '9') {    // key in the key-value pair should be numeric
                formatCheck = false;
                break;
            }
            j++;
        }
        if (!formatCheck) {
            break;
        }
        if (j == len-1) {
            formatCheck = false;
            break;
        }
        if (qrCode[j] != ':' || qrCode[j+1] != '\"') {    // after the numeric key should come a : and a "
            formatCheck = false;
            break;
        }
        j += 2;
        while (j < len-1 && qrCode[j] != '\"') {
            j++;
        }
        if (j == len-1) {
            formatCheck = false;
            break;
        }
        if (qrCode[j] != '\"' || qrCode[j+1] != ',') {    // after the value of the key-value pair should come a " and a ,
            formatCheck = false;
            break;
        }
        i = j+2;
    }

    return formatCheck;
}

/* function to extract the value for a given key from the input QR code */
char* getValueForQRCodeKey(char* qrCode, int key) {
    if (!isValidQRCodeFormat(qrCode)) {
        printf("Invalid QR Code format\n");
        exit(1);
    }
    
    char strKey[5];
    sprintf(strKey, "%d", key);
    char* keyStr = malloc(5*sizeof(char));
    strcpy(keyStr, strKey);
    
    int len = strlen(qrCode);
    int i = 1;
    while (i < len-1) {
        if (qrCode[i] != ':') {
            i++;
        }
        else {
            int j = i+1;
            while (j < len-1 && qrCode[j] != ':') {
                j++;
            }
            char* numStr = malloc((j-i)*sizeof(char));
            strncpy(numStr, qrCode+i+1, j-i-1);
            numStr[j-i-1] = '\0';
            int numKey = atoi(numStr);
            free(numStr);
            
            if (numKey == key) {
                int k = j+2;
                while (k < len-1 && qrCode[k] != '\"') {
                    k++;
                }
                char* value = malloc((k-j-2)*sizeof(char));
                strncpy(value, qrCode+j+3, k-j-3);
                value[k-j-3] = '\0';
                return value;
            }
            
            i = j+2;
        }
    }
    
    return NULL;
}

int main() {
    char qrCode[QR_CODE_MAX_SIZE];
    printf("Enter QR code: ");
    fgets(qrCode, QR_CODE_MAX_SIZE, stdin);
    qrCode[strcspn(qrCode, "\n")] = '\0';    // remove newline character from the end of the input
    
    if (!isValidQRCodeFormat(qrCode)) {
        printf("Invalid QR Code format\n");
        exit(1);
    }
    
    printf("QR Code:\n%s\n", qrCode);
    int key;
    printf("Enter key to extract value: ");
    scanf("%d", &key);
    char* value = getValueForQRCodeKey(qrCode, key);
    printf("Value: %s\n", value);
    
    free(value);
    return 0;
}