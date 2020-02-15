#include <boost/asio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::asio;

void turnOn(serial_port & sp, bool print = 0) {

    // Magic
    char offData[8];
    char onData[8];
    for(int i=0;i<8;i++)
    {
        offData[i]='0';
        onData[i]='0';
    }

    // OFF
    string offCmd = "QT\n";
    write(sp, buffer(offCmd, 8));
    read(sp, buffer(offData, 8));

    // ON
    string onCmd = "BM\n";
    write(sp, buffer(onCmd, 8));
    read(sp, buffer(onData, 8));

    // Print
    if(print) {
        for(char i : offData) {
            cout<<i;
        }
        for(char i : onData) {
            cout<<i;
        }
    }
}

int main() {

    // Config
//    io_service service;
//    serial_port sp(service, "/dev/tty.usbmodem14301");
//    serial_port::baud_rate rate(9600);
//    sp.set_option(rate);
//
//
//    turnOn(sp, true);

    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::CircleShape shape(900);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }



    return 0;

}