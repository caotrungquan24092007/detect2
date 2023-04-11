#include <SoftwareSerial.h> //Thư viện sử dụng bất kỳ 2 chân digital nào để làm chân TX RX
#include <Servo.h>
SoftwareSerial mybluetooth(2,3); // Khai báo tên Bluetooth và chân TX RX (2-TX, 3-RX)
Servo myservo;

String incomingByte ; 
int led = 9;   
 
char docgiatri; //Biến docgiatri kiểu char
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  mybluetooth.begin(9600); //Kết nối Bluetooth với tốc độ baud là 9600
}
void loop() {
  
  if(mybluetooth.available() > 0) {
    docgiatri = mybluetooth.read(); //Đọc các giá trị trên app được kết nối qua bluetooth và gán vào docgiatri
    if (docgiatri == ('1')) {digitalWrite(led,HIGH);}
    if (docgiatri == ('2')) {digitalWrite(led,LOW);}
    if (docgiatri == ('3')) {if (pos == 0){for(pos = 0; pos < 120; pos += 1){ myservo.write(pos); delay(20);}}}
    if (docgiatri == ('4')) {if (pos == 120){for(pos = 120; pos >= 1; pos -= 1){myservo.write(pos);delay(20);}}}
    Serial.println(docgiatri);
  }
  
  if (Serial.available() > 0) {
    incomingByte = Serial.readStringUntil('\n');
    if (incomingByte == "1") {digitalWrite(led, HIGH); } 
    else if (incomingByte == "2") {digitalWrite(led, LOW);}
  }
  

}
