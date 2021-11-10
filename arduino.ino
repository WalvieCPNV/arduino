/*
Author: Arthur Bottemanne
Description: Make an arduino program that plays simon says
Version: 10.11.21
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

int sequenceLength = 0;

int playerInputCount = 0;

int playerInputCountMode2 = 0;

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
    sequenceLength = 0;
    playerInputCount = 0;
    playerInputCountMode2 = 0;
    noTone(tonePin);
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, LOW);
    }
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
        speedMultiplyer += 0.2;
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

void verifyInput(int number, int buzzerFrequency)
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
        delay(300);
        resetGame();
        delay(300);
        startupMusic();
    }
}

void checkMode(int counterVariable, int mode, int frequency)
{
    if (mode == 1)
    {
        verifyInput(counterVariable, frequency);
    }
    else
    {
        verifySequence(counterVariable, frequency);
    }
}

void verifySequence(int number, int buzzerFrequency)
{
    if (playerInputCountMode2 == sequenceLength)
    {
        Sequence[sequenceLength] = number;
        sequenceLength += 1;
        tone(tonePin, buzzerFrequency);
        playerInputCountMode2 = -1;
    }
    else if (number == Sequence[playerInputCountMode2])
    {
        tone(tonePin, buzzerFrequency);
        Serial.println("Correct!");
    }
    else
    {
        tone(tonePin, INCORRECT);
        Serial.println("Incorrect!");
        resetGame();
        delay(1000);
        startupMusic();
    }
}

void playerInput(int mode)
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
                digitalWrite(2, HIGH);
                checkMode(i, mode, BLUE_LED);
            } 
            break;
        
        case 3:
            if (digitalRead(A3) == LOW)
            {
                digitalWrite(3, HIGH);
                checkMode(i, mode, YELLOW_LED);
            }  
            break;
        case 4:
            if (digitalRead(A4) == LOW)
            {
                digitalWrite(4, HIGH);
                checkMode(i, mode, RED_LED);
            }
            break;
        case 5:
            if (digitalRead(A5) == LOW)
            {
                digitalWrite(5, HIGH);
                checkMode(i, mode, GREEN_LED);
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
    
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, LOW);
    }
}

void secondGameMode()
{
    startupMusic();
    delay(650);

    do
    {
        Serial.print("inputCounter: ");
        Serial.println(playerInputCountMode2);
        Serial.print("sequenceLength: ");
        Serial.println(sequenceLength);
        playerInput(2);
        if (sequenceLength != 0)
        {
            playerInputCountMode2 += 1;
        }
        delay(200);
    }
    while (sequenceLength < 5);
    resetGame();
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
        for (playerInputCount = 0; playerInputCount < freeSpace; playerInputCount++)
        {
            Serial.println(playerInputCount + 1);
            playerInput(1);
        }
        delay(200/speedMultiplyer);
        checkSpeedIncrease();
    }
    while (freeSpace < 3);
    resetGame();
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