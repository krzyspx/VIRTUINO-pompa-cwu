
unsigned long kodZapp = 0;
int impulsZapp = 0;
byte bityZapp = 0;
byte protZapp = 0;

void sendkod(unsigned long code, int impuls, byte bity, byte prot);


void printSetcod() {
  String str = String (String (kodZapp) + " / " + String(impulsZapp) + " / " + String(bityZapp) + " / " + String(protZapp));
  Serial.println(str);
  sendValue(pin27, str);
}

void pin22_rec(String value) {
  int v = value.toInt();
  if (v) {
      unsigned long a = kodZapp; 
      sendkod(a, impulsZapp, bityZapp, protZapp);
  }
}
void pin23_rec(String value) {
  String str = value;
  kodZapp = atol(str.c_str());
  printSetcod();
}
void pin24_rec(String value) {
  impulsZapp = value.toInt();
  printSetcod();
}
void pin25_rec(String value) {
  int v = value.toInt();
  bityZapp = byte(v);
  printSetcod();
}
void pin26_rec(String value) {
  int v = value.toInt();
  protZapp = byte(v);
  printSetcod();
}
