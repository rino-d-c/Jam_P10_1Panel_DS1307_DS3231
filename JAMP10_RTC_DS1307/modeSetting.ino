


void modeSetMenit()
{
  if (tmenit <= 9)
  {
    char menit[3];
    stringBuff = String(tmenit);
    stringBuff.toCharArray(menit, 3);
    dmd.drawChar(19, 0, '0', GRAPHICS_NORMAL);
    dmd.drawMarquee(menit, 3, 25, 0);
  }
  else
  {
    char menit[3];
    stringBuff = String(tmenit);
    stringBuff.toCharArray(menit, 3);
    dmd.drawMarquee(menit, 3, 19, 0);
  }
  if (digitalRead(UP) == LOW)
  {
    delay(250);
    tmenit++;
    dmd.clearScreen( true );
    if (tmenit > 59)
      tmenit = 0;
  }
}

void modeSetJam()
{
  if (tjam <= 9)
  {
    char jam[3];
    stringBuff = String(tjam);
    stringBuff.toCharArray(jam, 3);
    dmd.drawChar(2, 0, '0', GRAPHICS_NORMAL);
    dmd.drawMarquee(jam, 3, 8, 0);
  }
  else
  {
    char jam[3];
    stringBuff = String(tjam);
    stringBuff.toCharArray(jam, 3);
    dmd.drawMarquee(jam, 3, 2, 0);
  }
  if (digitalRead(UP) == LOW)
  {
    delay(250);
    tjam++;
    dmd.clearScreen( true );
    if (tjam > 23)
      tjam = 0;
  }
}

void modeSetHari()
{
  stringBuff = shari[thari];
  char hari[9];
  stringBuff.toCharArray(hari, 9);
  dmd.drawMarquee(hari, 5, 1, 9);

  if (digitalRead(UP) == LOW)
  {
    delay(250);
    thari++;
    dmd.clearScreen( true );
    if (thari == 7)
      thari = 0;
  }

}

void modeSetTanggal()
{
  if (ttanggal < 10)
  {
    char tanggal[3];
    stringBuff = String(ttanggal);
    stringBuff.toCharArray(tanggal, 3);
    dmd.drawChar(1, 9, '0', GRAPHICS_NORMAL);
    dmd.drawMarquee(tanggal, 3, 7, 9);
  }
  else
  {
    char tanggal[3];
    stringBuff = String(ttanggal);
    stringBuff.toCharArray(tanggal, 3);
    dmd.drawMarquee(tanggal, 3, 1, 9);
  }
  if (digitalRead(UP) == LOW)
  {
    delay(250);
    ttanggal++;
    dmd.clearScreen( true );
    DateTime dt(ttahun, tbulan, ttanggal, tjam, tmenit, 0, thari);
    rtc.setDateTime(dt);
    if (ttanggal > 31)
      ttanggal = 1;

  }
}

void modeSetBulan()
{
  if (tbulan < 10)
  {
    char bulan[3];
    stringBuff = String(tbulan);
    stringBuff.toCharArray(bulan, 3);
    dmd.drawChar(19, 9, '0', GRAPHICS_NORMAL);
    dmd.drawMarquee(bulan, 3, 25, 9);
  }
  else
  {
    char bulan[3];
    stringBuff = String(tbulan);
    stringBuff.toCharArray(bulan, 3);
    dmd.drawMarquee(bulan, 3, 19, 9);
  }
  if (digitalRead(UP) == LOW)
  {
    delay(250);
    tbulan++;
    dmd.clearScreen( true );
    if (tbulan > 12)
      tbulan = 1;
  }
}

void modeSetTahun()
{
  char tahun[6];
  stringBuff = " " + String(ttahun) + " ";
  stringBuff.toCharArray(tahun, 7);
  dmd.drawMarquee(tahun, 6, -2, 9);
  if (digitalRead(UP) == LOW)
  {
    delay(250);
    ttahun++;
    dmd.clearScreen( true );
    if (ttahun > 2099)
      ttahun = 2010;
  }
}

