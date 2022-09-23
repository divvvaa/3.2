


/* 
  
  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int lIGHT_FELT;
  bool l_E_D;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <BH1750FVI.h>

BH1750FVI lightmeter(BH1750FVI::k_DevModeContLowRes);

WiFiClient client;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  pinMode(LED_BUILTIN,OUTPUT);
  lightmeter.begin();
  delay(2000);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  lIGHT_FELT = lightmeter.GetLightIntensity();
  delay(2000);
  
  if(lIGHT_FELT > 100) {
    l_E_D = true;
    digitalWrite(LED_BUILTIN,l_E_D);
  }
  
  else {
    l_E_D = false;
    digitalWrite(LED_BUILTIN,l_E_D);
  }
  delay(2000);
}





  
