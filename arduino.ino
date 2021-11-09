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

int gameInSession = 0;

int Sequence[31] = {0};

int freeSpace = 0;

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

void initialiseVariables()
{
    gameInSession = 0;

    Sequence[31] = {0};

    freeSpace = 0;
}

void generateLed()
{
    int randomLed = random(2, 6);
    Sequence[freeSpace] = randomLed;
    freeSpace++;
}

void showLed()
{
    for (int i = 0; i < freeSpace; i++)
    {
        digitalWrite(Sequence[i], HIGH);
        delay(300);
        digitalWrite(Sequence[i], LOW);
        delay(200);
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
        Serial.println("Incorrect!");
        gameInSession = 0;
    }
}

void playerInput(int playerInputCount)
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
                verifyInput(i, playerInputCount, BLUE_LED);
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

void playGame()
{
    winningMusic();
    delay(650);
    do
    {
        generateLed();
        showLed();
        for (int playerInputCount = 0; playerInputCount < freeSpace; playerInputCount++)
        {
            Serial.println(playerInputCount + 1);
            playerInput(playerInputCount);
        }
        delay(200);
    }
    while (gameInSession = 1 && freeSpace < 3);

    winningMusic();
}

void loop()
{
    int blueButton = digitalRead(A2);

    if (blueButton == LOW)
    {
        initialiseVariables();
        gameInSession = 1;
        while (blueButton == LOW)
        {
            delay(33.3);
            blueButton = digitalRead(A2);
        }
        playGame();
    }

    delay(33.3);
}