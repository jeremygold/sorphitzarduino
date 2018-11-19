/* 
  Example using 2 light dependent resistors (LDRs) to change 
  FM synthesis parameters, and a knob for fundamental frequency,
  using Mozzi sonification library.

  Demonstrates analog input, audio and control oscillators, phase modulation
  and smoothing a control signal at audio rate to avoid clicks.
  Also demonstrates AutoMap, which maps unpredictable inputs to a set range.
  
  This example goes with a tutorial on the Mozzi site:
  http://sensorium.github.io/Mozzi/learn/introductory-tutorial/
  
  The circuit:
     Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.1, or 
     check the README or http://sensorium.github.com/Mozzi/

     Potentiometer connected to analog pin 0.
       Center pin of the potentiometer goes to the analog pin.
       Side pins of the potentiometer go to +5V and ground
  
     Light dependent resistor (LDR) and 5.1k resistor on analog pin 1:
       LDR from analog pin to +5V (3.3V on Teensy 3.1)
       5.1k resistor from analog pin to ground
     
     Light dependent resistor (LDR) and 5.1k resistor on analog pin 2:
       LDR from analog pin to +5V (3.3V on Teensy 3.1)
       5.1k resistor from analog pin to ground
  
  Mozzi help/discussion/announcements:
  https://groups.google.com/forum/#!forum/mozzi-users

  Tim Barrass 2013, CC by-nc-sa.
*/
#include <Arduino.h>
// #include <// USBMIDI.h>
#include <Bounce2.h>
#include <ResponsiveAnalogRead.h>
#include <MozziGuts.h>
#include <Oscil.h> // oscillator
#include <LowPassFilter.h>
#include <tables/cos2048_int8.h> // table for Oscils to play
#include <Smooth.h>
#include <AutoMap.h> // maps unpredictable inputs to a range

ResponsiveAnalogRead analogOne(A0, true, 1);
ResponsiveAnalogRead analogTwo(A1, true, .1);
ResponsiveAnalogRead analogThree(A2, true, .1);
ResponsiveAnalogRead analogFour(A3, true, .1);

int faderValue1 = 0;
int faderValue2 = 0;
int faderValue3 = 0;
int faderValue4 = 0;
// int cc1 = 124;
// int cc2 = 124;
// int cc3 = 124;
// int cc4 = 124;
// int lastAnalogValue1 = 0;
// int lastAnalogValue2 = 0;
// int lastAnalogValue3 = 0;
// int lastAnalogValue4 = 0;
// int lastfaderValue1 = faderValue1 = 760;
// int lastfaderValue2 = faderValue2 = 2600;
// int lastfaderValue3 = faderValue3 = 2000;
// int lastfaderValue4 = faderValue4; // = 0;
// desired carrier frequency max and min, for AutoMap
const int MIN_CARRIER_FREQ = 22;
const int MAX_CARRIER_FREQ = 460;

// desired intensity max and min, for AutoMap, note they're inverted for reverse dynamics
const int MIN_INTENSITY = 700;
const int MAX_INTENSITY = 10;

// desired mod speed max and min, for AutoMap, note they're inverted for reverse dynamics
const int MIN_MOD_SPEED = 10000;
const int MAX_MOD_SPEED = 1;

AutoMap kMapCarrierFreq(0, 1023, MIN_CARRIER_FREQ, MAX_CARRIER_FREQ);
AutoMap kMapIntensity(0, 1023, MIN_INTENSITY, MAX_INTENSITY);
AutoMap kMapModSpeed(0, 1023, MIN_MOD_SPEED, MAX_MOD_SPEED);

const int KNOB_PIN = A0; // set the input for the knob to analog pin 0
const int LDR1_PIN = A1; // set the analog input for fm_intensity to pin 1
const int LDR2_PIN = A2; // set the analog input for mod rate to pin 2

Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aCarrier(COS2048_DATA);
Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aModulator(COS2048_DATA);
Oscil<COS2048_NUM_CELLS, CONTROL_RATE> kIntensityMod(COS2048_DATA);
Oscil<COS2048_NUM_CELLS, CONTROL_RATE> kFilterMod(COS2048_DATA);
LowPassFilter lpf;

int mod_ratio = 5; // brightness (harmonics)
long fm_intensity; // carries control info from updateControl to updateAudio

// smoothing for intensity to remove clicks on transitions
float smoothness = 0.95f;
Smooth<long> aSmoothIntensity(smoothness);

void setup()
{
  //Serial.begin(9600); // for Teensy 3.1, beware printout can cause glitches
  Serial.begin(115200); // set up the Serial output so we can look at the piezo values // set up the Serial output so we can look at the light level
  // USBComposite.setProductId(0x0031);
  // USBMIDI.begin();
  kFilterMod.setFreq(1.3f);
  lpf.setResonance(200);
  startMozzi(); // :))
}

void updateControl()
{
  // // read the knob
  // faderValue1 = mozziAnalogRead(A0);
  // cc1 = faderValue1 / 32.3;
  // if (faderValue1 > 0 && faderValue1 < 145 && (lastfaderValue1 / 32 != faderValue1 / 32))
  // {
  //   // USBMIDI.sendControlChange(0, 14, 0);
  //   lastfaderValue1 = faderValue1;
  // }
  // else if (faderValue1 > 6015 && faderValue1 < 6097 && lastfaderValue1 / 32 != faderValue1 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 14, 127);
  //   lastfaderValue1 = faderValue1;
  // }
  // else if (lastfaderValue1 / 32 != faderValue1 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 14, faderValue1 / 32.3);
  //   lastfaderValue1 = faderValue1;
  // }
  // faderValue2 = mozziAnalogRead(A1);
  // cc1 = faderValue2 / 32.3;
  // if (faderValue2 > 0 && faderValue2 < 145 && (lastfaderValue2 / 32 != faderValue2 / 32))
  // {
  //   // USBMIDI.sendControlChange(0, 15, 0);
  //   lastfaderValue2 = faderValue2;
  // }
  // else if (faderValue2 > 6015 && faderValue2 < 6097 && lastfaderValue2 / 32 != faderValue2 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 15, 127);
  //   lastfaderValue2 = faderValue2;
  // }
  // else if (lastfaderValue2 / 32 != faderValue2 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 15, faderValue2 / 32.3);
  //   lastfaderValue2 = faderValue2;
  // }
  // faderValue3 = mozziAnalogRead(A2);
  // cc1 = faderValue3 / 32.3;
  // if (faderValue3 > 0 && faderValue3 < 145 && (lastfaderValue3 / 32 != faderValue3 / 32))
  // {
  //   // USBMIDI.sendControlChange(0, 16, 0);
  //   lastfaderValue3 = faderValue3;
  // }
  // else if (faderValue3 > 6015 && faderValue3 < 6097 && lastfaderValue3 / 32 != faderValue3 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 16, 127);
  //   lastfaderValue1 = faderValue3;
  // }
  // else if (lastfaderValue3 / 32 != faderValue3 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 16, faderValue3 / 32.3);
  //   lastfaderValue3 = faderValue3;
  // }
  // faderValue4 = mozziAnalogRead(A3);
  // cc1 = faderValue4 / 32.3;
  // if (faderValue4 > 0 && faderValue4 < 145 && (lastfaderValue4 / 32 != faderValue4 / 32))
  // {
  //   // USBMIDI.sendControlChange(0, 17, 0);
  //   lastfaderValue1 = faderValue4;
  // }
  // else if (faderValue4 > 6015 && faderValue4 < 6097 && lastfaderValue4 / 32 != faderValue4 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 17, 127);
  //   lastfaderValue4 = faderValue4;
  // }
  // else if (lastfaderValue4 / 32 != faderValue4 / 32)
  // {
  //   // USBMIDI.sendControlChange(0, 17, faderValue4 / 32.3);
  //   lastfaderValue4 = faderValue4;
  // }

  int knob_value = mozziAnalogRead(KNOB_PIN) / 4; // value is 0-1023
  // Serial.print("KNOB = ");
  // Serial.print(knob_value);
  // Serial.print("\t"); // prints a tab

  // map the knob to carrier frequency
  int carrier_freq = kMapCarrierFreq(knob_value);

  //calculate the modulation frequency to stay in ratio
  int mod_freq = carrier_freq * mod_ratio;

  // set the FM oscillator frequencies
  aCarrier.setFreq(carrier_freq);
  aModulator.setFreq(mod_freq);

  // read the light dependent resistor on the width Analog input pin
  int LDR1_value = mozziAnalogRead(LDR1_PIN) / 1; // value is 0-1023
  // print the value to the Serial monitor for debugging
  // Serial.print("LDR1 = ");
  // Serial.print(LDR1_value);
  // Serial.print("\t"); // prints a tab

  int LDR1_calibrated = kMapIntensity(LDR1_value);
  Serial.print("LDR1_calibrated = ");
  Serial.print(LDR1_calibrated);
  Serial.print("\t"); // prints a tab

  // calculate the fm_intensity
  fm_intensity = ((long)LDR1_calibrated * (kIntensityMod.next() + 128)) >> 8; // shift back to range after 8 bit multiply
  // Serial.print("fm_intensity = ");
  // Serial.print(fm_intensity);
  // Serial.print("\t"); // prints a tab

  // read the light dependent resistor on the speed Analog input pin
  int LDR2_value = mozziAnalogRead(LDR2_PIN) / 1; // value is 0-1023
  // Serial.print("LDR2 = ");
  // Serial.print(LDR2_value);
  // Serial.print("\t"); // prints a tab

  // use a float here for low frequencies
  float mod_speed = (float)kMapModSpeed(LDR2_value) / 1000;
  Serial.print("   mod_speed = ");
  Serial.print(mod_speed);

  int slider3 = mozziAnalogRead(A3) / 4;
  kIntensityMod.setFreq(mod_speed);
  lpf.setCutoffFreq(slider3);
  Serial.println(); // finally, print a carraige return for the next line of debugging info
}

int updateAudio()
{
  long modulation = lpf.next(aSmoothIntensity.next(fm_intensity) * aModulator.next());
  return aCarrier.phMod(modulation);
}

void loop()
{
  audioHook();
}
