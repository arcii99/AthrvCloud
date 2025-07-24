//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PACKET_SIZE 1024
#define MAX_PACKETS 1000

typedef struct Packet {
  int size;
  struct timeval arrival_time;
} Packet;

typedef struct Stream {
  char name[MAX_NAME_LENGTH];
  Packet packets[MAX_PACKETS];
  int num_packets;
} Stream;

typedef struct Queue {
  Stream *streams;
  int num_streams;
} Queue;

void add_packet(Stream *stream, int size, struct timeval arrival_time) {
  if (stream->num_packets < MAX_PACKETS) {
    Packet new_packet;
    new_packet.size = size;
    new_packet.arrival_time = arrival_time;
    stream->packets[stream->num_packets] = new_packet;
    stream->num_packets++;
  }
  else {
    printf("Packet dropped: stream %s is full\n", stream->name);
  }
}

int calculate_latency(Stream *stream, long int current_time) {
  int total_latency = 0;
  for (int i = 0; i < stream->num_packets; i++) {
    Packet current_packet = stream->packets[i];
    long int time_diff = (current_time * 1000000 + current_packet.arrival_time.tv_usec) - (current_packet.arrival_time.tv_sec * 1000000 + current_packet.arrival_time.tv_usec);
    total_latency += time_diff;
  }
  return total_latency / stream->num_packets;
}

int calculate_throughput(Stream *stream, long int current_time) {
  int total_size = 0;
  for (int i = 0; i < stream->num_packets; i++) {
    total_size += stream->packets[i].size;
  }
  int elapsed_time = current_time - stream->packets[0].arrival_time.tv_sec;
  return (total_size * 8) / elapsed_time; //bps
}

void print_queue_stats(Queue *queue, long int current_time) {
  printf("--------Queue Stats--------\n");
  for (int i = 0; i < queue->num_streams; i++) {
    printf("Stream: %s\n", queue->streams[i].name);
    printf("Current throughput: %d bps\n", calculate_throughput(&queue->streams[i], current_time));
    printf("Average latency: %d us\n", calculate_latency(&queue->streams[i], current_time));
    printf("--------------------------\n");
  }
}

int main() {
  Queue queue;
  queue.num_streams = 2;
  queue.streams = (Stream*)malloc(queue.num_streams * sizeof(Stream));

  //Initialize streams
  strcpy(queue.streams[0].name, "VoIP");
  queue.streams[0].num_packets = 0;
  strcpy(queue.streams[1].name, "FTP");
  queue.streams[1].num_packets = 0;

  //Simulate incoming packets
  for (int i = 0; i < 20; i++) {
    struct timeval now;
    gettimeofday(&now, NULL);
    if (i % 5 == 0) {
      add_packet(&queue.streams[0], 100, now);
    }
    else {
      add_packet(&queue.streams[1], 1000, now);
    }
    print_queue_stats(&queue, now.tv_sec);
  }
}