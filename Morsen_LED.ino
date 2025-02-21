// GPIO-Pin für die LED
const int LED_PIN = D5; // Du kannst diesen Pin anpassen

// Morsecode-Zeichen für Zahlen 0-9 und Buchstaben A-Z
const char* morseCharacters[] = 
{
  "-----", // 0
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----.", // 9
  ".-",    // A
  "-...",  // B
  "-.-.",  // C
  "-..",   // D
  ".",     // E
  "..-.",  // F
  "--.",   // G
  "....",  // H
  "..",    // I
  ".---",  // J
  "-.-",   // K
  ".-..",  // L
  "--",    // M
  "-.",    // N
  "---",   // O
  ".--.",  // P
  "--.-",  // Q
  ".-.",   // R
  "...",   // S
  "-",     // T
  "..-",   // U
  "...-",  // V
  ".--",   // W
  "-..-",  // X
  "-.--",  // Y
  "--.."   // Z
};

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  // Morsecode anzeigen
  displayMorse("HELLO WORLD", 300); // Hier den Text einfügen und die Geschwindigkeit anpassen
}

void displayMorse(const char* text, int unit) 
{
  for (int i = 0; text[i] != '\0'; i++) 
  {
    char c = text[i];
    if (c >= '0' && c <= '9') 
    {
      int number = c - '0';
      const char* morse = morseCharacters[number];
      for (int j = 0; morse[j] != '\0'; j++) 
      {
        if (morse[j] == '.') 
        {
          digitalWrite(LED_PIN, HIGH); // LED einschalten (Punkt)
          delay(unit);
          digitalWrite(LED_PIN, LOW); // LED ausschalten (Punkt)
          delay(unit);
        } 
        else if (morse[j] == '-') 
        {
          digitalWrite(LED_PIN, HIGH); // LED einschalten (Strich)
          delay(3 * unit);
          digitalWrite(LED_PIN, LOW); // LED ausschalten (Strich)
          delay(unit);
        }
      }
      delay(3 * unit); // Pause zwischen den Morsezeichen
    } 
    else if (c == ' ') 
    {
      delay(7 * unit); // Pause zwischen den Wörtern
    } else if (c >= 'A' && c <= 'Z') 
    {
      int letterIndex = c - 'A' + 10; // 10 ist der Index für 'A'
      const char* morse = morseCharacters[letterIndex];
      for (int j = 0; morse[j] != '\0'; j++) 
      {
        if (morse[j] == '.') 
        {
          digitalWrite(LED_PIN, HIGH); // LED einschalten (Punkt)
          delay(unit);
          digitalWrite(LED_PIN, LOW); // LED ausschalten (Punkt)
          delay(unit);
        } 
        else if (morse[j] == '-') 
        {
          digitalWrite(LED_PIN, HIGH); // LED einschalten (Strich)
          delay(3 * unit);
          digitalWrite(LED_PIN, LOW); // LED ausschalten (Strich)
          delay(unit);
        }
      }
      delay(3 * unit); // Pause zwischen den Morsezeichen
    }
  }
}
