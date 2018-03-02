// Jam digital P10 DS1302 by Rino DC @micropwr
#include <Wire.h>
#include "DS1302.h"
#include "Sodaq_DS3231.h"
#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
#define SETTING 4
#define UP 3
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

unsigned long previousMillis = 0;
unsigned long currentMillis;
const int interval = 1000;

boolean colon;
byte count;
byte mode = 0;

String shari[7] = {"Ahad   ", "Senin   ", "Slasa   ", "Rabu   ", "Kamis   ", "Jumat   ", "Sabtu  "};

String stringBuff;
byte tjam;
byte tmenit;
byte thari;
byte ttanggal;
byte tbulan;
int ttahun;


void ScanDMD()
{
  dmd.scanDisplayBySPI();
  dmd.setBrightness(255);
}


void setup(void)
{
  Serial.begin(115200);
  Wire.begin();
  rtc.begin();
  pinMode(SETTING, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);


  Timer1.initialize( 4000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
  Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

  dmd.clearScreen( true );
  dmd.selectFont(SystemFont5x7);

}

void loop(void)
{
  //Serial.println(mode);
  DateTime now = rtc.now();
  tjam = now.hour();
  tmenit = now.minute();
  thari = now.dayOfWeek();
  ttanggal = now.date();
  tbulan = now.month();
  ttahun = now.year();
  
  if (digitalRead(SETTING) == LOW)
  {
    delay(250);
    dmd.clearScreen( true );
    mode++;
  }
  if (mode == 0)
  {
    modeNormal();
  }
  if (mode == 1)
  {
    modeSetMenit();
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
  }
  if (mode == 2)
  {
    modeSetJam();
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
  }
  if (mode == 3)
  {
    modeSetHari();
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
  }
  if (mode == 4)
  {
    modeSetTanggal();
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
  }
  if (mode == 5)
  {
    modeSetBulan();
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
  }
  if (mode == 6)
  {
    modeSetTahun();
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
  }
  if (mode >= 7)
  {
    mode = 0;
  }
}
