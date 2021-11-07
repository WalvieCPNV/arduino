#include "music.h"

void setup() 
{
    for (int i = 2; i < 6; i++)
    {
        pinMode(i, OUTPUT);
    }

    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
    pinMode(A4, INPUT_PULLUP);
    pinMode(A5, INPUT_PULLUP);
}

void loop() 
{

    if (digitalRead(A4) == LOW)
    {
        digitalWrite(4, HIGH);
        midi();
    }
    else
    {
        digitalWrite(4, LOW);
    }

    delay(33.3);
}