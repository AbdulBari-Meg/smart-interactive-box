// Smart Interactive Box - High School Graduation Project
// Developed by: AbdulBari Hakmi

#include <SoftwareSerial.h> // مكتبة التحكم بالصوت والاتصال

const int sensorPin = 2;        // الحساس الرقمي متصل بالمنفذ رقم 2
const int ledPin = 13;         // الإضاءة التفاعلية متصلة بالمنفذ رقم 13
int boxState = 0;              // متغير لقراءة حالة الصندوق (مفتوح/مغلق)

void setup() {
  pinMode(ledPin, OUTPUT);     // تعيين منفذ الإضاءة كمخرج
  pinMode(sensorPin, INPUT);   // تعيين منفذ الحساس كمدخل لقراءة الحالة
  Serial.begin(9600);          // بدء الاتصال التسلسلي لمراقبة النظام
}

void loop() {
  // قراءة البيانات القادمة من حساس الحركة أو فتح الصندوق
  boxState = digitalRead(sensorPin);

  if (boxState == HIGH) { 
    // إذا تم فتح الصندوق أو استشعار حركة
    digitalWrite(ledPin, HIGH);   // تشغيل الإضاءة التفاعلية فوراً
    Serial.println("Box Opened! Playing Audio Module...");
    delay(5000);                  // انتهاء تشغيل المقطع التفاعلي لمدة 5 ثوانٍ
  } else {
    // إذا كان الصندوق مغلقاً
    digitalWrite(ledPin, LOW);    // إطفاء الإضاءة
  }
  delay(100); // استقرار النظام
}
