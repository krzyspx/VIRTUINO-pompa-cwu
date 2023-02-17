#define pirpompa 14013756

//#define pompaoff 4478228 //zmienic
//#define pompaon  4478225
#define pompaoff 17748 //zmienic
#define pompaon  17745

#define czasobiegu  24  // ilość sek włączenia pompy x 10
#define pompapilot 7730435 //

int obieg = -3;

void pin6_rec(String value) //LED in ESP
{
  int v = value.toInt();
  if (v == 1) digitalWrite(led_wew, HIGH); else digitalWrite(led_wew, LOW);
}

void programsetup() {
}
void programakcja() {

}
void pompazal() //wysyłanie kodu do załączenia pompy
{
  sendkodpilot(pompaon);
  Serial.println(pompaon);
  sendValue(pin11, String(obieg));
}
void pompastop() //wysyłanie kodu do wyłączenia pompy
{
  sendValue(pin12, String(0));
  akcja.updateInterval(2, 2000);
}
void czy_pompa() {
  if ((o_kod == pirpompa) || (o_kod == pompapilot)) {
    obieg = czasobiegu;
    pompazal();
    o_kod =  0;
    akcja.updateInterval(2, 300);
    sendValue(pin12, String(1));
  }
}

void program_timer() {
  if (obieg < -2) obieg = -3; else {
    if (obieg < 1) {
      if (obieg == 0)   pompastop();
      sendkodpilot(pompaoff);
      Serial.println(pompaoff);
    }  else {
      pompazal();
    }
  }
  obieg--;
}

void pin15_rec(String value)
{
  int v = value.toInt();
  if (v)  o_kod = pirpompa;
}
int tk = 0;
void ntp_timer() { // załączanie pompy o określonych godzinach
  get_time_ntp();

  if (time_compare(9, 0))  o_kod = pirpompa;
  if (time_compare(10, 0))  o_kod = pirpompa;
  if (time_compare(11, 0))  o_kod = pirpompa;
  if (time_compare(21, 0))  o_kod = pirpompa;
  if (time_compare(22, 0))  o_kod = pirpompa;
  if (time_compare(23, 0))  o_kod = pirpompa;
}
