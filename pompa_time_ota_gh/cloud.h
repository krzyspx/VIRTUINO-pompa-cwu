
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "bbbbbbbbbbbbbbbbbbb";
const char DEVICE_KEY[]  = "ffffffffffffffffffff";    // Secret device password

void initProperties();

WiFiConnectionHandler ArduinoIoTPreferredConnection(ssid, password);
//--------------------------------
void cloudsetup() {

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // Connect to Arduino IoT Cloud

  //     Print info about cloud connetion set 0 to 4
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
}

void cloudloop() {
  ArduinoCloud.update();
}
