#include "client.h"

namespace client {

client::client()
{
    try {
        start_client();
        connect_to_server();

        talk_with_server();
        //        send_message();
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

    if (inet_pton(AF_INET, IP_ADDRESS_SERVER,
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

void client::talk_with_server() {
    while (1) {
        send_message();
        recv_message();
    }
}

void client::send_message() {
    std::cout << "Write message: \n";
    std::cin >> _message.content;
    // std::cin >> _message.size;

    time_to_send = time(NULL);

    // _message.size = sizeof(_message.content);

    if (send(_socket, (char *)&_message, sizeof(_message), 0) < 0) {
        throw std::runtime_error("Can't send message");
    }

    std::cout << "Message is send\n";
}

void client::recv_message() {
    // long time_S;
    // if (recv(_socket, (char *)&time_S, sizeof(time_S), 0) < 0) {
    //     throw std::runtime_error("Response is not given");
    // }
    // std::cout << "Response: "<< time_to_send - time(NULL) << std::endl;
    if (recv(_socket, (char *)&_message, sizeof(_message), 0) < 0) {
        throw std::runtime_error("Response is not given");
    }
    std::cout << "message server - " << _message.content << "1" << std::endl;

}

void client::close_socket() {
    shutdown(_socket, 2);

    if (_socket != 0) {
        close(_socket);
        _socket = -1;
    }
}

}
