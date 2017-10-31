#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
    char* domain = (char*)"AF_INET";
    bool type = false;
    char message[2000];
    Socket* socket = new Socket(domain,type);
    socket->connectSocket((char*)"127.0.01",8888); //cambiar por socket->connectSocket((char*)"163.178.104.187",80); para el servidor de Chiqui
    socket->write((char*)"GET / HTTP/1.1\r\nhost: redes.ecci\r\n\r\n",32);
    socket->read(message,32);
    socket->socketShutdown(1);
    return 0;
}
