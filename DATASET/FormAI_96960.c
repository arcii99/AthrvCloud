//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

//function to convert int to binary string
char* intToBin(int n){
    char* bits = malloc(8*sizeof(char));
    int i=7;
    while(i>=0){
        if (n%2 == 0)
            bits[i] = '0';
        else
            bits[i] = '1';
        n /= 2;
        i--;
    }
    return bits;
}

int main(){
    char msg[1000];
    int fdin = open("input.bmp", O_RDONLY);  //open input file
    int fdout = open("output.bmp", O_WRONLY | O_CREAT, 0644);  //open output file

    if (fdin < 0 || fdout < 0){  //check if files opened properly
        printf("File not found\n");
        exit(1);
    }

    for (int i=0;i<54;i++){  //read and write the header bytes to output
        char byte;
        read(fdin, &byte, 1);
        write(fdout, &byte, 1);
    }

    printf("Enter the message to hide:\n");
    fgets(msg, 1000, stdin);

    int len = strlen(msg);
    int size = lseek(fdin, 0, SEEK_END);  //size of input file

    if(len*8 > size-54){  //check if message can be stored within image
        printf("Image file too small to hide message\n");
        exit(1);
    }

    lseek(fdin, 54, SEEK_SET);  //go to pixel data in input file
    lseek(fdout, 54, SEEK_SET);  //go to pixel data in output file

    for (int i=0;i<len;i++){
        for (int j=0;j<8;j++){
            char c;
            read(fdin, &c, 1);  //read a byte from input file
            char* bits = intToBin((int)c);  //get binary string of byte
            bits[7] = msg[i] & (int)pow(2,j) ? '1' : '0';  //store message bits in last bit of byte
            c = strtol(bits, NULL, 2);  //get new byte
            write(fdout, &c, 1);  //write new byte to output file
            free(bits);
        }
    }

    printf("Message hidden successfully!\n");

    close(fdin);
    close(fdout);

    return 0;
}