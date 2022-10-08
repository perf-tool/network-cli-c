#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    if (strcmp(argv[1], "getaddrinfo") == 0) {
        struct addrinfo *res;
        int err = getaddrinfo(argv[2], NULL, NULL, &res);
        if (err != 0) {
            printf("getaddrinfo: %s", gai_strerror(err));
        }
        struct addrinfo* i;
        for (i = res; i != NULL; i = i->ai_next) {
            char str[INET6_ADDRSTRLEN];
            if (i->ai_addr->sa_family == AF_INET) {
                struct sockaddr_in *p = (struct sockaddr_in *)i->ai_addr;
                printf("%s\n", inet_ntop(AF_INET, &p->sin_addr, str, sizeof(str)));
            } else if (i->ai_addr->sa_family == AF_INET6) {
                struct sockaddr_in6 *p = (struct sockaddr_in6 *)i->ai_addr;
                printf("%s\n", inet_ntop(AF_INET6, &p->sin6_addr, str, sizeof(str)));
            }
        }
    }
}
