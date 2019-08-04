# arduino-new-year-tree

Arduino-based desktop new year tree with LEDs and two piezo speakers.

Demo:
https://www.youtube.com/watch?v=j6FsPV-Azto

Arduino connections are pretty straightforward, so I didn't bothered with the visual scheme:
1) two piezo-speakers are connected to "BASS_PIN" and "MELODY_PIN"
2) two buttons are connected to "button1Pin" and "button2Pin"
3) shift register for single LEDS is connected to "clockPin", "latchPin", "dataPin". LEDs are connected to the shift register outputs.
4) LED-matrix is connected to "DIN", "CS" and "CLK".

All the pin settings can be changed in the sketch, if needed. LEDs phases can also be tuned using "led_phases" and "totalLedPhases".
Melodies and pictures can be changed also using corresponding byte arrays.
