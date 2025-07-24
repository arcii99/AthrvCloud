//FormAI DATASET v1.0 Category: QR code generator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    char qr_data[200];
    char command[250];
    char output_file_name[30] = "qr_code.png";

    // check if data is provided or not
    if(argc < 2) {
        printf("Please provide some data to generate QR code");
        exit(1);
    } else {
        // read the input data and store it in qr_data variable
        strcpy(qr_data, argv[1]);
    }

    // create the command to generate QR code using qrencode library
    sprintf(command, "qrencode -o %s \"%s\"", output_file_name, qr_data);

    // execute the command using system function
    system(command);

    printf("QR code generated successfully!\n");
    printf("Check %s file in current directory\n", output_file_name);

    return 0;
}