# antenna-lna-ESP8266WebRelaySwitch

![switchboard](https://user-images.githubusercontent.com/35871385/121892349-ea61fa00-cd1c-11eb-9695-ed8b6c48c2ed.jpg)

# Desciption
Control of on/off for LNAs and antenna relays using a ESP8266 4 channel relay board via a simple web interface. Can be used to control anything via the relays, just change the names in the HTML part of the code. Part of the HTML code is from Peter (2M0SQL) - https://github.com/magicbug/polarisation-switch

Relay boards used is the following, but similar boards with the same type of serial control of the relays should be possible to use:
* https://www.icstation.com/mobile/esp8266-wifi-channel-relay-module-remote-control-switch-wireless-transmitter-smart-home-p-13421.html

# Setup
Enter the name and password of your Wifi network:
```
const char* ssid = "name"; //Enter Wi-Fi SSID
const char* password =  "password"; //Enter Wi-Fi Password
```

Change the following to your choice of fixed IP address, or just remove/comment all the IPAddress rows if you would like to use dynamic address. See comment in the code.
```
  IPAddress ip(192, 168, 1, 20);
```
I have used this for controlling two LNAs and two antenna relays, but change the name of the buttons if you like, look in the different part of the HTML code.
Then just flash the ESP8266 with the tool of your choice (I use Arduino IDE for Windows).

# Web interface
The result for the web interface, see below. The page is responsive. The relay board starts with all relays to off position.

![switchwebinterface](https://user-images.githubusercontent.com/35871385/121892408-006fba80-cd1d-11eb-88bf-9a61da6d5611.jpg)
