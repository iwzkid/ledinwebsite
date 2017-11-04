#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server ( 80 );

const int led1 = 14;
const int led2 = 12;

char led_status;

void handleRoot() {
	char temp[400];
	snprintf ( temp, 400,

"<html>\
  <head>\
    <title>Lia</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
      a {font-size: 82px;}\
    </style>\
  </head>\
  <body>\
    <a href='/on1'>Set on</a>\
    <br>\
    <a href='/off1'>Set off</a>\
    <br>\
    <a href='/on2'>Set on</a>\
    <br>\
    <a href='/off2'>Set off</a>\
  </body>\
</html>" );
	server.send ( 200, "text/html", temp );
}

void setup ( void ) {
  pinMode ( led1, OUTPUT );
  pinMode ( led2, OUTPUT );

  WiFi.softAP("Leduri");

	server.on ( "/on1", led1_on );
  server.on ( "/off1", led1_off );
  server.on ( "/on2", led2_on );
  server.on ( "/off2", led2_off );
  

	server.onNotFound ( handleRoot );
	server.begin();
}

void loop ( void ) {
	server.handleClient();
}

void led1_on(){
  digitalWrite ( led1, HIGH );
  handleRoot();
}

void led1_off(){
  digitalWrite ( led1, LOW );
  handleRoot();
}
void led2_on(){
  digitalWrite ( led2, HIGH );
  handleRoot();
}

void led2_off(){
  digitalWrite ( led2, LOW );
  handleRoot();
}
