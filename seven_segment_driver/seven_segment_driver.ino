#include <ESP8266WiFi.h>

#include <stdint.h>
#include <stdbool.h>

#define C1        16
#define C2        5
#define C3        4
#define C4        0

#define SEG_A     2
#define SEG_B     14
#define SEG_C     12
#define SEG_D     13
#define SEG_E     15
#define SEG_F     3
#define SEG_G     1
#define SEG_DP    10

void setup(void)
{
  Serial.begin(115200);

  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  /*pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT); */

  Serial.println("7 Segment display driver test");
}


void DriveDisplay (uint8_t digit)
{
  Serial.println("Writing to digit " + String(digit));

  digitalWrite(C1, 1);
  digitalWrite(C2, 0);
  digitalWrite(C3, 0);
  digitalWrite(C4, 0);

  digitalWrite(SEG_A, 0);
  digitalWrite(SEG_B, 0);
  /*digitalWrite(SEG_C, 0);
  digitalWrite(SEG_D, 0);
  digitalWrite(SEG_E, 0); */
  /* digitalWrite(SEG_F, 0);
  digitalWrite(SEG_G, 0);
  digitalWrite(SEG_DP, 0); */

  for (uint8_t index = 0; index < 2; index++)
  {
    switch (index)
    {
      case 0:
        digitalWrite (SEG_A, 1);
        break;

      case 1:
        digitalWrite(SEG_B, 1);
        break;

      case 2:
        digitalWrite(SEG_C, 1);
        break;

      case 3:
        digitalWrite(SEG_D, 1);
        break;

      case 4:
        digitalWrite(SEG_E, 1);
        break;

      case 5:
        digitalWrite(SEG_F, 1);
        break;

      case 6:
        digitalWrite(SEG_G, 1);
        break;

      case 7:
        digitalWrite(SEG_DP, 1);
        break;
    }

    delay(300);
  }
}

void loop(void)
{
  DriveDisplay (0);
  delay(1000);
}