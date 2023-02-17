
#include <RCSwitch.h> // biblioteka obsługi nadawania i odbioru 433 MHz
RCSwitch mySwitch = RCSwitch();
#define ESP01 1
#define D1MINI 2
int procesor = D1MINI;
unsigned long o_kod = 0;
void czy_pompa();

int printon = 0; // flaga wysyłania danych na monitor
int terminalon = 0; // flaga wysyłania danych na terminal BLYNK

void pin16_rec(String value) {//button
  terminalon = value.toInt();
}

void no433setup()
{
  if (procesor == D1MINI) {
    mySwitch.enableReceive(12);  // port odbiornika
    mySwitch.enableTransmit(14); // nadajnika
  }
  if (procesor == ESP01) {
    mySwitch.enableReceive(3);  //
    mySwitch.enableTransmit(1); //
  }
}
int licznik = 0;
void no433akcja()
{

  if (mySwitch.available()) {
    licznik = licznik + 1;
    String str = String(("(" + String(licznik) + ") " + String(mySwitch.getReceivedValue()) + " / " + String(mySwitch.getReceivedBitlength()) + " / " + String(mySwitch.getReceivedDelay())
                         + " / "  + "" + String(mySwitch.getReceivedProtocol()) ));
    if (terminalon) {// przełącznik wysyłania info na terminal
      if (licznik == 1) sendValue(pin17, str);
      if (licznik == 2) sendValue(pin18, str);
      if (licznik == 3) sendValue(pin19, str);
      if (licznik == 4) sendValue(pin20, str);
      if (licznik == 5) sendValue(pin21, str);
      if (licznik == 6) sendValue(pin22, str);
    }
    if (licznik > 5)licznik = 0;
    sendValue(pin3, str);
    Serial.println(str);

    o_kod = mySwitch.getReceivedValue();

    mySwitch.disableReceive();
    czy_pompa();
    mySwitch.resetAvailable();
    no433setup();
  }
}

void sendkod(unsigned long code, int impuls, byte bity, byte prot) { // wysłanie kodu
  mySwitch.disableReceive();

  mySwitch.setPulseLength(impuls);
  mySwitch.setRepeatTransmit(10);
  mySwitch.send(code, bity);

  no433setup();
}

void sendkodpilot (unsigned long code) {
  sendkod(code, 340, 24, 1);
}
