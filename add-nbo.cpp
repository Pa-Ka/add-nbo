#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h> // for translate network byte-order

/*int CreateNetworkByteFile(char* name, int num) // making file written by Network byte-order 
{
    FILE* fp = fopen(name, "wb");
    uint32_t n = htonl(num);
    if(fp == NULL) return printf("[!] Can't Write File\n");
    fwrite(&n, sizeof(n), 1, fp);
    fclose(fp);
    return 0;
}*/

uint32_t ReadFromFile(char* name)
{
    uint32_t n = 0;
    FILE* fp = fopen(name, "rb");
    if(fp == NULL) { printf("[!] %s: No such file\n"); exit(-1); };
    fread(&n, 1, sizeof(uint32_t), fp);
    return ntohl(n);
}

int main(int argc, char* argv[])
{
    if(argc < 3)
        return printf("[!] Usage: %s <File1> <File2>\n", argv[0]);

    uint32_t a = ReadFromFile(argv[1]);
    uint32_t b = ReadFromFile(argv[2]);
    printf("[*] %d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);
    return 0;
}
