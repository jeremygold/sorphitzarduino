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
//#include <ADC.h>  // Teensy 3.1 uncomment this line and install https://github.com/pedvide/ADC
#include "mozzi_config.h"
#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/saw8192_int8.h>
#include <tables/cos8192_int8.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>

#define FREQ_OFFSET_PIN 0
#define DIVERGENCE_PIN 1
#define FREQ_PIN 2
#define WAVEFORM_PIN 3

// harmonics
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos1(SAW8192_DATA);
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos2(SAW8192_DATA);
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos3(SAW8192_DATA);
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos4(SAW8192_DATA);
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos5(SAW8192_DATA);
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos6(SAW8192_DATA);
Oscil<SAW8192_NUM_CELLS, AUDIO_RATE> aCos0(SAW8192_DATA);

// duplicates but slightly off frequency for adding to originals
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos1b(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos2b(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos3b(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos4b(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos5b(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos6b(COS8192_DATA);
Oscil<COS8192_NUM_CELLS, AUDIO_RATE> aCos0b(COS8192_DATA);

// base pitch frequencies
float f0, f1, f2, f3, f4, f5, f6;

// to map light input to frequency divergence of the b oscillators
const float DIVERGENCE_SCALE = 0.01; // 0.01*1023 = 10.23 Hz max divergence

// to map freqOffset to base freq drift
const float OFFSET_SCALE = 0.1; // 0.1*1023 = 102.3 Hz max drift
const float FREQ_SCALE = 1.0;   // 1.0 * 1023 = 1023.0 Hz freq adjustment
const float WAVE_SCALE = 1.0 / 1024.0;

float waveRatio = 0.5;

void setFrequencies(float baseFreq)
{
  // select base frequencies using mtof
  // C F♯ B♭ E A D the "Promethean chord"
  f0 = baseFreq; // a spare C !
  f1 = f0 * 1.33333333333;
  f2 = f0 * 1.5;
  f3 = f0 * 1.61111111111;
  f4 = f0 * 1.77777777778;
  f5 = f0 * 1.91666666667;
  f6 = f0 * 2.05555555556;

  // set Oscils with chosen frequencies
  aCos0.setFreq(f0);
  aCos1.setFreq(f1);
  aCos2.setFreq(f2);
  aCos3.setFreq(f3);
  aCos4.setFreq(f4);
  aCos5.setFreq(f5);
  aCos6.setFreq(f6);

  // set frequencies of duplicate oscillators
  aCos6b.setFreq(f6);
  aCos0b.setFreq(f0);
  aCos1b.setFreq(f1);
  aCos2b.setFreq(f2);
  aCos3b.setFreq(f3);
  aCos4b.setFreq(f4);
  aCos5b.setFreq(f5);
}

void setup()
{
  startMozzi();
  setFrequencies(440.0);
}

void loop()
{
  audioHook();
}

void updateControl()
{
  // read analog inputs
  int freqOffset = mozziAnalogRead(FREQ_OFFSET_PIN); // not calibrated to degrees!
  int divergenceSetting = mozziAnalogRead(DIVERGENCE_PIN);

  float base_freq_offset = OFFSET_SCALE * freqOffset;
  float divergence = DIVERGENCE_SCALE * divergenceSetting;

  int baseFreq = mozziAnalogRead(FREQ_PIN) * FREQ_SCALE;

  waveRatio = (float)mozziAnalogRead(WAVEFORM_PIN) * WAVE_SCALE;
  setFrequencies(440.0 + baseFreq);

  float freq;

  // change frequencies of the oscillators, randomly choosing one pair each time to change
  switch (rand(7))
  {

  case 0:
    freq = f0 + base_freq_offset;
    aCos0.setFreq(freq);
    aCos0b.setFreq(freq + divergence);
    break;

  case 1:
    freq = f1 + base_freq_offset;
    aCos1.setFreq(freq);
    aCos1b.setFreq(freq + divergence);
    break;

  case 2:
    freq = f2 + base_freq_offset;
    aCos2.setFreq(freq);
    aCos2b.setFreq(freq + divergence);
    break;

  case 3:
    freq = f3 + base_freq_offset;
    aCos3.setFreq(freq);
    aCos3b.setFreq(freq + divergence);
    break;

  case 4:
    freq = f4 + base_freq_offset;
    aCos4.setFreq(freq);
    aCos4b.setFreq(freq + divergence);
    break;

  case 5:
    freq = f5 + base_freq_offset;
    aCos5.setFreq(freq);
    aCos5b.setFreq(freq + divergence);
    break;

  case 6:
    freq = f6 + base_freq_offset;
    aCos6.setFreq(freq);
    aCos6b.setFreq(freq + divergence);
    break;
  }
}

int updateAudio()
{
  float waveRatioInv = 1.0 - waveRatio;

  int asig =
      waveRatio * aCos0.next() + waveRatioInv * aCos0b.next() +
      waveRatio * aCos1.next() + waveRatioInv * aCos1b.next() +
      waveRatio * aCos2.next() + waveRatioInv * aCos2b.next() +
      waveRatio * aCos3.next() + waveRatioInv * aCos3b.next() +
      waveRatio * aCos4.next() + waveRatioInv * aCos4b.next() +
      waveRatio * aCos5.next() + waveRatioInv * aCos5b.next() +
      waveRatio * aCos6.next() + waveRatioInv * aCos6b.next();

  return asig >> 5;
}
