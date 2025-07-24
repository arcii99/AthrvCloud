//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include<stdio.h>
#include<math.h>

//function to convert ASCII character to binary
void convertCharToBinary(char c, int binary[]){
    int i=7;
    while(i>=0){
        binary[i]=c%2;
        c=c/2;
        i--;
    }
}

//function to convert binary to ASCII character
char convertBinaryToChar(int binary[]){
    int i, sum=0;
    for(i=7;i>=0;i--){
        sum+=binary[i]*pow(2,7-i);
    }
    return (char)sum;
}

//function to hide the message in the image
void hideMessage(int image[][8], char message[]){
    int i, j, k=0, binary[8];
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            convertCharToBinary(message[k], binary);
            image[i][j] = (image[i][j] & 254) | binary[0];
            image[i][j+1] = (image[i][j+1] & 254) | binary[1];
            image[i+1][j] = (image[i+1][j] & 254) | binary[2];
            image[i+1][j+1] = (image[i+1][j+1] & 254) | binary[3];
            image[i+2][j] = (image[i+2][j] & 254) | binary[4];
            image[i+2][j+1] = (image[i+2][j+1] & 254) | binary[5];
            image[i+3][j] = (image[i+3][j] & 254) | binary[6];
            image[i+3][j+1] = (image[i+3][j+1] & 254) | binary[7];
            k++;
            if(k>=strlen(message)){
                return;
            }
        }
    }
}

//function to extract the message from the image
void extractMessage(int image[][8]){
    int i, j, binary[8], k=0;
    char message[255];
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            binary[0] = image[i][j] & 1;
            binary[1] = image[i][j+1] & 1;
            binary[2] = image[i+1][j] & 1;
            binary[3] = image[i+1][j+1] & 1;
            binary[4] = image[i+2][j] & 1;
            binary[5] = image[i+2][j+1] & 1;
            binary[6] = image[i+3][j] & 1;
            binary[7] = image[i+3][j+1] & 1;
            message[k] = convertBinaryToChar(binary);
            k++;
        }
    }
    printf("The hidden message is: %s", message);
}

//main function
int main(){
    int image[8][8]= {{55, 45, 67, 98, 120, 111, 40, 60},
                      {67, 23, 87, 176, 225, 128, 150, 89},
                      {180, 166, 42, 34, 65, 98, 100, 120},
                      {57, 82, 123, 87, 90, 98, 129, 200},
                      {101, 187, 240, 179, 205, 154, 109, 211},
                      {175, 129, 127, 100, 90, 89, 100, 110},
                      {32, 35, 22, 45, 98, 76, 120, 150},
                      {78, 90, 95, 99, 105, 107, 127, 128}
                     };
    char message[] = "This is a secret message.";
    
    //Hiding the message in the image
    hideMessage(image, message);
    
    //Extracting the hidden message from the image
    extractMessage(image);
    
    return 0;
}