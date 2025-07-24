//FormAI DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
//SHERLOCK HOLMES STYLE SOCKET PROGRAM

/*
It was a dark and stormy night when Sherlock Holmes received an urgent message from a client in distress.
The client had been hacked and their sensitive data was at risk. Holmes immediately sprang into action and 
began coding a program to secure the client's data.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
	//First, Holmes had to set up a socket connection to communicate with the client.

	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *hello = "Hello from the other side."; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	memset(&serv_addr, '0', sizeof(serv_addr)); 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	//Holmes' client had a dynamic IP, so he scanned the network to find it.

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed! \n"); 
		return -1; 
	} 

	//Once the connection was established, Holmes began to encrypt the client's data using his custom encryption algorithm.

	char secret_key[50] = "The game is afoot!";
	char data_to_encrypt[100] = "The client's data is now secure.";

	int i, j;
	int shift;

	for(i = 0, j = 0; i < strlen(data_to_encrypt); i++, j++){
		if(j >= strlen(secret_key)){
			j = 0;
		}
		shift = secret_key[j] - 'A';
		data_to_encrypt[i] = ((data_to_encrypt[i] - 'A' + shift) % 26) + 'A';
	}
	
	char encrypted_data[100];
	strcpy(encrypted_data, data_to_encrypt);
	
	//Holmes then sent the encrypted data to the client.

	send(sock , encrypted_data , strlen(encrypted_data) , 0 ); 
	
	//After sending the data, Holmes received a confirmation message from the client.

	valread = read( sock , buffer, 1024); 
	printf("%s\n",buffer ); 

	//Finally, satisfied that the client's data was secure, Holmes closed the socket.

	close(sock); 
	return 0; 
}