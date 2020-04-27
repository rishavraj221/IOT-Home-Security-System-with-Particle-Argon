//LASER EMMITTING ARGON

int led= D7;
int laser = D0; //laser emmitter
int buzzer = D4; //active buzzer
int ledstate=LOW; //read led state


void setup() {
 
  pinMode(led, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Particle.subscribe("jtrakas1", brokendoorfunc, ALL_DEVICES); // function from J. Trakas Argon - Laser reciever
  Particle.subscribe("llarson4", itreallyisbrokenfunc, ALL_DEVICES); // communication back to J. rakas Argon
    
}


void loop(){
     
digitalWrite(laser, HIGH);

ledstate= digitalRead(D7);

if (ledstate == HIGH){
 
tone(buzzer, 2093, 650);
delay(500);
/*tone(buzzer, 5500, 650);
delay(75);*/

}
}   


int brokendoorfunc(const char *event, const char *data) //Read function from Argon 2
{
    if(strcmp(data, "Door Open")==0){
        digitalWrite(led, HIGH);
        Particle.publish("llarson4", "broken"); //Publish broken to signal Argon 2
      
    }
    else if (strcmp(data, "Door Closed")==0){
        digitalWrite(led, LOW);
        Particle.publish("llarson4", "intact");
    }
    else{
        
    }
}

int itreallyisbrokenfunc(const char *event, const char *data)
{
    if(strcmp(data, "broken")==0){
        
    }
    if(strcmp(data,"intact")==0){
        
    }
}
