/*
Author: Arthur Bottemanne
Description: reproduces the simon says board game on an arduino
Date: 11.11.21
Version: v1.1
*/

#include "jingle.h"

//Defines the different frequencies played when a button is played
#define CORRECT 523.25
#define BLUE_LED 165
#define YELLOW_LED 131
#define RED_LED 110
#define GREEN_LED 82
#define INCORRECT 33

//Initialises the variables needed for the programs process

//used for storing the sequence of LED's in the current game
int Sequence[31] = {0};
//indicates at what index of the sequence array is free for the program to insert a value into
int freeSpace = 0;
//will increase everytime sequence is dividable by 3, makes the first game modes delay take less time
int speedMultiplyer = 1;
//counts the ammount of inputs for the current sequence
int playerInputCount = 0;
//checks if the second game mode is won
int winConditionMode2;

//initialises the buttons state
int blueButton = digitalRead(A2);
int yellowButton = digitalRead(A3);
int redButton = digitalRead(A4);
int greenButton = digitalRead(A5);

void setup()
{
    //Configures the pins behaviour
    for (int i = 2; i < 6; i++)
    {
        pinMode(i, OUTPUT);
    }
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
    pinMode(A4, INPUT_PULLUP);
    pinMode(A5, INPUT_PULLUP);

    //initialises a pseudo-random number generator
    randomSeed(analogRead(0));

    //initialises the baud rate for serial functions
    Serial.begin(9600);
}

//checks if the game is in the second game mode and plays a sound if the input was correct
void verifyCorrectNote(int gameMode)
{
    //will play the "CORRECT" sound for a short time after a short delay id the game mode is the second
    //checks also for freeSpace if it isn't 0 to know if its the start of the game or not
    if (gameMode == 2 && freeSpace != 0)
    {
        //if the game is at the state of adding an LED, it will simply not play the sound
        if (playerInputCount == -1)
        {
            return;
        }
        delay(300);
        Serial.println("Correct sound effect playing");
        tone(tonePin, CORRECT, 350);
        delay(350);
    }
    
}

//resets the pins state to 0
void resetPinOutputState()
{
    noTone(tonePin);
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, LOW);
    }
}

//resets the variables and pin output to their original state
void resetGame()
{
    //resets the variables
    Sequence[31] = {0};
    freeSpace = 0;
    speedMultiplyer = 1;
    playerInputCount = 0;
    playerInputCount = 0;
    winConditionMode2 = 0;
    //resets the pins
    resetPinOutputState();
}

//generates a random LED and adds it to the sequence
void generateLED()
{
    int randomLED = random(2, 6);
    Sequence[freeSpace] = randomLED;
    freeSpace++;
}

//checks if 3 LED's have been guessed correctly and increases the speed of the game if so
void checkSpeedIncrease()
{
    if (freeSpace % 3 == 0)
    {
        speedMultiplyer += 0.3;
    }
    
}

//shows the sequence of the LED's one by one
void showLED()
{
    //loops through the array Sequence
    for (int i = 0; i < freeSpace; i++)
    {
        //turns on and off the LED in the sequence
        //the delay between every LED turning on and off gets shorter everytime speedMultiplyer is increased
        digitalWrite(Sequence[i], HIGH);
        //will play the correct frequency for the current LED that is lit up
        switch (Sequence[i])
        {
            case 2:
                tone(tonePin, BLUE_LED, 300/speedMultiplyer);
                break;
            case 3:
                tone(tonePin, YELLOW_LED, 300/speedMultiplyer);
                break;
            case 4:
                tone(tonePin, RED_LED, 300/speedMultiplyer);
                break;
            case 5:
                tone(tonePin, GREEN_LED, 300/speedMultiplyer);
                break;
            default:
                break;
        }
        delay(300/speedMultiplyer);
        digitalWrite(Sequence[i], LOW);
        delay(200/speedMultiplyer);
    }
}

//makes a noise and will simply proceed with the game
void inputCorrect(int buzzerFrequency)
{
    tone(tonePin, buzzerFrequency);
    Serial.println("Correct!");
}

//will reset the game and start the same game mode from the beginning
void inputIncorrect()
{
    tone(tonePin, INCORRECT);
    Serial.println("Incorrect!");
    delay(300);
    resetGame();
    delay(300);
    startupMusic();
}

//verifies if the input made by the user is the correct button for the second game mode
void verifySequence(int LEDPinNumber, int buzzerFrequency)
{
    //check if there isn't anything left in the sequence
    if (playerInputCount == freeSpace)
    {
        //will add the button pressed to the sequence
        Sequence[freeSpace] = LEDPinNumber;
        freeSpace++;
        tone(tonePin, buzzerFrequency);
        //assigns -1 to the variable due to the fact that it will immediatley add one to it
        playerInputCount = -1;
    }
    //check if the pressed button is the same as the LED in the current sequence
    else if (LEDPinNumber == Sequence[playerInputCount])
    {
        inputCorrect(buzzerFrequency);
        //checks if the player has inputted the full sequence when the game is finished
        if (freeSpace == 31 && playerInputCount == freeSpace - 1)
        {
            winConditionMode2 = 1;
        }
    }
    else
    {
        inputIncorrect();
    }
}

//verifies if the input made by the user is the correct button for the first game mode
void verifyInput(int LEDPinNumber, int buzzerFrequency)
{
    //checks if the pressed button is the same as the LED in the current sequence
    if (LEDPinNumber == Sequence[playerInputCount])
    {
        inputCorrect(buzzerFrequency);
    }
    else
    {
        inputIncorrect();
    }
}

//checks which mode is in session and changes the verification method depending on the game mode
void checkMode(int LEDPinNumber, int mode, int frequency)
{
    //will change the verification method depending on which game mode it is
    if (mode == 1)
    {
        verifyInput(LEDPinNumber, frequency);
    }
    else
    {
        verifySequence(LEDPinNumber, frequency);
    }
}

//fetches the user button input
void playerInput(int gameMode)
{
    //waits for a button input to be registered
    do    
    {
        delay(50);
        //reads continuously the input of all of the buttons
        blueButton = digitalRead(A2);
        yellowButton = digitalRead(A3);
        redButton = digitalRead(A4);
        greenButton = digitalRead(A5);
    }
    while (blueButton == HIGH && yellowButton == HIGH && redButton == HIGH && greenButton == HIGH);

    //checks which button has been pressed
    for (int i = 2; i < 6; i++)
    {
        switch (i)
        {
        //blue button
        case 2:
            if (digitalRead(A2) == LOW)
            {
                digitalWrite(2, HIGH);
                //will change the verification method depending on which game mode it is
                //passes through which LED has been pressed and what frequency the program is supposed to play
                checkMode(i, gameMode, BLUE_LED);
            } 
            break;
        //yellow button
        case 3:
            if (digitalRead(A3) == LOW)
            {
                //will change the verification method depending on which game mode it is
                //passes through which LED has been pressed and what frequency the program is supposed to play
                digitalWrite(3, HIGH);
                checkMode(i, gameMode, YELLOW_LED);
            }  
            break;
        //red button
        case 4:
            if (digitalRead(A4) == LOW)
            {
                //will change the verification method depending on which game mode it is
                //passes through which LED has been pressed and what frequency the program is supposed to play
                digitalWrite(4, HIGH);
                checkMode(i, gameMode, RED_LED);
            }
            break;
        //green button
        case 5:
            if (digitalRead(A5) == LOW)
            {
                //will change the verification method depending on which game mode it is
                //passes through which LED has been pressed and what frequency the program is supposed to play
                digitalWrite(5, HIGH);
                checkMode(i, gameMode, GREEN_LED);
            }  
            break;

        default:
            break;
        }
    }
    //waits for every button to be released before continuing with the game
    do
    {
        delay(50);
        //reads continuously the input of all of the buttons
        blueButton = digitalRead(A2);
        yellowButton = digitalRead(A3);
        redButton = digitalRead(A4);
        greenButton = digitalRead(A5);
    }
    while (blueButton != HIGH || yellowButton != HIGH || redButton != HIGH || greenButton != HIGH);

    //resets the pins
    resetPinOutputState();
    //will play a sound if the player got an input right and if the game is in game mode 2
    verifyCorrectNote(gameMode);
}

//plays the second game mode
void secondGameMode()
{
    //plays the starting jingle of the game
    startupMusic();
    delay(650);

    do
    {
        playerInput(2);
        if (freeSpace != 0)
        {
            playerInputCount += 1;
        }
        delay(200);
    }
    while (winConditionMode2 == 0);
    //the program goes back to the original loop once the win condition is achieved
    resetGame();
    //plays the winning jingle of the game
    winningMusic();
}

//plays the first game mode
void firstGameMode()
{
    //plays the starting jingle of the game
    startupMusic();
    delay(650);
    do
    {
        generateLED();
        showLED();
        //for every entry in the sequence table, the player must make the same ammount of inputs to generate another LED
        for (playerInputCount = 0; playerInputCount < freeSpace; playerInputCount++)
        {
            //passes through which mode is being played
            playerInput(1);
        }
        //divides the wait time by the speed multiplier to make the game faster
        delay(200/speedMultiplyer);
        checkSpeedIncrease();
    }
    while (freeSpace < 31);
    //the program goes back to the original loop once the win condition is achieved
    resetGame();
    //plays the winning jingle of the game
    winningMusic();
}

//awaits the player input to play either game mode
void loop()
{
    blueButton = digitalRead(A2);
    yellowButton = digitalRead(A3);

    //launches the first game mode if the blue button is pressed
    if (blueButton == LOW)
    {
        resetGame();
        //waits for the button to be released for the game to launch
        while (blueButton == LOW)
        {
            blueButton = digitalRead(A2);
        }
        firstGameMode();
    }

    //launches the second game mode if the yellow button is pressed
    if (yellowButton == LOW)
    {
        resetGame();
        //waits for the button to be released for the game to launch
        while (yellowButton == LOW)
        {
            yellowButton = digitalRead(A2);
        }
        secondGameMode();
    }
}