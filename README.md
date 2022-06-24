## Description
In this project you can find how to make your own _GPS_ tracker that can be monitored over the internet

### Languages used
- [Javascript](https://www.javascript.com/)
- [Python](https://www.python.org/)
- [C++](https://cplusplus.com/doc/tutorial/)
### Other things used
- [Arduino IDE](https://www.arduino.cc/)
- [NodeJS](https://nodejs.org/en/)
-	[OSC](https://www.cnmat.berkeley.edu/OpenSoundControl)
- [Telnet](https://en.wikipedia.org/wiki/Telnet)


### OSC server side
We need to install **node-osc** library for nodejs using _npm_. For that run `npm install node-osc` in your terminal, or go to _osc_ folder and run `npm install`.

Open _osc/osc-server.js_ to see a basic example code.

### Telnet server side
We need to install **telnetserver** library for python using _pip_. For that run `pip install telnetserver` in your terminal, or go to _telnet_ folder and run `pip install -r requirements.txt`.

Open _telnet/telnet-server.py_ to see a basic example code.


### Device side
#### Hardware 
- ESP8266 WeMos D1 Mini
- NEO-6M

#### Software
- Arduino IDE
- UART
