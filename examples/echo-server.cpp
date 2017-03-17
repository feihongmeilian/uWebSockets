#include <uWS/uWS.h>
#include <iostream>
#include <string>
int main()
{
    uWS::Hub h;

    h.onMessage([](uWS::WebSocket<uWS::SERVER> ws, char *message, size_t length, uWS::OpCode opCode) {
        ws.send(message, length, opCode);
        std::string str(message, length);
        std::cout<<str<<std::endl;
    });

    h.listen(3000);
    h.run();
}
