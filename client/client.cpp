#include "client.h"

namespace client {

client::client()
{
    try {
        start_client();
        connect_to_server();
        send_message();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

client::~client() {
    close_socket();
    std::cout << "close client";
}

void client::start_client() {
    _socket = socket(AF_INET, SOCK_STREAM, 0);

    if (_socket < 0) {
        throw std::runtime_error("socket initialization error");
    }

    std::cout << "Set socket: Success\n";

    _server_addr.sin_family = AF_INET;
    _server_addr.sin_port = PORT_SERVER ;

    if (inet_pton(AF_INET, IP_ADRESS_SERVER,
                  &(_server_addr.sin_addr)) <= 0){
        throw std::runtime_error("IP addres is't correct");
    }

    std::cout << "Set IP address and port: Success\n";
}

void client::connect_to_server() {
    if(connect(_socket, (struct sockaddr *)&_server_addr, sizeof(_server_addr))<0){
        throw std::runtime_error("Can't connect to server");
    }

    std::cout << "Connect to server: Success\n";
}

void client::send_message() {
    std::cout << "Write message: \n";
//    std::cin >> _message.word;
//    _message.word = "testing server";
//    _message.size
    _message.test_bit = true;

    if (send(_socket, &_message, sizeof(_message), 0) < 0) {
        throw std::runtime_error("Can't send message");
    }

    std::cout << "Message is send";
}

void client::close_socket() {
    shutdown(_socket, 2);

    if (_socket != 0) {
        close(_socket);
        _socket = -1;
    }
}

}
