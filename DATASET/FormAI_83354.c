//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_CONNECTIONS 1000
#define MAX_PACKET_SIZE 1024

enum ConnectionState {
  CLOSED,
  SYN_RECEIVED,
  SYN_ACK_SENT,
  ESTABLISHED
};

struct Connection {
  int id;
  char address[16];
  int port;
  enum ConnectionState state;
};

typedef struct Connection Connection;

int num_connections = 0;
Connection connections[MAX_CONNECTIONS];

void log_packet(char* packet, int size) {
  char str[MAX_PACKET_SIZE * 2 + 1];
  for(int i = 0; i < size; i++) {
    sprintf(str + i*2, "%02x", packet[i]);
  }
  str[size*2] = 0;
  printf("Received packet: %s\n", str);
}

int find_connection(char* address, int port) {
  for(int i = 0; i < num_connections; i++) {
    if(strcmp(connections[i].address, address) == 0 &&
       connections[i].port == port) {
      return connections[i].id;
    }
  }
  return -1;
}

void open_connection(char* address, int port) {
  if(num_connections >= MAX_CONNECTIONS) {
    printf("Too many connections\n");
    return;
  }

  int id = num_connections;

  strcpy(connections[id].address, address);
  connections[id].port = port;
  connections[id].state = SYN_RECEIVED;

  num_connections++;

  printf("Opened connection %d to %s:%d\n", id, address, port);
}

void close_connection(int id) {
  if(id < 0 || id >= num_connections) {
    printf("Invalid connection ID\n");
    return;
  }

  printf("Closed connection %d to %s:%d\n", id, connections[id].address, connections[id].port);

  // Remove connection by moving the last one to its position
  num_connections--;
  if(id < num_connections) {
    connections[id] = connections[num_connections];
  }
}

void handle_packet(char* packet, int size) {
  log_packet(packet, size);

  // Check packet size
  if(size < 4) {
    printf("Invalid packet size\n");
    return;
  }

  // Check packet type
  if(packet[0] != 'S' || packet[1] != 'Y' ||
     (packet[2] != 'N' && packet[2] != 'A' && packet[2] != 'F') ||
     (packet[2] == 'A' && packet[3] != 'C')) {
    printf("Invalid packet type\n");
    return;
  }

  int id = find_connection("127.0.0.1", 1234);
  if(id < 0) {
    if(packet[2] != 'S') {
      printf("Connection not found\n");
      return;
    }
    open_connection("127.0.0.1", 1234);
    id = num_connections - 1;
  }

  Connection* conn = &connections[id];

  if(packet[2] == 'S') {
    if(conn->state != CLOSED) {
      printf("Connection already open\n");
      return;
    }

    conn->state = SYN_RECEIVED;

    char response[4] = { 'S', 'Y', 'N', 'A' };
    if(write(1, response, sizeof(response)) < sizeof(response)) {
      perror("Failed to send packet");
      exit(1);
    }
  }
  else if(packet[2] == 'A') {
    if(packet[3] != 'C') {
      printf("Invalid packet type\n");
      return;
    }

    if(conn->state != SYN_ACK_SENT) {
      printf("Unexpected packet\n");
      return;
    }

    conn->state = ESTABLISHED;

    printf("Connection %d established\n", id);
  }
  else {
    printf("Unexpected packet\n");
    return;
  }
}

int main() {
  while(1) {
    char packet[MAX_PACKET_SIZE];
    int size = read(0, packet, sizeof(packet));
    if(size < 0) {
      perror("Failed to read packet");
      exit(1);
    }
    if(size == 0) {
      break;
    }

    handle_packet(packet, size);
  }

  return 0;
}