//Security system data acquisition code

//This device receives the signal that the door is open and activates a buzzer, turns on 
// an led, sends a signal back to the emitter device, and sends a signal to IFTTT to send the phone alert

//Define components
int led = D7;
int buzzer = D4;
int val;


//Setup components and define functions
void setup() {
    
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Particle.subscribe("jtrakas1", brokendoorfunc, ALL_DEVICES);
  Particle.subscribe("fhawkinsifttt", fhawkinsiftttfunc);
  Particle.subscribe("fhawkins5", alarmonfunc, ALL_DEVICES);
  
}


//Loop checking the state of the led to determine if the buzzer should be on
void loop() {

   val = digitalRead(led);
   if(val == HIGH){
       tone(buzzer, 1047, 650);
       delay(500);
        }
            
     else{
         
       }
       
}


//Function to receive the state of the door
int brokendoorfunc(const char *event, const char *data)
    {
     
    if (strcmp(data, "Door Open") == 0){ //If door is open, then turn led on and send signal to IFTTT and send signal to turn alarm on
         digitalWrite(led, HIGH);
         Particle.publish("fhawkinsifttt", "alarm");
         Particle.publish("fhawkins5", "1"); //This command goes to IFTTT and compiles data into a Google sheet to create a graph 
    
    }
     
    else if (strcmp(data, "Door Closed") == 0){ //If door is closed turn led off and send signals to turn alarm off 
         digitalWrite(led, LOW);
         Particle.publish("fhawkinsifttt", "safe");
         Particle.publish("fhawkins5", "Alarm Off");
    }
     
    else{ //If it does not receive one of the previous commands, then do nothing
        
    }
    
}


int fhawkinsiftttfunc(const char *event, const char *data)
    {
    //IFTTT function does not need anything here in order to function
    }


int alarmonfunc(const char *event, const char *data)
    {
        
     if (strcmp(data, "Alarm On") == 0){ //Alarm function does need something inside here to work because it is communicating to other Particle devices
     
    }
     
     else if (strcmp(data, "Alarm Off") == 0){
        
     }
     
    else{
        
    }
    
}
