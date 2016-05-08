#include <SFML/Network.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    UdpSocket udp;
    if(udp.bind(8080) != Socket::Done)
    {
        cout << "Error!" << endl;
    }
    cout << "Binding done!" << endl;
    char send[] = "Data sent!";
    if(udp.send(send, sizeof(send), IpAddress("192.168.1.5"), 8080) != Socket::Done)
    {
        cout << "Error with sending!" << endl;
    }
    cout << "Sent successfully!" << endl;
    UdpSocket reciever;
    reciever.bind(8080);
    char* data;
    size_t size;
    if(reciever.receive(data, size, )
}
