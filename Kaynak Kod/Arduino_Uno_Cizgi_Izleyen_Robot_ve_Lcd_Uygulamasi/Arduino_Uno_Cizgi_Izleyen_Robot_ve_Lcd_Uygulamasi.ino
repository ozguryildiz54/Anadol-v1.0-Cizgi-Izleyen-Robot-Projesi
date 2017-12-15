#include <LiquidCrystal.h> //Lcd kullanımı için bu kütüphaneyi kullanmamız gerekiyor.

//Motor sürücü pinleri tanımlandı
const int sag_i = 4; //Sağ tekerin ileri hareketi
const int sag_g = 5; //Sağ tekerin geri hareketi
const int sol_i = 7; //Sol tekerin ileri hareketi
const int sol_g = 6; //Sol tekerin geri hareketi

//Sensör pinleri tanımlandı
const int sol_sensor = 2;
const int orta_sensor = 1;
const int sag_sensor = 3;
int konum; //son konumu bulmak için kullanılır.

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // LCD'nin baglandigi Arduino pinleri

int sol_durum, sag_durum, orta_durum; // sol, orta ve sağ sensörün durum değişkenleri tanımlandı

int motor1 = A5; //Mmotorun biri A5 pinine bağlandı
int motor2 = A4; //Bir değeri ise A4 pinine bağlandı

void setup()
{
  // motor sürücü pinleri çıkış olarak atandı
  pinMode(sag_i, OUTPUT); 
  pinMode(sag_g, OUTPUT);
  pinMode(sol_i, OUTPUT);
  pinMode(sol_g, OUTPUT);
  
  // sensör pinleri giriş pini olarak atandı
  pinMode(sag_sensor, INPUT); 
  pinMode(sol_sensor, INPUT);
  pinMode(orta_sensor, INPUT);

  lcd.begin(16, 2); // Kullandigimiz LCDnin sutun ve satir sayisini belirtmeliyiz
  lcd.print("Anadol v. 1.0"); // Ekrana yazi yazalim
}

// Ana döngümüzün girişi
void loop()        
{
  lcd.setCursor(0, 1); //Lcd ekranının imleci sol alt köşededir
  // sol, orta ve sağ sensör okunup değişkenlere kaydedildi.  
  sol_durum = digitalRead(sol_sensor); 
  sag_durum = digitalRead(sag_sensor);
  orta_durum = digitalRead(orta_sensor);

  analogWrite(motor1, 255); 
  analogWrite(motor2, 255);
  if (sol_durum == HIGH && sag_durum == HIGH && orta_durum==LOW) // Sadece ortada ki sensör siyah bandı görüyor ise tüm motorlar ileri yönde çalıştırıldı.
  { 
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
    lcd.print("Araç düz devam ediyor.");
    konum=2;
  }
  else if (sol_durum == HIGH && sag_durum == LOW && orta_durum== HIGH) // sağ sensör siyah görüyor ise sol motor çalıştırıldı.
  {
    digitalWrite(sol_i, LOW);
    digitalWrite(sol_g, HIGH);
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);
    lcd.print("Araç sağa doğru dönüyor.");
    konum=3;
  }
  else if (sol_durum == LOW && sag_durum == HIGH && orta_durum== HIGH) // sol sensör siyah görüyor ise sağ motor çalıştırıldı.
  {
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
    digitalWrite(sag_i, LOW);
    digitalWrite(sag_g, HIGH);
    lcd.print("Araç sola doğru dönüyor.");
    konum=1;
  }
  else if (sol_durum == LOW && sag_durum == HIGH && orta_durum==LOW) // sol sensör ve orta sensör siyah görüyor ise iki motor dar çalıştırıldı.
  {
    lcd.print("Araç düz doğru hareket ediyor.");
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);  
    konum=2;
  }
  else if (sol_durum== HIGH && sag_durum== LOW && orta_durum==LOW) // sağ sensör ve orta sensör siyah görüyor ise ise iki motor dar çalıştırıldı.
  { 
    lcd.print("Araç düz hareket ediyor.");
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);
    konum=2;
  }
  else if (sol_durum== LOW && sag_durum== LOW && orta_durum==HIGH) //bu durum sensörlerin stabil olmamasından kaynaklı normalde olmamızı gereken bir durum
  { 
    digitalWrite(sag_i, HIGH);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, HIGH);
    digitalWrite(sol_g, LOW);
    konum=2;
  }
  else if(sol_durum== HIGH && sag_durum== HIGH && orta_durum==HIGH) //araç eğer pist dışındaysa son konuma git
  {
     if(konum==1)
     {
      digitalWrite(sol_i, HIGH);
      digitalWrite(sol_g, LOW);
      digitalWrite(sag_i, LOW);
      digitalWrite(sag_g, HIGH);
     }
     else if(konum==3)
     {
      digitalWrite(sol_i, LOW);
      digitalWrite(sol_g, HIGH);
      digitalWrite(sag_i, HIGH);
      digitalWrite(sag_g, LOW);
     }
     
     else if(konum==2)
     {
      digitalWrite(sag_i, HIGH);
      digitalWrite(sag_g, LOW);
      digitalWrite(sol_i, HIGH);
      digitalWrite(sol_g, LOW);
     }
  }
  else  //eğer yukarıda şartların hiçbiri değilse dur.
  {
    digitalWrite(sag_i, LOW);
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, LOW);
    digitalWrite(sol_g, LOW);
  }
}







