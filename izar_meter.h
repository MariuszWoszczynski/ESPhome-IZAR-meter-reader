#include "esphome.h"
#include "Arduino.h"
#include "ArduinoJson.h"
#include "izar_wmbus.h"


//int  meterId = 0xFFFFFFFF;      //comment to determine the ID of your counter, enter the ID (instead FFFFFFFF) and uncomment the line 

int waterUsage_temp;
int waterUsage;
IzarWmbus reader;

class MyCustomSensor : public Component, public TextSensor  {
 public:
  TextSensor *water_sensor = new TextSensor();   
  TextSensor *id_sensor = new TextSensor();
                       
  
  void setup() {
       reader.init(0);                                //to display all meters in range
//       reader.init(meterId);                        //uncomment the line after identifying your metera
  }
  
IzarResultData data;

  void loop() {

    FetchResult result = reader.fetchPacket(&data);
    if (result == FETCH_SUCCESSFUL) {
        waterUsage_temp = data.waterUsage;
        if ((waterUsage_temp > 0) and (waterUsage_temp < 10000000)) {    //data filter
            waterUsage = waterUsage_temp;
        } 
        char usage_text[32];
        itoa(waterUsage, usage_text, 10);
        water_sensor->publish_state(usage_text);
        
        int meterId = data.meterId;                //Uncomment from reading all the meters in the range. Comment this line after identifying your meter ID.              

        char ID_text[32];
        itoa(meterId, ID_text, 16);
        id_sensor->publish_state(ID_text);

    } else {
        delay(300);
        reader.ensureRx(); 
    }
  }
};


