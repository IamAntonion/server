#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <iostream>
#include <stdexcept>
#include <ctime>

namespace server {

#define PORT_SERVER         8080
#define IP_ADDRESS_SERVER   "127.0.0.1"

class server
{
public:
    server();
    ~server();

    bool add_client();

private:
    int _socket_server;
    int _socket_client;

    // создаем по мотивам структуру для сервера и клиента
    struct sockaddr_in _server_addr;
    struct sockaddr_in _client_addr;    // возможно следует клиентов хранить в мапе?

    void start_server();
    void close_socket();
    void listen_server();

    void recv_message();
    void send_message();

    struct message {
        std::string content;
        // int size;
        //        std::string word;
        //        bool test_bit;
    };

    message _message;
};

}

#endif // SERVER_H
