// This is the Code for the Laser Receiving Circuit
int phor = D0;
int ledwr = D9;
int  led = D7;
int buzz = D8;
int lastsensorreading = LOW;
int sensorreading = LOW;
int val;
int bing = D4; // The above section initializes which pins will be used in the Particle Argon

void setup() {
pinMode(ledwr, OUTPUT);
pinMode(led, OUTPUT);
pinMode(phor, INPUT_PULLUP);
pinMode(buzz, OUTPUT);
pinMode(bing, OUTPUT);
Particle.subscribe("llarson4", itreallyisbrokenfunc, ALL_DEVICES);
Particle.subscribe("jtrakas1",brokendoorfunc, ALL_DEVICES);
Particle.subscribe("fhawkins5", alarmonfunc, ALL_DEVICES);
              } // The void setup() section declares which pins will be used as inputs and outputs for the project as well as which events will be subscribed to. This allows Particle Communication


void loop() {
    lastsensorreading = sensorreading;
    sensorreading = digitalRead(phor);
    val = digitalRead(bing);    
    if (sensorreading == LOW && (lastsensorreading == HIGH)) {
        Particle.publish("jtrakas1", "Door Closed");
    }    
    if (sensorreading == HIGH && (lastsensorreading == LOW)) {
     Particle.publish("jtrakas1", "Door Open");
    }
    if (val == HIGH) {
    tone(buzz, 1568, 650);
        delay(500);
    }
    else {
        
    }
} // The void loop() section publishes an event every time a state switches (i.e. a door closes when it was previously open or opens when it was previously shut)

int brokendoorfunc(const char *event, const char *data)
{
    if (strcmp(data,"Door Open")==0){
      
    }
    else if (strcmp(data, "Door Closed")==0){
        
    }
    else{
        
    } // the brokendoorfunc function publishes data notifying whether the door used is open or closed
    
}    
int itreallyisbrokenfunc(const char *event, const char *data)
{
    if (strcmp(data,"broken")==0){
        digitalWrite(bing, HIGH);
    }
    else if (strcmp(data, "intact")==0){
        digitalWrite(bing, LOW);
    }
    else{
        
    }
} // the itreallyisbrokenfunc function writes the buzzer on or off depending on if a message is received from the transmission Argon

int alarmonfunc(const char *event, const char *data)
{
    if (strcmp(data,"Alarm On")==0){
        digitalWrite(led, HIGH);
    }
    else if (strcmp(data, "Alarm Off")==0){
        digitalWrite(led, LOW);
    }
    else{
        
    } // the alarmonfunc function writes an LED on or off depending on if a message is received from the data acquisition and cloud transmission Argon
    
}
