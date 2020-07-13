#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h> // for translate network byte-order

int CreateNetworkByteFile(char* name, int num)
{
    FILE* fp = fopen(name, "wb");
    uint32_t n = htonl(num);
    if(fp == NULL) return printf("[!] Can't Write File\n");
    fwrite(&n, sizeof(n), 1, fp);
    fclose(fp);
    return 0;
}

uint32_t ReadFromFile(char* name)
{
    uint32_t n = 0;
    FILE* fp = fopen(name, "rb");
    if(fp == NULL) { printf("[!] %s: No such file\n"); };
    fread(&n, sizeof(uint32_t), 1, fp);
    return ntohl(n);
}

void my_ntohl(uint32_t *p)
{
    // translate only host-network-order on little endian
}

int main(int argc, char* argv[])
{
    if(argc < 3)
        return printf("[!] Usage: %s <File1> <File2>\n", argv[0]);

    uint32_t a = ReadFromFile(argv[1]);
    uint32_t b = ReadFromFile(argv[2]);
    printf("[*] Network byte-order in first file : %d\n", a);
    printf("[*] Network byte-order in second file : %d\n", b);
    printf("[*] Sum : %d\n", a+b);
    return 0;
}