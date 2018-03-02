void modeNormal()
{  
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    tampilJam();
    count++;
    if (count <= 10)
    {
      tampilHari();
    }
    else if (count > 10 && count <= 25)
      tampilTanggal();
    else
      tampilTahun();

    if (count == 35)
    {
      count = 0;
    }
  }
}

void tampilJam()
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



  colon = !colon;
  if ( colon == true )
    dmd.drawChar(14, 0, ':', GRAPHICS_OR );
  else
    dmd.drawChar(14, 0, ':', GRAPHICS_NOR );
}

void tampilHari()
{
  stringBuff = shari[thari];
  char hari[9];
  stringBuff.toCharArray(hari, 9);
  dmd.drawMarquee(hari, 5, 1, 9);
}

void tampilTanggal()
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
  dmd.drawChar(13, 9, '/', GRAPHICS_NORMAL );

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

}

void tampilTahun()
{
  char tahun[8];
  stringBuff = " " + String(ttahun) + " ";
  stringBuff.toCharArray(tahun, 7);
  dmd.drawMarquee(tahun, 6, -2, 9);
}

