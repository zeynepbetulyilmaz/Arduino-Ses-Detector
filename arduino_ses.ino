//HC05 Bluetooth Modülü Sesle Role Kontrolü 
String metniOku = ""; 
int cihaz = 9; // 9. pine bağlı cihazı tanımladık (led, role vs.) 
void setup() { 
pinMode(cihaz, OUTPUT); 
digitalWrite(cihaz, HIGH); // Aktif düşük role başlangıçta HIGH ile çalışmamasını sağladık 
Serial.begin(9600); //Bluetooth bağlantı hızını 9600 olarak ayarladık 
} 
void loop() { 
while (Serial.available()) { // Bluetooth bağlantısı var ise 
char c = (char)Serial.read(); 
metniOku += c; 
} 
if (metniOku.length() > 0) { // Eğer komut var ise 
if (metniOku == "cihazı çalıştır") { // gelen komut kontrolüne göre işlem yaptırıyoruz 
digitalWrite(cihaz, LOW); // Aktif düşük role LOW komutu ile çalışmasını sağladık 
} 
if (metniOku == "Cihazı kapat") { 
digitalWrite(cihaz, HIGH); // Aktif düşük role HIGH komutu ile çalışmamasını sağladık 
} metniOku = ""; //gelen mesajı sıfırlıyoruz } 
delay(100); 
}
