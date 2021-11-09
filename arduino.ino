/*
Author: Arthur Bottemanne
Description: Make an arduino program that plays simon says
Version: 09.11.21
*/

#include "jingle.h"

#define BLUE_LED  165
#define YELLOW_LED  131
#define RED_LED  110
#define GREEN_LED  82
#define INCORRECT  33

int Sequence[31] = {0};

int freeSpace = 0;

int speedMultiplyer = 1;

int blueButton = digitalRead(A2);
int yellowButton = digitalRead(A3);
int redButton = digitalRead(A4);
int greenButton = digitalRead(A5);

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

    randomSeed(analogRead(0));

    Serial.begin(9600);
}

void resetGame()
{
    Sequence[31] = {0};
    freeSpace = 0;
    speedMultiplyer = 1;
}

void generateLed()
{
    int randomLed = random(2, 6);
    Sequence[freeSpace] = randomLed;
    freeSpace++;
}

void checkSpeedIncrease()
{
    if (freeSpace % 3 == 0)
    {
        speedMultiplyer += 0.1;
    }
    
}

void showLed()
{
    for (int i = 0; i < freeSpace; i++)
    {
        digitalWrite(Sequence[i], HIGH);
        delay(300/speedMultiplyer);
        digitalWrite(Sequence[i], LOW);
        delay(200/speedMultiplyer);
    }
}

void verifyInput(int number, int playerInputCount, int buzzerFrequency)
{
    if (number == Sequence[playerInputCount])
    {
        tone(tonePin, buzzerFrequency);
        Serial.println("Correct!");
    }
    else
    {
        tone(tonePin, INCORRECT);
        Serial.println("Incorrect!");
        resetGame();
        delay(200);
        noTone(tonePin);
    }
}

void verifySequence(int number, int playerInputCount, int buzzerFrequency)
{
    if (number == Sequence[playerInputCount])
    {
        Serial.println("Correct!");
    }
    else
    {
        tone(tonePin, INCORRECT);
        Serial.println("Incorrect!");
        resetGame();
        delay(200);
        noTone(tonePin);
    }
}

void playerInput(int playerInputCount, int mode)
{
    do    
    {
        delay(33.3);

        blueButton = digitalRead(A2);
        yellowButton = digitalRead(A3);
        redButton = digitalRead(A4);
        greenButton = digitalRead(A5);
    }
    while (blueButton == HIGH && yellowButton == HIGH && redButton == HIGH && greenButton == HIGH);

    for (int i = 2; i < 6; i++)
    {
        switch (i)
        {
        case 2:
            if (digitalRead(A2) == LOW)
            {
                    if (mode == 1)
                    {
                        verifyInput(i, playerInputCount, BLUE_LED);
                    }
                    else
                    {
                        verifySequence(i, playerInputCount, BLUE_LED);
                    }
            } 
            break;
        
        case 3:
            if (digitalRead(A3) == LOW)
            {
                verifyInput(i, playerInputCount, YELLOW_LED);
            }  
            break;
        case 4:
            if (digitalRead(A4) == LOW)
            {
                verifyInput(i, playerInputCount, RED_LED);
            }
            break;
        case 5:
            if (digitalRead(A5) == LOW)
            {
                verifyInput(i, playerInputCount, GREEN_LED);
            }  
            break;

        default:
            break;
        }
    }
    
    do
    {
        delay(33.3);

        blueButton = digitalRead(A2);
        yellowButton = digitalRead(A3);
        redButton = digitalRead(A4);
        greenButton = digitalRead(A5);
    }
    while (blueButton != HIGH || yellowButton != HIGH || redButton != HIGH || greenButton != HIGH);

    noTone(tonePin);
}

void secondGameMode()
{
    startupMusic();
    delay(650);
    do
    {
        for (int playerInputCount = 0; playerInputCount < freeSpace; playerInputCount++)
        {
            Serial.println(playerInputCount + 1);
            playerInput(playerInputCount, 2);
        }
        delay(200);
    }
    while (freeSpace < 31);

    winningMusic();
}

void firstGameMode()
{
    startupMusic();
    delay(650);
    do
    {
        generateLed();
        showLed();
        for (int playerInputCount = 0; playerInputCount < freeSpace; playerInputCount++)
        {
            Serial.println(playerInputCount + 1);
            playerInput(playerInputCount, 1);
        }
        delay(200/speedMultiplyer);
        checkSpeedIncrease();
    }
    while (freeSpace < 3);

    winningMusic();
}

void loop()
{
    blueButton = digitalRead(A2);
    yellowButton = digitalRead(A3);

    if (blueButton == LOW)
    {
        resetGame();
        while (blueButton == LOW)
        {
            delay(33.3);
            blueButton = digitalRead(A2);
        }
        firstGameMode();
    }

    if (yellowButton == LOW)
    {
        resetGame();
        while (yellowButton == LOW)
        {
            delay(33.3);
            yellowButton = digitalRead(A2);
        }
        secondGameMode();
    }

    delay(33.3);
}