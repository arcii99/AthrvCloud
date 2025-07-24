//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_PACKETS 1000
#define MAX_PACKET_SIZE 1500
#define MIN_PACKET_DELAY 1
#define MAX_PACKET_DELAY 1000

// Structs
typedef struct {
  int size;
  int delay;
} Packet;

typedef struct {
  Packet packets[MAX_PACKETS];
  int count;
  int totalSize;
  float averageDelay;
} PacketQueue;

// Function declarations
void simulateTraffic(PacketQueue *inputQueue, PacketQueue *outputQueue);
void processPackets(PacketQueue *inputQueue, PacketQueue *outputQueue);
void addPacket(PacketQueue *queue, int size, int delay);
void printQueueStats(PacketQueue queue);

// Main function
int main() {
  srand(time(NULL));

  PacketQueue inputQueue, outputQueue;
  inputQueue.count = 0;
  inputQueue.totalSize = 0;
  inputQueue.averageDelay = 0.0f;
  outputQueue.count = 0;
  outputQueue.totalSize = 0;
  outputQueue.averageDelay = 0.0f;

  // Generate sample traffic
  for (int i = 0; i < MAX_PACKETS; i++) {
    int size = rand() % MAX_PACKET_SIZE + 1;
    int delay = rand() % (MAX_PACKET_DELAY - MIN_PACKET_DELAY + 1) + MIN_PACKET_DELAY;
    addPacket(&inputQueue, size, delay);
  }

  simulateTraffic(&inputQueue, &outputQueue);

  printf("Input queue stats:\n");
  printQueueStats(inputQueue);

  printf("\nOutput queue stats:\n");
  printQueueStats(outputQueue);

  return 0;
}

// Simulates the processing of packets from the input queue to the output queue
void simulateTraffic(PacketQueue *inputQueue, PacketQueue *outputQueue) {
  clock_t startTime = clock();

  while (inputQueue->count > 0) {
    processPackets(inputQueue, outputQueue);
  }

  clock_t endTime = clock();
  float elapsedTime = (float)(endTime - startTime) / CLOCKS_PER_SEC;
  outputQueue->averageDelay /= outputQueue->count;
  printf("\nTraffic simulation completed in %.3f seconds\n", elapsedTime);
}

// Processes packets from input queue to output queue
void processPackets(PacketQueue *inputQueue, PacketQueue *outputQueue) {
  int delay = inputQueue->packets[0].delay;
  clock_t startTime = clock();

  // Simulate delay
  while (((float)(clock() - startTime) / CLOCKS_PER_SEC) * 1000 < delay);

  // Move packet from input queue to output queue
  Packet packet = inputQueue->packets[0];
  inputQueue->count -= 1;
  inputQueue->totalSize -= packet.size;
  inputQueue->averageDelay -= (float)packet.delay / inputQueue->count;
  memmove(inputQueue->packets, inputQueue->packets+1, inputQueue->count * sizeof(Packet));

  addPacket(outputQueue, packet.size, packet.delay);
}

// Adds packet to queue
void addPacket(PacketQueue *queue, int size, int delay) {
  Packet packet = { size, delay };
  queue->packets[queue->count] = packet;
  queue->count += 1;
  queue->totalSize += size;
  queue->averageDelay += (float)delay / queue->count;
}

// Prints queue stats
void printQueueStats(PacketQueue queue) {
  printf("Total packets: %d\n", queue.count);
  printf("Total size: %d bytes\n", queue.totalSize);
  printf("Average delay: %.3f ms\n", queue.averageDelay);
}