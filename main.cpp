#include <SFML/Network.hpp>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace sf;
using namespace std;

int main()
{
    UdpSocket client;
    client.bind(8080);
    IpAddress remote("192.168.1.5");
    IpAddress get;
    client.send("$!$", 3, remote, 80);
    char data[1024];
    if(client.receive(data, 1024, 0, get, 0) != Socket::Done) return 228;
    if(!strcmp("$!$", data)) client.send("$!$", 3, remote, 80);
    bool co = true;
    do
    {
        string mess;
        cout << "Type your message!: ";
        cin >> mess;
        if(mess == 0)
            co = false;
        client.send(mess.c_str(), 1024, remote, 80);
        size_t size;
        string cat;
        client.receive(cat, 1024, size, get, 0);
        if(size != 0) cout << cat << endl;
    } while(co);
}
