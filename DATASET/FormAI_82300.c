//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include<stdio.h> 
#include<time.h> 
#include<unistd.h> 
#include<arpa/inet.h> 
#include<sys/socket.h> 
  
#define PORT 8080 
#define SERVER_IP "127.0.0.1" 
#define DOWNLOAD_SIZE 1073741824 // 1 Gigabyte
#define UPLOAD_SIZE 1048576  // 1 Megabyte
  
void download_speed_test(int socket_id) 
{ 
    char buffer[1024]; 
    int bytes = 0; 
    clock_t start, end; 
    double time_used; 
  
    start = clock(); 
    while(bytes < DOWNLOAD_SIZE) 
    { 
        recv(socket_id, buffer, 1024, 0); 
        bytes += 1024; 
    } 
    end = clock(); 
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    double download_speed = (DOWNLOAD_SIZE / 1048576) / time_used; 
    printf("Download speed: %f Mbps\n", download_speed); 
} 

void upload_speed_test(int socket_id) 
{ 
    char buffer[UPLOAD_SIZE]; 
    int bytes = 0; 
    clock_t start, end; 
    double time_used; 
  
    start = clock(); 
    while(bytes < UPLOAD_SIZE) 
    { 
        send(socket_id, buffer, 1024, 0); 
        bytes += 1024; 
    } 
    end = clock(); 
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    double upload_speed = (UPLOAD_SIZE / 1048576) / time_used; 
    printf("Upload speed: %f Mbps\n", upload_speed); 
} 
  
int main() 
{ 
    struct sockaddr_in server_address; 
    int socket_id = 0, bytes_received = 0; 
  
    char buffer[1024] = {0}; 
  
    if((socket_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
  
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 
       
    if(inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
  
    if(connect(socket_id, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    download_speed_test(socket_id);
    upload_speed_test(socket_id);
    return 0; 
}