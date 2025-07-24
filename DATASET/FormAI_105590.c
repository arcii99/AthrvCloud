//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv)
{
  char *device = NULL; // The device to capture on
  char errorBuffer[PCAP_ERRBUF_SIZE]; // A buffer to store any errors
  pcap_t *handle; // The handle for the capture session
  int snapshotLength = 1024; // The maximum number of bytes of packet to capture
  int promiscuousMode = 1; // Capture packets in promiscuous mode (non-zero means promiscuous)
  int timeoutLimit = 10000; // In milliseconds, the amount of time to wait for a packet to arrive before timing out

  // Find a capture device
  device = pcap_lookupdev(errorBuffer);
  if (device == NULL)
  {
    printf("Error finding capture device: %s\n", errorBuffer);
    return 1;
  }
  printf("Using device: %s\n", device);

  // Open the capture session
  handle = pcap_open_live(device, snapshotLength, promiscuousMode, timeoutLimit, errorBuffer);
  if (handle == NULL)
  {
    printf("Error opening capture session: %s\n", errorBuffer);
    return 1;
  }

  // Begin the capture
  printf("Starting capture...\n");
  pcap_loop(handle, 0, packetHandler, NULL);

  // Cleanup
  pcap_close(handle);
  printf("Capture complete.\n");
  return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
  printf("Received a packet with length of %d\n", pkthdr->len);
  // Do something with the packet here
}