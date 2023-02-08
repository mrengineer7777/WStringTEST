#include <Arduino.h>
#include <rom/rtc.h>

void setup() {
  Serial.begin(115200);                                                             //Open UART0

  //When first powered on, or reset via RST line: delay to allow USB to connect
  if(rtc_get_reset_reason(0)==POWERON_RESET) {
      delay(3000);
  }
  Serial.printf("-------------WString Testing---------------\r\n");
}

void loop() {
  Serial.println("Constructor Tests");

  char c1 = 'a';
  unsigned char c2 = 'a';
  String s_c1(c1);
  String s_c2(c1);
  Serial.printf("char Expecting a, a, got %s, %s\r\n", s_c1.c_str(), s_c2.c_str());

  int i1 = -12345;
  unsigned int i2 = 12345;
  String s_i1(i1);
  String s_i2(i2);
  Serial.printf("int Expecting -12345, 12345, got %s, %s\r\n", s_i1.c_str(), s_i2.c_str());

  long l1 = -123456;
  unsigned long l2 = 123456;
  String s_l1(l1);
  String s_l2(l2);
  Serial.printf("long Expecting -123456, 123456, got %s, %s\r\n", s_l1.c_str(), s_l2.c_str());

  long long ll1 = -12345678;
  unsigned long long ll2 = 12345678;
  String s_ll1(ll1);
  String s_ll2(ll2);
  Serial.printf("long Expecting -12345678, 12345678, got %s, %s\r\n", s_ll1.c_str(), s_ll2.c_str());

  Serial.println("Concat Tests");

  String chartest = "";
  char c10 = 'a';
  unsigned char c20 = 'a';
  chartest.concat(c10);
  chartest += ", ";
  chartest.concat(c20);
  Serial.printf("char Expecting a, a, got %s\r\n", chartest.c_str());

  String inttest = "";
  int i10 = -12345;
  unsigned int i20 = 12345;
  inttest.concat(i10);
  inttest += ", ";
  inttest.concat(i20);
  Serial.printf("int Expecting -12345, 12345, got %s\r\n", inttest.c_str());

  String longtest = "";
  long l10 = -123456;
  unsigned long l20 = 123456;
  longtest.concat(l10);
  longtest += ", ";
  longtest.concat(l20);
  Serial.printf("long Expecting -123456, 123456, got %s\r\n", longtest.c_str());

  String longlongtest = "";
  long long ll10 = -12345678;
  unsigned long long ll20 = 12345678;
  longlongtest.concat(ll10);
  longlongtest += ", ";
  longlongtest.concat(ll20);
  Serial.printf("long long Expecting -12345678, 12345678, got %s\r\n", longlongtest.c_str());

   Serial.println("---Tests completed---");

  delay(10000);
}