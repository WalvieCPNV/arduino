int tonePin = 6;
int ledOn;

void ledJingle()
{
    digitalWrite(ledOn, LOW);
    int randomLed = random(2, 6);

    if (randomLed == ledOn)
    {
        if (randomLed == 5)
        {
            randomLed -= 1;
        }
        else
        {
            randomLed += 1;
        }
    }

    ledOn = randomLed;
    digitalWrite(ledOn, HIGH);
}

void allLedOn(int delayTime)
{
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, HIGH);
    }
    delay(delayTime);
    for (int i = 2; i < 6; i++)
    {
        digitalWrite(i, LOW);
    }
}

void startupMusic() {
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

void silhouette()
{
    tone(tonePin, 246, 164.835);
    delay(164.835);
    tone(tonePin, 220, 164.835);
    delay(164.835);
    tone(tonePin, 246, 164.835);
    delay(164.835);
    tone(tonePin, 293, 329.67);
    delay(329.67);
    tone(tonePin, 220, 164.835);
    delay(164.835);
    tone(tonePin, 246, 164.835);
    delay(164.835);
    tone(tonePin, 220, 164.835);
    delay(164.835);
    tone(tonePin, 246, 164.835);
    delay(164.835);
    tone(tonePin, 293, 164.835);
    delay(164.835);
    tone(tonePin, 246, 164.835);
    delay(164.835);
    tone(tonePin, 220, 164.835);
    delay(164.835);
    tone(tonePin, 246, 329.67);
    delay(329.67);
}

void Temp() {
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 440, 797.447727273);
    delay(797.447727273);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 523, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 493, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 440, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 440, 797.447727273);
    delay(797.447727273);
    tone(tonePin, 349, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 261, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 349, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 466, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 440, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 79.7447727273);
    delay(79.7447727273);
    tone(tonePin, 329, 79.7447727273);
    delay(79.7447727273);
    tone(tonePin, 349, 79.7447727273);
    delay(79.7447727273);
    tone(tonePin, 369, 79.7447727273);
    delay(79.7447727273);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 440, 797.447727273);
    delay(797.447727273);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 523, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 493, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 440, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 440, 637.958181818);
    delay(637.958181818);
    tone(tonePin, 349, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 261, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 349, 159.489545455);
    delay(159.489545455);
    tone(tonePin, 466, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 440, 318.979090909);
    delay(318.979090909);
    tone(tonePin, 349, 318.979090909);
    delay(318.979090909);
}

void winningMusic() {
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