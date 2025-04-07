# buzzer_mini_piano ![Wokwi CI](https://github.com/robotdevre/buzzer_mini_piano/actions/workflows/wokwi.yml/badge.svg)

Bu projede, Arduino Uno kullanılarak 9 farklı butona basıldığında piezo buzzer üzerinden farklı frekanslarda notalar çalan mini bir piyano yapılmıştır. Dahili `INPUT_PULLUP` özelliği ile her bir buton farklı bir nota üretir. `tone()` ve `noTone()` fonksiyonları kullanılarak temel sesli çıkış uygulamaları öğrenilir.

---

## 🔧 Kullanılan Malzemeler

- Arduino Uno  
- 9 x Buton  
- 1 x Piezo Buzzer  
- Jumper kablolar  

---

## 🎯 Proje Amacı

- `tone()` ve `noTone()` komutlarıyla buzzer sesi üretmek  
- `INPUT_PULLUP` ile dijital girişleri stabilize etmek  
- Diziler (arrays) ile pin ve frekansları yönetmek  
- Birden fazla girişe bağlı sesli sistem kurmak  

---

## 📷 Devre Şeması

📁 `diagram.json` dosyasında Wokwi uyumlu devre şeması bulunmaktadır.  
🔗 [Projeyi Wokwi'de görmek için tıklayın](https://wokwi.com/projects/426614220584259585)

---

## 💡 Kod

```cpp
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
  587  // Re (üst)
};

void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  bool played = false;

  for (int i = 0; i < 9; i++) {
    if (digitalRead
``` 
---

## 📫 Benimle İletişime Geç / Takip Et

Eğer proje hakkında bir fikrin varsa, soruların olursa ya da sadece selam vermek istersen; aşağıdaki kanallardan bana ulaşabilir ya da sosyal medya hesaplarımdan takip edebilirsin:

- 📧 [E-posta](mailto:info@robotdevre.com)  
- 📷 [Instagram](https://www.instagram.com/robotdevre/)  
- 🌐 [Web Sitesi](https://robotdevre.com/)  
- 🎥 [YouTube](https://www.youtube.com/@robotdevre)  
- 💼 [LinkedIn](https://www.linkedin.com/in/ugur-kerim-sirke/)  
- 🐦 [X (Twitter)](https://x.com/robotdevre)
