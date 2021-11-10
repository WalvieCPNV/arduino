//Initialises the variables needed for the jingles
int tonePin = 6;
int previousLED;

//turns off the previous LED that was turned on and turns on a random LED
void ledJingle()
{
    //turns off the previousLED
    digitalWrite(previousLED, LOW);
    //chooses a random LED to turn on
    int randomLED = random(2, 6);
    //if the randomLED was the same as the previousLED, it will either subtract or add one to the number changing which LED will be turned on
    if (randomLED == previousLED)
    {
        if (randomLED == 5)
        {
            randomLED -= 1;
        }
        else
        {
            randomLED += 1;
        }
    }

    //assigns the random LED chosen to the previous LED variable
    previousLED = randomLED;
    //turns on the LED chosen at random
    digitalWrite(previousLED, HIGH);
}

//turns on all the LED's at once and turns them off after a delay
void allLedOn(int delayTime)
{
    //loops through all the LED's and turns them on
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, HIGH);
    }
    //waits the same ammount of time that the last note lasts for
    delay(delayTime);
    //loops through all the LED's and turns them off
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, LOW);
    }
}

// Midi files made by: Arthur Bottemanne
// Credit:
// Midi to Arduino Converter
//     - Andy Tran (extramaster), 2015
// https://www.extramaster.net/tools/midiToArduino/

//plays a jingle made for when a game is launched
//turns on a random LED with every note that is played
//music: crossing field by LiSa
void startupMusic() 
{
    tone(tonePin, 349, 167.598);
    ledJingle();
    delay(167.598);
    tone(tonePin, 391, 167.598);
    ledJingle();
    delay(167.598);
    tone(tonePin, 440, 335.195);
    ledJingle();
    delay(335.195);
    tone(tonePin, 523, 1005.59);
    ledJingle();
    delay(1005.59);
    tone(tonePin, 349, 335.195);
    ledJingle();
    delay(335.195);
    tone(tonePin, 329, 670.39);
    ledJingle();
    delay(670.39);
    tone(tonePin, 587, 502.79);
    ledJingle();
    delay(502.79);
    tone(tonePin, 523, 83.7);
    ledJingle();
    delay(83.7);
    tone(tonePin, 587, 83.7);
    ledJingle();
    delay(83.7);
    tone(tonePin, 523, 1005.59);
    ledJingle();
    delay(1005.59);
    tone(tonePin, 440, 167.598);
    ledJingle();
    delay(167.598);
    tone(tonePin, 466, 335.195);
    ledJingle();
    delay(335.195);
    tone(tonePin, 440, 335.195);
    ledJingle();
    delay(335.195);
    tone(tonePin, 391, 335.195);
    ledJingle();
    delay(335.195);
    tone(tonePin, 440, 502.79);
    ledJingle();
    delay(502.79);
    tone(tonePin, 698, 1005.59);
    allLedOn(1005.59);
}

//plays a jingle made for when a game is won
//turns on a random LED with every note that is played
//music: FREEDOM DiVE↓ by XI
void winningMusic() 
{
    tone(tonePin, 1174, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1174, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1174, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046,69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 739, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 739, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 739, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 880, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 659, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 880, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 659, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 880, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 659, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 739, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 659, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 739, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 659, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 493, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 659, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 880, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 987, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1174, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 587, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1318, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1318, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 783, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1318, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1046, 69);
    ledJingle();
    delay(69);
    tone(tonePin, 1479, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1479, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1567, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1567, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1760, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1760, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1567, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1567, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1479, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1479, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1318, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1318, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1046, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1318, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 987, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1318, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1174, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 987, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1174, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1108, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 987, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1108, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 987, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1318, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 987, 67.56);
    ledJingle();
    delay(67.56);
    tone(tonePin, 1318, 67.56);
    ledJingle();
    delay(147);
    tone(tonePin, 1174, 540.5);
    allLedOn(540.5);
}