// Her bir butonun bağlı olduğu pinleri tanımlıyoruz  
const int buttonPins[9] = {12, 11, 10, 9, 8, 7, 6, 5, 4}; // 4 son butonun pini

// Buzzer'ın bağlı olduğu pin
const int buzzerPin = 3; // Buzzer artık 3. pine bağlı

// Her bir butona karşılık gelen frekansları tanımlıyoruz
const int tones[9] = {
  262, // Do
  294, // Re
  330, // Mi
  349, // Fa
  392, // Sol
  440, // La
  494, // Si
  523, // Do (üst)
  587  // Re (üst) — yeni eklenen butonun tonu
};

void setup() {
  Serial.begin(9600);
  delay(100); // Bazı durumlarda gerekli
  Serial.println("GITHUB TEST");
  
  // Buton pinlerini INPUT_PULLUP yapıyoruz
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Buzzer çıkış pini
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  bool played = false;

  // Butonları sırayla kontrol ediyoruz
  for (int i = 0; i < 9; i++) {
    // Butona basıldığında pin LOW olur (çünkü pull-up kullanıyoruz)
    if (digitalRead(buttonPins[i]) == LOW) {
      tone(buzzerPin, tones[i]);
      played = true;
      break; // İlk basılan tuşun sesini çal ve döngüden çık
    }
  }

  // Hiçbir tuşa basılmamışsa buzzeri sustur
  if (!played) {
    noTone(buzzerPin);
  }
}
