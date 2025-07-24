//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: all-encompassing
#include<stdio.h>
#include<pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Packet captured\n");
}

int main(int argc, char* argv[])
{
    char *dev; 
    char errbuf[PCAP_ERRBUF_SIZE]; //This stores any errors encountered by pcap
    pcap_t* descr;
    struct bpf_program fp;
    bpf_u_int32 maskp;
    bpf_u_int32 netp;
    int status = 0;
    
    //Get the name of the first device suitable for capture on this 
    //system 
    dev = pcap_lookupdev(errbuf);
    
    if(dev == NULL)
    {
        printf("%s\n",errbuf);
        return -1;
    }
    
    //Open device for live capture 
    descr = pcap_open_live(dev,BUFSIZ,0,-1,errbuf);
    if(descr == NULL)
    {
        printf("pcap_open_live() failed due to [%s]\n",errbuf);
        return -1;
    }
    //Compile the filter expression
    status = pcap_compile(descr, &fp, "tcp", 1, netp);
    if(status == -1)
    {
        printf("pcap_compile() failed due to [%s]\n",errbuf);
        return -1;
    }
    //Set the filter expression to the compiled filter
    status = pcap_setfilter(descr, &fp);
    if(status == -1)
    {
        printf("pcap_setfilter() failed due to [%s]\n",errbuf);
        return -1;
    }
    //Capture packets
    pcap_loop(descr,-1,packetHandler,NULL);
    return 0;
}