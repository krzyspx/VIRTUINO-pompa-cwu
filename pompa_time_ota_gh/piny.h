bool sendValue(const char* tag, String value);
bool sendValue(const char* tag, String value);


//====== predefinicje funkcji z innych bloków programu

void pin6_rec(String value);
void pin15_rec(String value);
void pin16_rec(String value) ;
void pin22_rec(String value) ;
void pin23_rec(String value) ;
void pin24_rec(String value) ;
void pin25_rec(String value) ;
void pin26_rec(String value) ;

//======= deklaracje wartości początkowych

int pin11_lastValue = 0;

// deklaracje pinów łączących ESP i APP
// ESP -------> app
const char* pin0 = "V0"; //led
const char* pin1 = "V1";  //przelacznik
const char* pin2 = "V2";
const char* pin3 = "V3";   //wys kod
const char* pin4 = "V4";   //temp
const char* pin5 = "V5";
// app ------> ESP
const char* pin6 = "V6";
//------------------------------zmienne programu
const char* pin10 = "V10";
const char* pin11 = "V11";  //obieg  esp>app
const char* pin12 = "V12";  //wskaznik działania pompy  esp>app
const char* pin13 = "V13";
const char* pin14 = "V14";
const char* pin15 = "V15";  // zał pompy esp<app
const char* pin16 = "V16";  // terminal om esp<app
const char* pin17 = "V17";  // vvvv   pseudo terminal
const char* pin18 = "V18";
const char* pin19 = "V19";
const char* pin20 = "V20";
const char* pin21 = "V21";   //^^^^^
const char* pin22 = "V22";  //przycisk programowania <app
const char* pin23 = "V23";  // kod <app
const char* pin24 = "V24";  // impuls <app
const char* pin25 = "V25";  //ilość bitów <app
const char* pin26 = "V26";  //protokoł <app
const char* pin27 = "V27";
const char* pin28 = "V28";
const char* pin29 = "V29";
const char* pin30 = "V30";
//===================================================== sendPinStatus
// It is called every time a new client is connected.
// The void informs Virtuino app about the current pin states and variable values.
void printSetcod();
void sendPinsStatus() {
  sendValue(pin11, String(pin11_lastValue));    // send pin11 value
  printSetcod();

}

//===================================================== onValueReceived
// It is called every time a new value received  - add ---> esp

void onValueReceived(String tag, String value) {
  Serial.println("Received: tag=" + tag + "  value=" + value);

  if (tag == "V6") pin6_rec(value); // led in esp

  if (tag == "V15") pin15_rec(value);  // zał pompy
  if (tag == "V16") pin16_rec(value);  // terminal on
  if (tag == "V22") pin22_rec(value);  // przycisk programowania
  if (tag == "V23") pin23_rec(value);   //kod
  if (tag == "V24") pin24_rec(value);   //impuls
  if (tag == "V25") pin25_rec(value);   //ilosc bitów
  if (tag == "V26") pin26_rec(value);   //protokol

}
