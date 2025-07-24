//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define WIFI_SIGNAL_MAX 100 // Maximum signal strength value
#define WIFI_SIGNAL_MIN 0   // Minimum signal strength value

typedef struct {
  uint16_t mac[6];
  int8_t signal_strength;
} wifi_packet_t; // structure to store wifi packet data

int main() {
  wifi_packet_t packet;
  int8_t signal_strength_dbm;
  float signal_strength_mw;
  float signal_strength_perc;
  int packets = 0;
  int avg_signal_strength = 0;
  int max_signal_strength = WIFI_SIGNAL_MIN;
  int min_signal_strength = WIFI_SIGNAL_MAX;
  uint32_t total_signal_strength = 0;

  printf("WiFi Signal Strength Analyzer\n\n");

  while (1) {
    // simulate incoming wifi packets
    for (int i = 0; i < 6; i++) {
      packet.mac[i] = (uint16_t)rand() % 65536;
    }
    packet.signal_strength = rand() % WIFI_SIGNAL_MAX;

    if (packet.signal_strength > max_signal_strength) {
      max_signal_strength = packet.signal_strength;
    }
    if (packet.signal_strength < min_signal_strength) {
      min_signal_strength = packet.signal_strength;
    }
    packets++;
    total_signal_strength += packet.signal_strength;
    avg_signal_strength = round((float)total_signal_strength / (float)packets);
    signal_strength_dbm = packet.signal_strength - 100;
    signal_strength_mw = pow(10, ((float)signal_strength_dbm)/10);
    signal_strength_perc = ((float)packet.signal_strength / (float)WIFI_SIGNAL_MAX) * 100.0;

    printf("Received packet from %02x:%02x:%02x:%02x:%02x:%02x | Signal Strength: %d dBm | %f mW | %f%%\n",
      packet.mac[0], packet.mac[1], packet.mac[2], packet.mac[3], packet.mac[4], packet.mac[5],
      signal_strength_dbm, signal_strength_mw, signal_strength_perc);

    printf("Average Signal Strength: %d | Max Signal Strength: %d | Min Signal Strength: %d | Total Packets: %d\n\n",
      avg_signal_strength, max_signal_strength, min_signal_strength, packets);
  }

  return 0;
}