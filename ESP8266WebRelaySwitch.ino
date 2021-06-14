#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "name"; //Enter Wi-Fi SSID
const char* password =  "password"; //Enter Wi-Fi Password

byte relay1_ON[] = {0xA0, 0x01, 0x01, 0xA2};  //Hex command to send to serial for open relay 1
byte relay1_OFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay 1
byte relay2_ON[] = {0xA0, 0x02, 0x01, 0xA3};  //Hex command to send to serial for open relay 2
byte relay2_OFF[] = {0xA0, 0x02, 0x00, 0xA2}; //Hex command to send to serial for close relay 2
byte relay3_ON[] = {0xA0, 0x03, 0x01, 0xA4};  //Hex command to send to serial for open relay 3
byte relay3_OFF[] = {0xA0, 0x03, 0x00, 0xA3}; //Hex command to send to serial for close relay 3
byte relay4_ON[] = {0xA0, 0x04, 0x01, 0xA5};  //Hex command to send to serial for open relay 4
byte relay4_OFF[] = {0xA0, 0x04, 0x00, 0xA4}; //Hex command to send to serial for close relay 4

int relay1_State = false;
int relay2_State = false;
int relay3_State = false;
int relay4_State = false;
String test = "";

String startHtmlPage()
{
String str ="<!DOCTYPE html>\n";
str +="<head>\n";
str +="<title>Antenna and LNA Switch</title>\n";
str +="<!-- Latest compiled and minified CSS -->\n";
str +="<link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css' crossorigin='anonymous'>\n";
str +="<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
str +="</head>\n";
str +="<body>\n";
str +="<div class='container-fluid'>\n";
str +="<h2 style='font-size: 1.8rem;'><a href='/'>Polarisation and LNA Switch</a></h2>\n";
str +="<div class='row'>\n";
  return str;
}

const String endHtmlPage = "</div>\n</div>\n</body>\n</html>";


void handleRoot() {
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_VHF_on() {
  relay1_State = true;
  Serial.write(relay1_ON, sizeof(relay1_ON));     // turns the relay 1 ON 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_VHF_off() {
  relay1_State = false;
    Serial.write(relay1_OFF, sizeof(relay1_OFF));     // turns the relay 1 OFF 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_UHF_on() {
  relay2_State = true;
  Serial.write(relay2_ON, sizeof(relay2_ON));     // turns the relay 2 ON 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_UHF_off() {
  relay2_State = false;
    Serial.write(relay2_OFF, sizeof(relay2_OFF));     // turns the relay 2 OFF 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_LNA_VHF_on() {
  relay3_State = true;
  Serial.write(relay3_ON, sizeof(relay3_ON));     // turns the relay 3 ON 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_LNA_VHF_off() {
  relay3_State = false;
    Serial.write(relay3_OFF, sizeof(relay3_OFF));     // turns the relay 3 OFF 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_LNA_UHF_on() {
  relay4_State = true;
  Serial.write(relay4_ON, sizeof(relay4_ON));     // turns the relay 4 ON 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}

void handle_LNA_UHF_off() {
  relay4_State = false;
    Serial.write(relay4_OFF, sizeof(relay4_OFF));     // turns the relay 4 OFF 
  server.send(200, "text/html", startHtmlPage() + relayStatusHtml() + endHtmlPage);
}


String relayStatusHtml()
{
    String str = "";

    //ANT VHF
    str +="<div class='col-12' style='margin-top: 5px;'>\n";
    str +="<div class='btn-group' role='group' aria-label='ANT VHF'>\n";
    str +="<a href='' class='btn btn-light' role='button' style='width: 97px;'><b>ANT VHF</b></a>\n";
    if (relay1_State == true) 
    {
      str += "<a href='/ant/vhf/on' class='btn btn-info' role='button' style='width: 120px;'>RHCP</a>\n";
      str += "<a href='/ant/vhf/off' class='btn btn-outline-info' role='button' style='width: 120px;'>LHCP (off)</a>\n";
    } else 
    {
      str += "<a href='/ant/vhf/on' class='btn btn-outline-info' role='button' style='width: 120px;'>RHCP</a>\n";      
      str += "<a href='/ant/vhf/off' class='btn btn-info' role='button' style='width: 120px;'>LHCP (off)</a>\n";
    }   
    str += "</div>\n</div>\n";

    //ANT UHF
    str +="<div class='col-12' style='margin-top: 5px;'>\n";
    str +="<div class='btn-group' role='group' aria-label='ANT UHF'>\n";
    str +="<a href='' class='btn btn-light' role='button' style='width: 97px;'><b>ANT UHF</b></a>\n";
    if (relay2_State == true) 
    {
      str += "<a href='/ant/uhf/on' class='btn btn-info' role='button' style='width: 120px;'>Horizontal</a>\n";
      str += "<a href='/ant/uhf/off' class='btn btn-outline-info' role='button' style='width: 120px;'>Vertical (off)</a>\n";
    } else 
    {
      str += "<a href='/ant/uhf/on' class='btn btn-outline-info' role='button' style='width: 120px;'>Horizontal</a>\n";      
      str += "<a href='/ant/uhf/off' class='btn btn-info' role='button' style='width: 120px;'>Vertical (off)</a>\n";
    }   
    str += "</div>\n</div>\n";

    //LNA VHF
    str +="<div class='col-12' style='margin-top: 5px;'>\n";
    str +="<div class='btn-group' role='group' aria-label='LNA VHF'>\n";
    str +="<a href='' class='btn btn-light' role='button' style='width: 97px;'><b>LNA VHF</b></a>\n";
    if (relay3_State == true) 
    {
      str += "<a href='/lna/vhf/on' class='btn btn-info' role='button' style='width: 120px;'>ON</a>\n";
      str += "<a href='/lna/vhf/off' class='btn btn-outline-info' role='button' style='width: 120px;'>OFF</a>\n";
    } else 
    {
      str += "<a href='/lna/vhf/on' class='btn btn-outline-info' role='button' style='width: 120px;'>ON</a>\n";      
      str += "<a href='/lna/vhf/off' class='btn btn-info' role='button' style='width: 120px;'>OFF</a>\n";
    }   
    str += "</div>\n</div>\n";

    //LNA UHF
    str +="<div class='col-12' style='margin-top: 5px;'>\n";
    str +="<div class='btn-group' role='group' aria-label='LNA UHF'>\n";
    str +="<a href='' class='btn btn-light' role='button' style='width: 97px;'><b>LNA UHF</b></a>\n";
    if (relay4_State == true) 
    {
      str += "<a href='/lna/uhf/on' class='btn btn-info' role='button' style='width: 120px;'>ON</a>\n";
      str += "<a href='/lna/uhf/off' class='btn btn-outline-info' role='button' style='width: 120px;'>OFF</a>\n";
    } else 
    {
      str += "<a href='/lna/uhf/on' class='btn btn-outline-info' role='button' style='width: 120px;'>ON</a>\n";      
      str += "<a href='/lna/uhf/off' class='btn btn-info' role='button' style='width: 120px;'>OFF</a>\n";
    }   
    str += "</div>\n</div>\n";
    
    return str;
}


void setup() {
  Serial.begin(115200); //Begin Serial at 115200 Baud
  
  //Static IP address setup. Remove or comment if you would like to use dynamic address
  IPAddress ip(192, 168, 1, 20);
  IPAddress dns(192, 168, 1, 1);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, dns, gateway, subnet);
  //--------------------------------------------
  
  WiFi.begin(ssid, password);  //Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
      delay(500);
      Serial.println("Waiting to connect...");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
  
  server.on("/", handleRoot); //Handle Index page
  server.on("/ant/vhf/on", handle_VHF_on); //Handle VHF on
  server.on("/ant/vhf/off", handle_VHF_off); //Handle VHF off
  server.on("/ant/uhf/on", handle_UHF_on); //Handle UHF on
  server.on("/ant/uhf/off", handle_UHF_off); //Handle UHF off
  server.on("/lna/vhf/on", handle_LNA_VHF_on); //Handle LNA VHF on
  server.on("/lna/vhf/off", handle_LNA_VHF_off); //Handle LNA VHF off
  server.on("/lna/uhf/on", handle_LNA_UHF_on); //Handle LNA UHF on
  server.on("/lna/uhf/off", handle_LNA_UHF_off); //Handle LNA UHF off
  
  server.begin(); //Start the server
  Serial.println("Server listening");
}

void loop() {
  server.handleClient(); //Handling of incoming client requests
}
