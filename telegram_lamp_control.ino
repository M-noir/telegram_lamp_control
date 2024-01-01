//EDISON SCIENCE CORNER
//EDISON SCIENCE CORNER
//EDISON SCIENCE CORNER


#include "CTBot.h"
CTBot myBot;

String ssid = "edison science corner";     //  YOUR WIFI SSID
String pass = "eeeeeeee"; // YOUR WIFI PASSWORD
String token = "1738613562:AAFwe-C43OexjkRV3G_gpsaQW7Xes2FMAb4";   // REPLACE Token WITH YOUR TELEGRAM BOT TOKEN
int bulb1 = D0;            
int bulb2 = D1;                           
                            						

void setup() {
	Serial.begin(9600);
	Serial.println("Starting Bot...");
	myBot.wifiConnect(ssid, pass);

	myBot.setTelegramToken(token);

	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection Not OK");
	pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
	digitalWrite(bulb1, LOW); 
  digitalWrite(bulb2, LOW);
}

void loop() {
	TBMessage msg;

	if (myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("LIGHT ON")) {             
			digitalWrite(bulb1, HIGH);
			myBot.sendMessage(msg.sender.id, "LIGHT is now ON");  
		}
		else if (msg.text.equalsIgnoreCase("LIGHT OFF")) {        
			digitalWrite(bulb1, LOW);                             
			myBot.sendMessage(msg.sender.id, "LIGHT is now OFF"); 
		}
   else if (msg.text.equalsIgnoreCase("FAN ON")) {        
     digitalWrite(bulb2, HIGH);                             
      myBot.sendMessage(msg.sender.id, "FAN is now ON"); 
    }
    else if (msg.text.equalsIgnoreCase("FAN OFF")) {       
      digitalWrite(bulb2, LOW);                            
      myBot.sendMessage(msg.sender.id, "FAN is now OFF"); 
    }
		else {                                                   
			String reply;
			reply = (String)"Welcome " + msg.sender.username + (String)". Lets think try do!.";
			myBot.sendMessage(msg.sender.id, reply);             
		}
	}
	delay(100);
}