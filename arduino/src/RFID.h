#ifndef RFID
#define RFID

#include <MFRC522.h>
#include <SPI.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 *mfrc522;

//== function declaration ==============================

bool read_RFID();

//== function definition ==============================

bool read_RFID() {
    if( mfrc522 -> PICC_IsNewCardPresent() && mfrc522 -> PICC_ReadCardSerial() ) {

        byte *id = mfrc522 -> uid.uidByte;
        byte idSize = mfrc522 -> uid.size;

        BT.write( "RFID: " );
        for ( byte i = 0; i < idSize; i++ ) {
            BT.print( id[i], HEX );
        }
        BT.write( '\n' );
        mfrc522 -> PICC_HaltA();
        return true;
    }
    return false;
}

#endif

