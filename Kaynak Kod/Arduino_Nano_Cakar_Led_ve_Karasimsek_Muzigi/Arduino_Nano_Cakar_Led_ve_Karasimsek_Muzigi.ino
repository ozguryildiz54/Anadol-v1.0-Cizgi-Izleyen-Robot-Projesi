const int buzzer = 9; 
const float songspeed = 1.5; 

int ledDelay = 50; //ledlerin çalışma arası zamanını ayarladık
int redPin = 12; //kırmızı ledimizi tanımladık
int redPin2 = 11; //2. kırmızı ledimizi tanımladık
int bluePin = 2; //mavi ledimizi tanımladık
int bluePin2 = 4; //2. mavi ledimizi tanımladık
int whitePin = 10; //beyaz ledimizi tanımladık
int whitePin2 = 6; //2. beyaz ledimizi tanımladık

//Karaşimşek Müziğinin Notalarının Tanımlaması
#define NOTE_C4  262   //Defining note frequency
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

int notes[] = 
{
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4, 
   
   //İlk parçanın tekrarı
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,
   //Tekrar burada bitiyor

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};

int duration[] = 
{         
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  //İlk bölümün tekrarı
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  //Tekrarın Sonu
  
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};

void setup() 
{
  pinMode(redPin, OUTPUT); //kırmızı ledimizi çıkış olarak atadık
  pinMode(redPin2, OUTPUT); //2. kırmızı ledimizi çıkış olarak atadık
  pinMode(bluePin, OUTPUT); //mavi ledimizi çıkış olarak atadık
  pinMode(bluePin2, OUTPUT); //2. mavi ledimizi çıkış olarak atadık
  pinMode(whitePin, OUTPUT); //beyaz ledimizi çıkış olarak atadık
  pinMode(whitePin2, OUTPUT); //2. beyaz ledimizi çıkış olarak atadık
}
 
void loop() 
{
 for (int i=0;i<203;i++)
 {
  int wait = duration[i] * songspeed;
  tone(buzzer,notes[i],wait);
  digitalWrite(redPin, HIGH); //ledlerin çakar birşekilde çalışmasını sağladık
  digitalWrite(redPin2, HIGH); //ledlerin çakar birşekilde çalışmasını sağladık
  delay(ledDelay);
  digitalWrite(redPin, LOW); //ledlerin çakar birşekilde çalışmasını sağladık
  digitalWrite(redPin2, LOW); //ledlerin çakar birşekilde çalışmasını sağladık
  delay(ledDelay);i++;tone(buzzer,notes[i],wait);
  
  digitalWrite(bluePin, HIGH); //ledlerin çakar birşekilde çalışmasını sağladık
  digitalWrite(bluePin2, HIGH); //ledlerin çakar birşekilde çalışmasını sağladık
  delay(ledDelay);
  digitalWrite(bluePin, LOW); //ledlerin çakar birşekilde çalışmasını sağladık
  digitalWrite(bluePin2, LOW); //ledlerin çakar birşekilde çalışmasını sağladık
  delay(ledDelay);i++;tone(buzzer,notes[i],wait);
  
  digitalWrite(whitePin, HIGH); //ledlerin çakar birşekilde çalışmasını sağladık
  digitalWrite(whitePin2, HIGH); //ledlerin çakar birşekilde çalışmasını sağladık
  delay(ledDelay);
  digitalWrite(whitePin, LOW); //ledlerin çakar birşekilde çalışmasını sağladık
  digitalWrite(whitePin2, LOW); //ledlerin çakar birşekilde çalışmasını sağladık
  delay(ledDelay);i++;tone(buzzer,notes[i],wait);
  delay(wait);} 
}

