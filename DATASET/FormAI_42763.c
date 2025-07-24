//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// define maximal packet length
#define MAX_PACKET_LEN 1518

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet_data);

int main(int argc, char *argv[]) {

	char errbuf[PCAP_ERRBUF_SIZE];
	char *dev;
	char filter_exp[] = "udp port 4000"; // filter for UDP packets on port 4000
	bpf_u_int32 net;
	bpf_u_int32 mask;
	pcap_t *handle;
	struct bpf_program fp;

	// get the default network device
	dev = pcap_lookupdev(errbuf);
	if (dev == NULL) {
		fprintf(stderr, "Unable to find default network device: %s\n", errbuf);
		exit(EXIT_FAILURE);
	}

	// get network address and mask for the device
	if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
		fprintf(stderr, "Unable to get network address and mask for device %s: %s\n", dev, errbuf);
		exit(EXIT_FAILURE);
	}

	// open pcap session for capturing packets
	handle = pcap_open_live(dev, MAX_PACKET_LEN, 1, 1000, errbuf);
	if (handle == NULL) {
		fprintf(stderr, "Unable to open live capture session on device %s: %s\n", dev, errbuf);
		exit(EXIT_FAILURE);
	}

	// compile and apply filter expression
	if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
		fprintf(stderr, "Unable to compile filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
		exit(EXIT_FAILURE);
	}

	if (pcap_setfilter(handle, &fp) == -1) {
		fprintf(stderr, "Unable to apply filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
		exit(EXIT_FAILURE);
	}

	// start capturing packets
	pcap_loop(handle, 0, packet_handler, NULL);

	pcap_close(handle);
	return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet_data) {
	// process packet here
	printf("Received packet of length %d\n", header->len);
}