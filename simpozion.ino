#include "FastLED.h"
#define LED_TYPE    WS2812B
#define DATA_PIN    2
#define NUM_LEDS    90
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
 
#define BRIGHTNESS          255
#define frames  120
 
void setup() {
  delay(3000); 
  Serial.begin(9600);
 FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}
 
typedef void (*structura[])();
structura lista = { cursa, foc, curcubeu1, curcubeu2, confetti, joc1, extra, bataie_de_inima, party, alb negru, curcubeu };
 
int fpsetup = 0;
int culori = 0;
 
void loop()
{
  lista[fpsetup]();
  FastLED.show();
  FastLED.delay(1000 / frames);
  delay( 20 ) {
    culori++;  
  }
  delay( 10 ) {
    urmatorul(); 
  }
}
 
#define vector1(A) (a(A) / a((A)[0]))
 
void urmatorul()
{
  fpsetup = (fpsetup + 1) % vector1( lista);
  Serial.println(fpsetup);
}
 
void curcubeu1()
{
  fill_curcubeu1( leds, NUM_LEDS, culori, 7);
}
 
void curcubeu2()
{
  curcubeu1();
  addGlitter(80);
}
 
void addGlitter( int sansa)
{
  if ( random8() < sansa) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}
 
void confetti()
{
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( culori + random8(64), 200, 255);
}
 
void joc1()
{
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS - 1 );
  leds[pos] += CHSV( culori, 255, 192);
}
 
void bataie_de_inima()
{
  int bpm = 62;
  CRGBPalette16 palette = party_p;
  int beat = beatsin8( bpm, 64, 255);
  for ( int i = 0; i < NUM_LEDS; i++) { 
    leds[i] = ColorFromPalette(palette, culori + (i * 2), beat - culori + (i * 10));
  }
}
 
void extra() {
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for ( int i = 0; i < 8; i++) {
    leds[beatsin16( i + 7, 0, NUM_LEDS - 1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
 
#define COOLING  55
#define boom 120
bool invers = false;
 
void foc()
{
  int foc1[NUM_LEDS];
 
  for ( int i = 0; i < NUM_LEDS; i++) {
    foc1[i] = qsub8( foc1[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
  }
 
  for ( int k = NUM_LEDS - 1; k >= 2; k--) {
    foc1[k] = (foc1[k - 1] + foc1[k - 2] + foc1[k - 2] ) / 3;
  }
 
  if ( random8() < boom ) {
    int y = random8(7);
    foc1[y] = qadd8( foc1[y], random8(160, 255) );
  }
 
  for ( int j = 0; j < NUM_LEDS; j++) {
    CRGB color = foc1Color( foc1[j]);
    int nrled;
    if ( invers ) {
      nrled = (NUM_LEDS - 1) - j;
    } else {
      nrled = j;
    }
    leds[nrled] = color;
  }
}
 
void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);
  }
}
 
void cursa() {
 
  int hue = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();  
    delay(10);
  }
 

  for (int i = (NUM_LEDS) - 1; i >= 0; i--) {

    leds[i] = CHSV(hue++, 255, 255);

    FastLED.show();

   
    fadeall();

    delay(10);
  }
 
}
 
CRGBPalette16 cculori;
TBlendType    amestec;
 
void party() {
  if (cculori != party_p) {
    cculori = party_p;
    amestec = LINEARBLEND;
  }
 
  int start1 = 0;
  start1 = start1 + 1; 
 
  cculoriUmplute( start1);
 
}
 
void cculoriUmplute( int colorIndex)
{
  int brightness = 255;
 
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( cculori, colorIndex, brightness, amestec);
    colorIndex += 3;
  }
}
 
void curcubeu() {
  if (cculori != curcubeu_p) {
    cculori = curcubeu_p;
    amestec = LINEARBLEND;
  }
 
  int start1 = 0;
  start1 = start1 + 1; 
 
  cculoriUmplute( start1);
 
}
 
void alb negru()
{

  fill_solid( cculori, 16, CRGB::Black);

  cculori[0] = CRGB::White;
  cculori[4] = CRGB::White;
  cculori[8] = CRGB::White;
  cculori[12] = CRGB::White;
  int start1 = 0;
  start1 = start1 + 1; 
  cculoriUmplute( start1);
 
}
