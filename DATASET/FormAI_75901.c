//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define SRC_PORT 5000 // source port number
#define DST_PORT 5001 // destination port number
#define MAX_BUFFER_SIZE 1024 // maximum buffer size for socket read
#define TIMEOUT_SEC 10 // timeout in seconds for socket read

int main(int argc, char** argv) {
    
    // create socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }
    
    // set socket options for QoS
    int qos = 1; // arbitrary QoS value
    int set_sock_opt_res = setsockopt(sock, IPPROTO_IP, IP_TOS, &qos, sizeof(qos));
    if (set_sock_opt_res < 0) {
        perror("setsockopt() failed");
        exit(1);
    }
    
    // set up source and destination addresses
    struct sockaddr_in src_addr, dst_addr;
    src_addr.sin_family = AF_INET;
    src_addr.sin_port = htons(SRC_PORT);
    src_addr.sin_addr.s_addr = INADDR_ANY;
    dst_addr.sin_family = AF_INET;
    dst_addr.sin_port = htons(DST_PORT);
    dst_addr.sin_addr.s_addr = inet_addr("192.168.0.2");
    
    // bind source address to socket
    int bind_res = bind(sock, (struct sockaddr*)&src_addr, sizeof(src_addr));
    if (bind_res < 0) {
        perror("bind() failed");
        exit(1);
    }
    
    // send packet to destination
    char* message = "QoS test message";
    int send_res = sendto(sock, message, strlen(message), 0, (struct sockaddr*)&dst_addr, sizeof(dst_addr));
    if (send_res < 0) {
        perror("sendto() failed");
        exit(1);
    }
    
    // wait for response from destination
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);
    int recv_res = recvfrom(sock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&sender_addr, &sender_addr_len);
    if (recv_res < 0) {
        perror("recvfrom() failed");
        exit(1);
    }
    
    // check QoS value of received packet
    int received_qos = (unsigned char)buffer[0] >> 5; // extract upper 3 bits as QoS
    if (received_qos == qos) {
        printf("QoS test succeeded: received QoS value matches sent QoS value.\n");
    } else {
        printf("QoS test failed: received QoS value (%d) does not match sent QoS value (%d).\n", received_qos, qos);
    }

    // close socket
    close(sock);

    return 0;
}