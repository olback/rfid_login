#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
MFRC522::MIFARE_Key key;
 
void setup() 
{
    Serial.begin(115200);
    SPI.begin();
    mfrc522.PCD_Init();
}

void loop() 
{
    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) 
    {
        return;
    }

    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) 
    {
        return;
    }

    //Show UID on serial monitor
    String content = "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    
    // Flush serial
    Serial.flush();

}
