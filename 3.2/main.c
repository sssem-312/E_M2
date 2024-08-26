#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stddef.h>

char* my_strdup(const char* s) {
    size_t len = strlen(s) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        memcpy(copy, s, len);
    }
    return copy;
}

uint32_t ip_to_uint32(const char *ip) {
    uint32_t val = 0;
    uint8_t octet;
    char *ip_copy = my_strdup(ip);
    char *token = strtok(ip_copy, ".");
    for (int i = 0; i < 4; ++i) {
        if (token != NULL) {
            octet = (uint8_t)atoi(token);
            val = (val << 8) | octet;
            token = strtok(NULL, ".");
        }
    }
    free(ip_copy);
    return val;
}

int is_in_subnet(uint32_t ip, uint32_t gateway, uint32_t mask) {
    return (ip & mask) == (gateway & mask);
}

int main(int argc, char *argl[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <gateway_ip> <subnet_mask> <N>\n", argl[0]);
        return EXIT_FAILURE;
    }

    char *gateway_ip = argl[1];
    char *subnet_mask = argl[2];

    uint32_t gateway = ip_to_uint32(gateway_ip);
    uint32_t mask = ip_to_uint32(subnet_mask);
    
    int number = atoi(argl[3]);

    int in_count = 0, out_count = 0;
    double in_percent = 0, out_percent = 0;

    srand(time(NULL));

    for (int i = 0; i < number; ++i) {
        uint32_t random_ip = (rand() % 256) << 24 | (rand() % 256) << 16 | (rand() % 256) << 8 | (rand() % 256);
        printf("%d.%d.%d.%d\n", (random_ip >> 24) & 0xFF, (random_ip >> 16) & 0xFF, (random_ip >> 8) & 0xFF, random_ip & 0xFF);
        if (is_in_subnet(random_ip, gateway, mask)) {
            in_count++;
        }
    }

    in_percent = ((double)in_count / number) * 100;
    out_count = number - in_count;
    out_percent = 100 - in_percent;

    printf("Количество узлов в подсети: %d/%.2f%%\n", in_count, in_percent);
    printf("Количество узлов из других подсетей: %d/%.2f%%\n", out_count, out_percent);

    return EXIT_SUCCESS;
}
