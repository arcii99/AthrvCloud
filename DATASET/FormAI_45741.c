//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    const u_char *packet;
    struct pcap_pkthdr header;
    int capture_count = 10;

    printf("[*] Initializing CyberPcap...\n");

    /* Open the capture file */
    handle = pcap_open_offline("capture.pcap", errbuf);
    if (handle == NULL) {
        fprintf(stderr, "[-] Couldn't open file: %s\n", errbuf);
        return(2);
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "[-] Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "[-] Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    printf("\n[*] Starting packet capture...\n\n");
    /* Loop through packets and print them out */
    while ((packet = pcap_next(handle, &header)) != NULL && capture_count > 0) {
        printf("[+] Packet captured, length: %d\n", header.len);
        capture_count--;
    }

    /* Clean up */
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("\n[*] Capture complete\n");

    return(0);
}