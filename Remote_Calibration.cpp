   #include <IRremote.hpp>  

const int RemotePin = 8; 

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RemotePin, ENABLE_LED_FEEDBACK);  
  Serial.println("IR Receiver is ready...");
}

void loop() {
  // IR signal
  if (IrReceiver.decode()) {
    // print hex code
    Serial.print("IR Code: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    IrReceiver.resume();
  }
}
