//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include<stdio.h>
#include<math.h>

// Function to encrypt the given message
void encrypt(char message[], int key)
{
    int len = 0;
    while(message[len] != '\0') // Finding the length of the message
        len++;

    // Finding the number of rows and columns in the matrix
    int row = sqrt(len);
    int col = row;
    if(row*col < len)
        col++;

    // Creating a matrix for encryption
    char matrix[row][col];
    int k = 0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(k < len)
                matrix[i][j] = message[k++];
            else
                matrix[i][j] = ' ';
        }
    }

    // Encoding the message using columnar transposition cipher
    char message_encrypted[row][col];
    char key_str[col+1];
    sprintf(key_str, "%d", key);
    int key_len = 0;
    while(key_str[key_len] != '\0')
        key_len++;

    int key_arr[key_len];
    for(int i=0; i<key_len; i++)
        key_arr[i] = key_str[i] - '0';

    int index_min;
    for(int i=0; i<key_len; i++)
    {
        index_min = i;
        for(int j=i+1; j<key_len; j++)
        {
            if(key_arr[j] < key_arr[index_min])
                index_min = j;
        }
        int temp = key_arr[i];
        key_arr[i] = key_arr[index_min];
        key_arr[index_min] = temp;
    }

    for(int i=0; i<col; i++)
    {
        for(int j=0; j<key_len; j++)
        {
            for(int k=0; k<row; k++)
            {
                if(matrix[k][i] != ' ')
                {
                    if(j == key_arr[k])
                    {
                        message_encrypted[k][i] = matrix[k][i];
                        break;
                    }
                }
            }
        }
    }

    // Printing the encrypted message
    printf("\nEncrypted message: ");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%c", message_encrypted[i][j]);
        }
    }
}

int main()
{
    char message[] = "This is a test message.";
    int key = 312;

    printf("Original message: %s", message);
    encrypt(message, key);
    printf("\n");
    
    return 0;
}