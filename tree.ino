#include <Tone.h>
#include <LedControl.h>

#define NOT_AN_INTERRUPT -1

Tone tones[2];

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// LEDs
int DIN = 6;
int CS =  11;
int CLK = 7;

#define BASS_PIN 5
#define MELODY_PIN 4
const int button1Pin = 2;     
const int button2Pin = 3;     
const int ledPin =  13;      
int clockPin = 8;
int latchPin = 9;
int dataPin = 10;

// LEDs
int led_phases[] = {
  0b10010000,
  0b01001000,
  0b00100100
  //0b00100010    
};
int totalLedPhases = 3;




// Picture
struct Picture {
  const byte *frames;
  int framesCount;  
};  

//Blank
const byte blankFrames[1][8] PROGMEM = {
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}
};

const Picture Blank = {
  &blankFrames[0][0],
  1  
};

//Smile
const byte smileFrames[1][8] PROGMEM = {
  {0x3c, 0x42, 0xa5, 0x81, 0xa5, 0x99, 0x42, 0x3c}
};

const Picture Smile = {
  &smileFrames[0][0],
  1  
};


// Dancing man


const byte dancingFrames[8][8] PROGMEM = {
  {0x18, 0x18, 0x3c, 0x5a, 0x99, 0x3c, 0x24, 0x66},  
  {0x98, 0x58, 0x3c, 0x1a, 0x19, 0x3c, 0x24, 0x66},
  {0x98, 0x58, 0x3c, 0x1a, 0x99, 0xfc, 0x4, 0x6},
  {0x18, 0x18, 0xfc, 0x1a, 0x19, 0x3c, 0x24, 0x66},
  {0x18, 0x18, 0x3c, 0x5a, 0x99, 0x3c, 0x24, 0x66},    
  {0x18, 0x18, 0x3f, 0x58, 0x98, 0x3c, 0x24, 0x66},
  {0x19, 0x1a, 0x3c, 0x58, 0x99, 0x3f, 0x20, 0x60},
  {0x18, 0x18, 0x3f, 0x58, 0x98, 0x3c, 0x24, 0x66}  
};  

/*
const byte dancingFrames[2][8] PROGMEM = {
  {0x0, 0xa, 0x1c, 0x28, 0x8, 0x34, 0x2, 0x0},
  {0x0, 0x28, 0x1c, 0xa, 0x8, 0x16, 0x20, 0x0}
};
*/

const Picture Dancing = {
  &dancingFrames[0][0],
  8  
};


// Tree
const byte treeFrames[1][8] PROGMEM = {
  {0x8, 0x1c, 0x3e, 0x1c, 0x3e, 0x7f, 0x8, 0x8}
};

const Picture Tree = {
  &treeFrames[0][0],
  1  
};

// Heart
const byte heartFrames[1][8] PROGMEM = {
  {0x0, 0x66, 0xff, 0xff, 0x7e, 0x3c, 0x18, 0x0}
};

const Picture Heart = {
  &heartFrames[0][0],
  1  
};

// Cat
const byte catFrames[1][8] PROGMEM = {
  {0x81, 0xc3, 0xbd, 0x81, 0xa5, 0x81, 0x42, 0x3c}
};

const Picture Cat = {
  &catFrames[0][0],
  1  
};

// Pacman
const byte pacmanFrames[2][8] PROGMEM = {
  {0x3c, 0x7e, 0xfc, 0xf8, 0xf8, 0xfc, 0x7e, 0x3c},
  {0x38, 0x7c, 0xfe, 0xfe, 0xfe, 0xfe, 0x7c, 0x38}
};


const Picture Pacman = {
  &pacmanFrames[0][0],
  2  
};

// Space invader
const byte invaderFrames[2][8] PROGMEM = {
  {0x24, 0x24, 0x7e, 0xdb, 0xff, 0xff, 0xa5, 0x24},
  {0x24, 0xa5, 0xff, 0xdb, 0xff, 0x7e, 0x24, 0x42}
};

const Picture Invader = {
  &invaderFrames[0][0],
  2  
};

// 2018
const byte newyearFrames[2][8] PROGMEM = {
  {0x0, 0xee, 0x2a, 0xea, 0x8a, 0x8a, 0xee, 0x0},
  {0x0, 0x2e, 0x6a, 0x2e, 0x2a, 0x2a, 0x2e, 0x0}
};

const Picture NewYear = {
  &newyearFrames[0][0],
  2  
};

// You win
const byte winFrames[4][8] PROGMEM = {
  {0x0, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0},
  {0x0, 0x0, 0x3c, 0x24, 0x24, 0x3c, 0x0, 0x0},
  {0x0, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x0},
  {0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff}
};

const Picture Win = {
  &winFrames[0][0],
  4  
};

// Spaceship
const byte spaceshipFrames[17][8] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x3c},
  {0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x3c, 0x24},
  {0x00, 0x00, 0x00, 0x18, 0x24, 0x3c, 0x24, 0x24},
  {0x00, 0x00, 0x18, 0x24, 0x3c, 0x24, 0x24, 0x66},
  {0x00, 0x18, 0x24, 0x3c, 0x24, 0x24, 0x66, 0x81},
  {0x18, 0x24, 0x3c, 0x24, 0x24, 0x66, 0x81, 0xff},
  {0x24, 0x3c, 0x24, 0x24, 0x66, 0x81, 0xff, 0x00},
  {0x3c, 0x24, 0x24, 0x66, 0x81, 0xff, 0x00, 0x00},
  {0x24, 0x24, 0x66, 0x81, 0xff, 0x00, 0x00, 0x00},
  {0x24, 0x66, 0x81, 0xff, 0x00, 0x00, 0x00, 0x00},
  {0x66, 0x81, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x81, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

const Picture Spaceship = {
  &spaceshipFrames[0][0],
  17  
};


// All pictures
int picturesCount = 8;
Picture Pictures[] = {
  Blank,
  Smile,
  Pacman,
  Tree,
  Dancing,
  Cat,
  Invader,
  Heart,
  // last are the secret pictures, which selected in code (indexes more than "picturesCount")
  NewYear,
  Win,
  Spaceship
};



// Song structure
struct Song {
    const int *melody;
    int melodyArrSize;
    const int *melodyNoteDurations;
    const int *bass;
    int bassArrSize;
    const int *bassNoteDurations;
    int tempo;
    boolean hasBass;    
};

// Steklovata

const int steklovata_melody[] PROGMEM = {
  NOTE_A3, NOTE_AS3,
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_E4, 
  NOTE_F4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_AS3, NOTE_A3, 0, NOTE_D4, NOTE_D4, NOTE_C4,
  NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, 0, 0, 0, NOTE_A3, NOTE_AS3,
  
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_E4, 
  NOTE_F4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_AS3, NOTE_A3, 0, NOTE_D4, NOTE_D4, NOTE_C4,
  NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4,NOTE_D4, NOTE_E4, 0, 0, 0, 0,
  
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_F4, 0,
  0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_F4, 0,
  0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_F4, 0,
  0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,  
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_F4, 0,
  0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,
  0,0, NOTE_F4, NOTE_E4, NOTE_F4, 0, NOTE_F4, NOTE_E4, NOTE_F4, 0, NOTE_F4, NOTE_E4, NOTE_F4, 0, 0
  
 
};

const int steklovata_bass[] PROGMEM = {
  0,
  NOTE_F3, 0, NOTE_F3, NOTE_C3, 0, NOTE_C3, NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_D3, 0, NOTE_D3, NOTE_A2, 0, NOTE_A2, NOTE_D3, 0,  NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2,
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_G2, 0, NOTE_G2, NOTE_D3, NOTE_G2, NOTE_D3,
  NOTE_C3, 0, NOTE_C3, NOTE_G3, 0, NOTE_G3, NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3,
  
  NOTE_F3, 0, NOTE_F3, NOTE_C3, 0, NOTE_C3, NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_D3, 0, NOTE_D3, NOTE_A2, 0, NOTE_A2, NOTE_D3, 0,  NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2,
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_G2, 0, NOTE_G2, NOTE_D3, NOTE_G2, NOTE_D3,
  NOTE_C3, 0, NOTE_C3, NOTE_G3, 0, NOTE_G3, NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3,
  
  NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3, NOTE_D3, 0, NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2, 
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3,  
  NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3, NOTE_D3, 0, NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2, 
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3,  
  NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3, NOTE_D3, 0, NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2, 
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3,  
  NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3, NOTE_D3, 0, NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2, 
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3,
  
  NOTE_F3, 0, NOTE_F3, NOTE_C3, NOTE_F3, NOTE_C3, NOTE_D3, 0, NOTE_D3, NOTE_A2, NOTE_D3, NOTE_A2, 
  NOTE_G2, 0, NOTE_G2, NOTE_D3, 0, NOTE_D3, NOTE_C3, 0, 0
};


const int steklovataMelodyNoteDurations[] PROGMEM = {
  
  4,4,
  2,4,4,4,4,4,2,2, 2,4,2,
  2,4,4,4,4,4,2,2, 2,2,4,
  2,2,1,1, 4,2,4,2,2,2,1,1, 4,4,
  
  2,4,4,4,4,4,2,2, 2,4,2,  
  2,4,4,4,4,4,2,2, 2,2,4,
  2,2,1,1, 4,2,4,2,2,2,1,1, 2,
  
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 1, 1, 2, 2, 2, 2, 2, 2,  
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 1, 1, 2, 2, 2, 2, 2, 2,  
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 1, 1, 2, 2, 2, 2, 2, 2,  
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 1, 1, 2, 2, 2, 2, 2, 2,
  1, 4, 4, 4, 2, 1, 4, 4, 2, 1, 4, 4, 2, 1, 4
  
};


const int steklovataBassNoteDurations[] PROGMEM = {
 
  2,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 4, 4, 2, 2, 2, 2,
  
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 4, 4, 2, 2, 2, 2,
  
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 
  2, 4, 4, 2, 4, 4, 2, 2, 2, 2,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 
  2, 4, 4, 2, 4, 4, 2, 2, 2, 2,
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 
  2, 4, 4, 2, 4, 4, 2, 2, 2, 2,  
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 
  2, 4, 4, 2, 4, 4, 2, 2, 2, 2,
  
  2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 
  2, 4, 4, 2, 4, 4, 2, 2, 2
};

const Song Steklovata = {
  &steklovata_melody[0],
  164,
  &steklovataMelodyNoteDurations[0],  
  &steklovata_bass[0],
  202, 
  &steklovataBassNoteDurations[0],  
  912,
  true  
};  

// end of Steklovata


// Last Christmas
const int gay_melody[] PROGMEM = {
  NOTE_E4, 0, NOTE_E4, NOTE_D4, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_D4, 0, NOTE_A3, NOTE_A3,
  NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_D4, 0, NOTE_B3, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, 0, 0,  
  NOTE_FS4, 0, NOTE_E4, 0, NOTE_B3, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, 0, NOTE_D4,
  NOTE_CS4, NOTE_D4, NOTE_D4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_A3, 0, 0  
};

const int gay_bass[] PROGMEM = {
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, 
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_CS3, NOTE_D3, NOTE_CS3, NOTE_D3,  
  NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, 
  NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_CS3, NOTE_D3,
  NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_FS3, NOTE_G3, NOTE_FS3, NOTE_G3,  
  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2,
  NOTE_A2, NOTE_B2, NOTE_CS3, NOTE_E3, 0
};

const int gay_melodyNoteDurations[] PROGMEM = {
  2, 4, 2, 2, 4, 4, 4, 4, 2, 4, 4, 4,
  4, 4, 2, 2, 4, 4, 4, 4, 4, 2, 2, 4,
  2, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4,
  4, 4, 4, 2, 2, 2, 2, 4, 1   
};

const int gay_BassNoteDurations[] PROGMEM = {
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  2, 4, 4, 2, 4, 4,
  2, 2, 2, 2
};

const Song Gay = {
  &gay_melody[0],
  44,
  &gay_melodyNoteDurations[0],  
  &gay_bass[0],
  58,
  &gay_BassNoteDurations[0],  
  1008,
  true
};  

// End of last christmas

// El Bimbo
const int bimbo_melody[] PROGMEM = {
  NOTE_FS4, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_FS4, NOTE_D4, 0, 0, 0,
  NOTE_FS4, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_FS4, NOTE_A4, 0, NOTE_G4, NOTE_G4, 0, 0,  
  NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, 0, NOTE_CS5, NOTE_CS5, 0, NOTE_B4, NOTE_B4, 0, NOTE_A4, NOTE_A4, 0, NOTE_G4, NOTE_G4, 0, NOTE_FS4, NOTE_FS4, 0, 0
};

const int bimbo_bass[] PROGMEM = {
  0, 0, 0, 0, 0,
  NOTE_B2, 0,  NOTE_FS3, 0, NOTE_B2, 0, NOTE_FS3, 0, NOTE_B2, 0, NOTE_FS3, 0, NOTE_B2, 0, NOTE_FS3, 0,
  NOTE_E3, 0,  NOTE_B2, 0, NOTE_E3, 0, NOTE_B2, 0, NOTE_E3, 0, NOTE_B2, 0, NOTE_E3, 0, NOTE_B2, 0,  
  NOTE_A2, 0,  NOTE_E3, 0, NOTE_A2, 0, NOTE_E3, 0, NOTE_A2, 0, NOTE_E3, 0, NOTE_A2, 0, NOTE_E3, 0,
  NOTE_D3, 0, NOTE_A2, 0, NOTE_D3, 0, NOTE_A3, NOTE_G3, NOTE_FS3, 0, 0  
};

const int bimbo_melodyNoteDurations[] PROGMEM = {
  4, 4, 4, 4, 4, 2, 1, 1, 4,
  4, 4, 4, 4, 4, 2, 4, 4, 2, 1, 4,
  4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 1
};


const int bimbo_BassNoteDurations[] PROGMEM = {
  4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 2, 4
};

const Song Bimbo = {
  &bimbo_melody[0],
  43,
  &bimbo_melodyNoteDurations[0],  
  &bimbo_bass[0],
  63,
  &bimbo_BassNoteDurations[0],  
  1008,
  true  
};  
// end of el bimbo


// Start of RickRoll
const int rick_melody[] PROGMEM = {
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3,  
  
  NOTE_F4, NOTE_F4, NOTE_DS4, 0, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_GS3,
  NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3,
  NOTE_CS4, NOTE_DS4, NOTE_C4, 0, NOTE_GS3, 
  NOTE_DS4, NOTE_CS4, 0, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3,
  
  NOTE_F4, NOTE_F4, NOTE_DS4, 0, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_GS3,
  NOTE_GS4, NOTE_C4, NOTE_CS4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3,
  NOTE_CS4, NOTE_DS4, NOTE_C4, 0, NOTE_GS3, 
  NOTE_DS4, NOTE_CS4, 0
};

const int rick_bass[] PROGMEM = {
  NOTE_C3, NOTE_C3,   
  
  NOTE_DS2, NOTE_DS2, NOTE_GS2, NOTE_GS2, NOTE_DS3, NOTE_GS2,
  NOTE_F2, NOTE_C3, NOTE_AS2, NOTE_AS2, NOTE_C3, NOTE_AS2,
  NOTE_DS2, NOTE_DS2, NOTE_GS2, NOTE_GS2, NOTE_DS3, NOTE_GS2,
  NOTE_F2, NOTE_C3, NOTE_AS2, NOTE_AS2, NOTE_C3, NOTE_AS2,
  
  NOTE_DS2, NOTE_DS2, NOTE_GS2, NOTE_GS2, NOTE_DS3, NOTE_GS2,
  NOTE_F2, NOTE_C3, NOTE_AS2, NOTE_AS2, NOTE_C3, NOTE_AS2,
  NOTE_DS2, NOTE_DS2, NOTE_GS2, NOTE_GS2, NOTE_DS3, NOTE_GS2,
  NOTE_F2, NOTE_C3, NOTE_AS2, NOTE_AS2
};

const int rick_melodyNoteDurations[] PROGMEM = {
  8,8,8,8,
  
  40,40,2,4,8,8,8,8,
  40,40,40,8,4,8,8,8,8,
  40,40,2,2,4,
  2,2,2,8,8,8,8,
  
  40,40,2,4,8,8,8,8,
  2,4,40,8,4,8,8,8,8,
  40,40,2,2,4,
  2,2,2,
};




const int rick_BassNoteDurations[] PROGMEM = {
  4,4,
  
  40,40,2,4,4,4,
  40,40,2,4,4,4,  
  40,40,2,4,4,4,
  40,40,2,4,4,4,
  
  40,40,2,4,4,4,
  40,40,2,4,4,4,  
  40,40,2,4,4,4,
  40,40,2,4  
};

const Song Rick = {
  &rick_melody[0],
  58,
  &rick_melodyNoteDurations[0],  
  &rick_bass[0],
  24,
  &rick_BassNoteDurations[0],  
  984,
  true  
};  

//End of RickRoll


// Imperial march
const int imperial_melody[] PROGMEM = {
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_G4, 
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_AS4, NOTE_FS4, NOTE_DS4, NOTE_AS4, NOTE_G4, 
 
  NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_E5, 0, 
  NOTE_G4, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_AS4, NOTE_A4, NOTE_AS4, 0, 
  NOTE_DS4, NOTE_FS4, NOTE_DS4, NOTE_FS4, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_DS5, 0,
  
  NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_E5, 0, 
  NOTE_G4, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_AS4, NOTE_A4, NOTE_AS4, 0, 
  NOTE_DS4, NOTE_FS4, NOTE_DS4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_G4, 0  
};

const int imperial_MelodyNoteDurations[] PROGMEM = {  
  2, 2, 2, 40, 8, 2, 40 , 8 ,1 , 
  2, 2, 2, 40, 8, 2, 40, 8, 1, 
  
  2, 40, 8, 2, 40, 8, 8, 8, 8, 40,
  4, 2, 40, 8,8,8,8, 40,
  4, 2 ,40, 8, 2,40,8,2, 2, 
  
  2, 40, 8, 2, 40, 8, 8, 8, 8, 40,
  4, 2, 40, 8,8,8,8, 40,
  4, 2 ,40, 8, 2,40,8,2, 2
};

const int imperial_bass[] PROGMEM = {
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3, 
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_AS3, NOTE_FS3, NOTE_DS3, NOTE_AS3, NOTE_G3, 
 
  NOTE_G4, NOTE_G3, NOTE_G3, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_E4, NOTE_DS4, NOTE_E4, 0, 
  NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_AS3, 0, 
  NOTE_DS3, NOTE_FS3, NOTE_DS3, NOTE_FS3, NOTE_AS3, NOTE_G3, NOTE_AS3, NOTE_DS4, 0,
  
  NOTE_G4, NOTE_G3, NOTE_G3, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_E4, NOTE_DS4, NOTE_E4, 0, 
  NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_AS3, 0, 
  NOTE_DS3, NOTE_FS3, NOTE_DS3, NOTE_AS3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3, 0  
};

const int imperial_BassNoteDurations[] PROGMEM = {
  2, 2, 2, 40, 8, 2, 40 , 8 ,1 , 
  2, 2, 2, 40, 8, 2, 40, 8, 1, 
  
  2, 40, 8, 2, 40, 8, 8, 8, 8, 40,
  4, 2, 40, 8,8,8,8, 40,
  4, 2 ,40, 8, 2,40,8,2, 2, 
  
  2, 40, 8, 2, 40, 8, 8, 8, 8, 40,
  4, 2, 40, 8,8,8,8, 40,
  4, 2 ,40, 8, 2,40,8,2, 2
};

const Song Imperial = {
  &imperial_melody[0],
  72,
  &imperial_MelodyNoteDurations[0],  
  &imperial_bass[0],
  72,
  &imperial_BassNoteDurations[0],  
  984,
  true  
};  



// End of imperial march



// Empty song
Song Mute = {
  NULL,
  NULL,
  NULL,  
  NULL,
  NULL,
  NULL,  
  900,
  NULL
};


//All songs
int songsCount = 4;
Song Songs[] = {
  Mute,
  Gay,    
  Steklovata,  
  Bimbo,
  Rick,  
  Imperial  
};

// Selected picture for each song
byte selectedPicture[] = 
{
  0,
  0,
  0,
  0
};

// Correct pictures
byte correctPictures[] = 
{
  0,
  7,
  3,
  4
};



// Current song
byte currentSong = 0;
int currentMelodyNote = 0;
int currentBassNote = 0;

// Current picture
byte currentPicture = 0;
byte currentFrame = 0;


// LED
byte leds = 0;
int currentLedPhase = 0;

// Bonus level
boolean isBonusLevel = false;
byte bonusLevelButtonsPressed = 0;
byte bonusLevelTotalButtonsPresses = 11;
int bonusLevelAnswer = 1;
boolean youWin = false;

//It's easter time!
byte easterButtonsPressed = 0;
byte easterTotalButtonsPresses = 10;
int easterAnswer = 1;
boolean easter = false;
unsigned long easterStart = 0;

// Matrix
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup() {
  Serial.begin(9600);
  
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,10);      // Set the brightness to 10  (15 - maximum value)
  lc.clearDisplay(0);         // and clear the display  

  tones[0].begin(BASS_PIN);    
  tones[1].begin(MELODY_PIN);
  
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);  
  attachInterrupt(digitalPinToInterrupt(button1Pin), pin_ISR_Button1, RISING);  
  attachInterrupt(digitalPinToInterrupt(button2Pin), pin_ISR_Button2, RISING);    
  
  // Initialize song  
  
  //currentSong = 4;
  currentSong = 0;  
  currentMelodyNote = 0;
  currentBassNote = 0;  
  
  // shift register
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);  
  
  // initialize leds
  leds = 0;
  updateShiftRegister();  
  
  
  //isBonusLevel = true;
  //youWin = true;
}


// Synchronization
unsigned long previousMelodyMillis = 0;
unsigned long previousBassMillis = 0;
unsigned long pauseUntilNextMelodyNote = 0;
unsigned long pauseUntilNextBassNote = 0;
volatile boolean switchingSong = false;
volatile boolean switchingPicture = false;
unsigned long lastInterrupt1;
unsigned long lastInterrupt2;
unsigned long pauseUntilNextFrame = 0;
unsigned long previousPictureMillis = 0;


void pin_ISR_Button1() {  
  if(millis() - lastInterrupt1 > 300) 
    {    
      if (!isBonusLevel && !youWin)      
        switchingSong = true;
      else if (!youWin && bonusLevelButtonsPressed < bonusLevelTotalButtonsPresses)
      {
        //make sound
        tones[0].play(NOTE_AS2, 300);   
        //remember bit 0
        bonusLevelAnswer = (bonusLevelAnswer << 1) | 0;
        bonusLevelButtonsPressed++;        
      }
      else if (youWin && easterButtonsPressed < easterTotalButtonsPresses)
      {
        easterAnswer = (easterAnswer << 1) | 0;       
        easterButtonsPressed++;                    
      }
      
      lastInterrupt1 = millis();
    }
}

void pin_ISR_Button2() {  
  if(millis() - lastInterrupt2 > 300) 
    {   
      if (!isBonusLevel && !youWin)      
        switchingPicture = true;
      else if (!youWin && bonusLevelButtonsPressed < bonusLevelTotalButtonsPresses)
      {       

        //make different sound        
        tones[0].play(NOTE_AS3, 300);           
        //remember bit 1
        bonusLevelAnswer = (bonusLevelAnswer << 1) | 1;                
        bonusLevelButtonsPressed++;                  
      } 
      else if (youWin && easterButtonsPressed < easterTotalButtonsPresses)
      {
        easterAnswer = (easterAnswer << 1) | 1;       
        easterButtonsPressed++;                    
      }              
      lastInterrupt2 = millis();
    }
}


void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}



void loop() {
  // Easter
  if (!easter && youWin && easterButtonsPressed == easterTotalButtonsPresses && easterAnswer == 1691)
  {
    Serial.println("It's easter time!");      
    
    currentSong = 5;
    currentPicture = 10;  
    
    currentMelodyNote = 0;
    currentBassNote = 0;    
    previousMelodyMillis = 0;
    previousBassMillis = 0;
    pauseUntilNextMelodyNote = 0;
    pauseUntilNextBassNote = 0;        
    
    currentFrame = 0;
    previousPictureMillis = 0;
    pauseUntilNextFrame = 0;           
    
    easterAnswer = 0;
    easter = true;
    easterStart = millis();
  }
  
  // Stop easter
  if (easter && millis() - easterStart >= 30000)
  {
    currentSong = 3;
    currentPicture = 4;  
    
    currentMelodyNote = 0;
    currentBassNote = 0;    
    previousMelodyMillis = 0;
    previousBassMillis = 0;
    pauseUntilNextMelodyNote = 0;
    pauseUntilNextBassNote = 0;        
    
    currentFrame = 0;
    previousPictureMillis = 0;
    pauseUntilNextFrame = 0;           
     
    easter = false;
  }  
  
  
  // Check win or lose conditions, reset if needed
  if (isBonusLevel && bonusLevelButtonsPressed == bonusLevelTotalButtonsPresses)
  {    
    if (bonusLevelAnswer == 4066)
    {
      isBonusLevel = false;      
      youWin = true;
      
       Serial.println("Bonus solved!");      
      // change to final song and picture      
      currentSong = 4;
      currentPicture = 9;      

      currentMelodyNote = 0;
      currentBassNote = 0;    
      previousMelodyMillis = 0;
      previousBassMillis = 0;
      pauseUntilNextMelodyNote = 0;
      pauseUntilNextBassNote = 0;        
      
      currentFrame = 0;
      previousPictureMillis = 0;
      pauseUntilNextFrame = 0;       
      
      delay(500);
    }
    else
    {
      // Play sad sound
      delay(500);      
      tones[0].play(NOTE_AS3, 300); 
      delay(400);
      tones[0].play(NOTE_E3, 300); 
      delay(400);
      tones[0].play(NOTE_AS2, 300);       
      delay(400);
      
      // Reset
      bonusLevelAnswer = 1;
      bonusLevelButtonsPressed = 0;          
    }
  }
    
  if (switchingSong)
  {
    // check if solved
    if (memcmp(selectedPicture, correctPictures, 4) == 0)
    {
      Serial.println("solved!");
      
      //activate bonus level
      isBonusLevel = true;
      currentSong = 0;
      
      currentPicture = 8;    
      currentFrame = 0;
      previousPictureMillis = 0;
      pauseUntilNextFrame = 0;     
    }
    else
    {        
      // Switch to the next song    
      currentMelodyNote = 0;
      currentBassNote = 0;    
      previousMelodyMillis = 0;
      previousBassMillis = 0;
      pauseUntilNextMelodyNote = 0;
      pauseUntilNextBassNote = 0;  
      
      if (currentSong == songsCount - 1)
        currentSong = 0;
      else  
        currentSong++;          
        
      // update selected picture  
      currentPicture = selectedPicture[currentSong];     
      currentFrame = 0;
      previousPictureMillis = 0;
      pauseUntilNextFrame = 0;          
    }

    //leds off
    leds = 0;    
    updateShiftRegister();
      
    switchingSong = false;
    
  }
  
  if (switchingPicture)
  {
    // Switch to the next picture    
    currentFrame = 0;
    previousPictureMillis = 0;
    pauseUntilNextFrame = 0;  
    
    if (currentPicture == picturesCount - 1)
      currentPicture = 0;
    else  
      currentPicture++;          
      
    switchingPicture = false;    
  }  

  unsigned long currentMillis = millis();
  
  if (currentSong!=0)
    CheckAndPlayCurrentSongNextNote(currentMillis);

  CheckAndShowNextPictureFrame(currentMillis);
  
}




void SwitchLedPhase()
{
  leds = led_phases[currentLedPhase];
  updateShiftRegister();  
  if (currentLedPhase == totalLedPhases - 1)
    currentLedPhase = 0;
  else  
    currentLedPhase++;    
}  

void CheckAndShowNextPictureFrame(
  unsigned long currentMillis
)
{
  if(currentMillis - previousPictureMillis >= pauseUntilNextFrame) 
  {

    previousPictureMillis = currentMillis;   
        
    byte currentFramesArray[8];
    for (int i = 0; i < 8; i++)
    {  
      currentFramesArray[i] = pgm_read_byte_near( Pictures[currentPicture].frames + currentFrame * 8 + i);      
      //Serial.print(t);      
    }

    // Remember selected
    if (!youWin && !isBonusLevel)
      selectedPicture[currentSong] = currentPicture;
    
    // Show picture
    printByte(currentFramesArray);         
    pauseUntilNextFrame = Songs[currentSong].tempo /2;
    
    if (currentFrame == Pictures[currentPicture].framesCount - 1)
      currentFrame = 0;
    else
      currentFrame++ ;      
  }  
  
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}  

void CheckAndPlayCurrentSongNextNote(
  unsigned long currentMillis
  )
{
  if(currentMillis - previousMelodyMillis >= pauseUntilNextMelodyNote) 
  {      
    previousMelodyMillis = currentMillis;   
    int noteLength = pgm_read_word_near(Songs[currentSong].melodyNoteDurations + currentMelodyNote);    
    int noteDuration;  
    if (noteLength / 10 > 0)
      noteDuration = Songs[currentSong].tempo * 1.5 / (noteLength / 10);
    else  
      noteDuration = Songs[currentSong].tempo / noteLength;  
    
    tones[1].play(pgm_read_word_near(Songs[currentSong].melody + currentMelodyNote), noteDuration * 0.9);        
    pauseUntilNextMelodyNote = noteDuration; // * 1.30;    
    
    if (currentMelodyNote == Songs[currentSong].melodyArrSize - 1)
      currentMelodyNote = 0;
    else
      currentMelodyNote++ ;       
  }

  if(Songs[currentSong].hasBass && currentMillis - previousBassMillis >= pauseUntilNextBassNote) 
  {
    previousBassMillis = currentMillis;   
    int noteLength = pgm_read_word_near(Songs[currentSong].bassNoteDurations + currentBassNote);  
    int noteDuration;  
    if (noteLength / 10 > 0)
      noteDuration = Songs[currentSong].tempo * 1.5 / (noteLength / 10);
    else  
      noteDuration = Songs[currentSong].tempo / noteLength;  

    tones[0].play(pgm_read_word_near(Songs[currentSong].bass + currentBassNote), noteDuration * 0.9);          
    
    // switch LED on each bass note     
    
    
    if (pgm_read_word_near(Songs[currentSong].bass + currentBassNote) != 0)
      SwitchLedPhase();          
    


    pauseUntilNextBassNote = noteDuration; // * 1.30;    
    
    if (currentBassNote == Songs[currentSong].bassArrSize - 1)
      currentBassNote = 0;
    else
      currentBassNote++ ;        
  }    
  

  
  
}

