//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: genious
/* Packet Monitoring Example Program in C */
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Define the callback function */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    /* Print the size of the packet */
    printf("Packet size: %d\n", header->len);
    /* Print the content of the packet */
    for(int i=0; i<header->len; i++)
    {
        printf("%02x ", packet[i]);
        if ((i+1)%16 == 0) printf("\n");
    }
    printf("\n");
}

int main()
{
    /* Variables */
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_expression[] = ""; /* this filter expression can be added */

    /* Get a device */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL)
    {
        fprintf(stderr, "Error finding device: %s\n", error_buffer);
        exit(1);
    }
    
    /* Open the device */
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening device: %s\n", error_buffer);
        exit(1);
    }
    
    /* Compile and apply filter */
    if (pcap_compile(handle, &fp, filter_expression, 0, 0) == -1)
    {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Error applying filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    /* Start the capture */
    printf("Packet monitoring started on device: %s\n", device);
    pcap_loop(handle, -1, packet_handler, NULL);

    /* Close the handle */
    pcap_close(handle);
    
    /* Exit */
    return 0;
}