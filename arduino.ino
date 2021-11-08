#include "music.h"

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

void verifyInput(int number, int playerInputCount)
{
    if (number == Sequence[playerInputCount])
    {
        Serial.println("Correct!");
    }
    else
    {
        Serial.println("Incorrect!");
    }
}

void playerInput(int playerInputCount)
{
    Serial.println("waiting for player input");

    while (blueButton == HIGH && yellowButton == HIGH && redButton == HIGH && greenButton == HIGH)
    {
        delay(33.3);

        blueButton = digitalRead(A2);
        yellowButton = digitalRead(A3);
        redButton = digitalRead(A4);
        greenButton = digitalRead(A5);
    }
    
    for (int i = 2; i < 6; i++)
    {
        switch (i)
        {
        case 2:
            if (digitalRead(A2) == LOW)
            {
                verifyInput(i, playerInputCount);
            }  
            break;
        
        case 3:
            if (digitalRead(A3) == LOW)
            {
                verifyInput(i, playerInputCount);
            }  
            break;
        case 4:
            if (digitalRead(A4) == LOW)
            {
                verifyInput(i, playerInputCount);
            }  
            break;
        case 5:
            if (digitalRead(A5) == LOW)
            {
                verifyInput(i, playerInputCount);
            }  
            break;

        default:
            break;
        }
    }
    
    while (blueButton != HIGH || yellowButton != HIGH || redButton != HIGH || greenButton != HIGH)
    {
        delay(33.3);

        blueButton = digitalRead(A2);
        yellowButton = digitalRead(A3);
        redButton = digitalRead(A4);
        greenButton = digitalRead(A5);
    }
}

void playGame()
{
    midi();
    do
    {
        generateLed();
        showLed();
        for (int playerInputCount = 0; playerInputCount < freeSpace; playerInputCount++)
        {
            Serial.println(playerInputCount);
            playerInput(playerInputCount);
        }
        delay(200);
        Serial.println("restarting game");
    }
    while (gameInSession = 1);    
}

void loop()
{
    int blueButton = digitalRead(A2);

    if (blueButton == LOW)
    {
        digitalWrite(3, HIGH);
        delay(200);
        digitalWrite(3, LOW);
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