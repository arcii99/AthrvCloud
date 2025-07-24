//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>

#define PORT 8080

// Function to generate random numbers between the given range
int generateRandom(int lower, int upper) 
{ 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num; 
} 

// Function to calculate power of a number
int power(int a, int b, int P) 
{  
    if (b == 1) 
        return a; 
  
    else
        return ((int)pow(a, b) % P); 
} 

// Function to generate shared secret key using Diffie-Hellman algorithm
int generateSharedKey(int a, int b, int P) 
{ 
    int x = generateRandom(1, P-1); 
    int A = power(a, x, P); 
    int B = power(b, x, P); 
  
    if (A == B) 
        return A; 
    else
        return -1; 
} 

int main() 
{ 
    int sock = 0, opt = 1; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    int pubkey[2];

    // Creating socket file descriptor 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
    
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        printf("\n Error setting socket options \n"); 
        return -1; 
    } 
    
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    
    // Setting up server connection parameters
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    serv_addr.sin_port = htons(PORT); 
    
    // Connecting to server 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\n Connection Failed \n"); 
        return -1; 
    } 

    // Sending public key to server
    pubkey[0] = generateRandom(1, 100);
    pubkey[1] = power(2, pubkey[0], 97); //Using modulo 97 as prime number
    write(sock , pubkey , sizeof(pubkey)); 
    
    printf("Sent Public Key: (%d, %d)\n", pubkey[0], pubkey[1]);

    // Receiving public key from server
    read(sock , pubkey , sizeof(pubkey)); 
    printf("Received Public Key: (%d, %d)\n", pubkey[0], pubkey[1]);

    // Generating shared secret key
    int shared_secret = generateSharedKey(pubkey[1], pubkey[0], 97);
    printf("Shared Secret Key: %d\n", shared_secret);
    
    return 0; 
}