#include <uWS/uWS.h>
#include <iostream>
#include <string>
int main()
{
    uWS::Hub h;

    h.onConnection([](uWS::WebSocket<uWS::CLIENT> ws, uWS::HttpRequest req) {
        std::string str("Hello,World!");
        ws.send(str.c_str());
    });

    h.onMessage([](uWS::WebSocket<uWS::CLIENT> ws, char *message, size_t length, uWS::OpCode opCode) {
        ws.send(message, length, opCode);
        std::string str(message, length);
        std::cout<<str<<std::endl;
    });

    h.connect("ws://127.0.0.1:3000", nullptr);
    h.run();
}
