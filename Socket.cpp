#include "Socket.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>


using namespace std;

Socket::Socket(){}

Socket::~Socket(){
    close(sock);
}

Socket::Socket(char* domain, bool type){
    if(strcmp(domain,"AF_INET") == 0){
        domainNumber = AF_INET;
    } else if(strcmp(domain,"AF_LOCAL") == 0){
        domainNumber = AF_LOCAL;
    } else if(strcmp(domain,"AF_INET6") == 0){
        domainNumber = AF_INET6;
    }
    if(!type){
        sockType = SOCK_STREAM;
    } else {
        sockType = SOCK_DGRAM;
    }
    sock = socket(domainNumber , sockType , 0);
    if (sock == -1){
        cout << "Could not create socket" << endl;
    }
}

int Socket::connectSocket(char* host,int port){
    //param1:AF_INET, AF_LOCAL, AF_INET6,
    //sock = 0;
    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
        cout << "connect error" << endl;
        return 1;
    }
    return 0;
}

void Socket::read(char* message,int len){
    if(recv(sock, message , 2000 , 0) < 0){
        cout << "recv failed" << endl;
    } else {
        cout << "Reply received\n" << endl;
        cout << message << endl;
    }
}

void Socket::write(char* message,int len){
    if( send(sock , message , strlen(message) , 0) < 0){
        cout << "Send failed" << endl;
    } else {
        cout << "Data Send\n" << endl;
    }
}

void Socket::socketShutdown(int a){
    shutdown(sock,a);
}
