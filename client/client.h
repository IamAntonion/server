#ifndef CLIENT_H
#define CLIENT_H

#include <ctime>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdexcept>
#include <iostream>

namespace client {

#define PORT_SERVER         8080
#define IP_ADDRESS_SERVER   "127.0.0.1"

class client
{
public:
    client();
    ~client();

private:
    int _socket;
    struct sockaddr_in _server_addr;

    void start_client();
    void connect_to_server();
    void talk_with_server();

    void send_message();
    void recv_message();

    void close_socket();

    struct message {
        // std::string content;
        // int time;
        int size;
        //        std::string word;
        //        bool test_bit;
    };

    int time_to_send;

    message _message;
};

}

#endif // CLIENT_H
