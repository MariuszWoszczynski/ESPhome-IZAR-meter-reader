#include "esphome.h"
#include "Arduino.h"
#include "ArduinoJson.h"
#include "izar_wmbus.h"

//uint32_t meterId = 0xFFFFFFFF;                          //comment to determine the ID of your counter, enter the ID and uncomment the line 
 
IzarWmbus reader;

class MyCustomSensor : public Component {
 public:
  Sensor *water_sensor = new Sensor();                            
  Sensor *id_sensor = new Sensor();                              
  
  void setup() {
       reader.init(0);                                    //to display all meters in range
//       reader.init(meterId);                            //uncomment the line after identifying your meter
  }
  
IzarResultData data;
StaticJsonDocument<200> doc;

  void loop() {

    FetchResult result = reader.fetchPacket(&data);
    if (result == FETCH_SUCCESSFUL) {
        int waterUsage = data.waterUsage;                      
        water_sensor->publish_state(waterUsage);

        uint32_t meterId = data.meterId;                //Uncomment from reading all the meters in the range. Comment this line after identifying your meter ID.             
        id_sensor->publish_state(meterId);

    } else {
        delay(300);
        reader.ensureRx(); 
    }
  }
};




