#ifndef SOCKET_H
#define SOCKET_H


class Socket
{
    public:
        Socket();
        Socket(char* domain,bool type);
        //char = dominio, bool si es IPv4 o IPv6
        virtual ~Socket();
        int connectSocket(char* host,int port);
        void read(char* message,int len);
        void write(char* message,int len);
        void socketShutdown(int a);
        int listenSocket(int queuee);
        int bindd();

    protected:

    private:
        int sockType;
        int sock;
        int domainNumber;
};

#endif // SOCKET_H
