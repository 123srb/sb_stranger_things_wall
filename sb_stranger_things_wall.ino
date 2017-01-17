  #include <FastLED.h>
 #define NUM_LEDS 34
  #define DATA_PIN 6
 
  char myStrings[][50] = { "badgerbadgerbadgermushroom","hesdeadjim","singthedoomsong","iwannabelennybruce","spookyscaryskeletons"};
  String tempString = "";
  CRGB leds[NUM_LEDS];
  
  int ledNum;
  String color;
  String letter;
  int r;
  int g;
  int b;
  int y = 1;
  
void setup() {
  // put your setup code here, to run once:
  



  Serial.begin(9600);
   FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  size_t i = 0;
  for( i = 0; i < sizeof(myStrings) / sizeof(myStrings[0]); i++)
    {
      size_t j = 0;
      tempString = String(myStrings[i]);
      int tempStringLength = tempString.length();
      for (j = 0; j < tempStringLength; j++)
          {

            letter = String::String(myStrings[i][j]);
            //Serial.print(letter);
              if (letter == "a"){          
              lightUp(31,255,255,102);
              //Yellow;  
              }
              else if(letter=="b"){
              lightUp(30,0,102,255);
              //Blue;
            
              }
              else if(letter=="c"){
              lightUp(29,204,51,0);
              //Red;
            
              }
              else if(letter=="d"){
              lightUp(28,0,153,51);
              //Green;
            
              }
              else if(letter=="e"){
              lightUp(27,101,255,255);
              //CornflowerBlue;
            
              }
              else if(letter=="f"){
              lightUp(26,255,204,102);
              //Orange;
            
              }
              else if(letter=="g"){
              lightUp(25,204,51,0);
              //Red;
            
              }
              else if(letter=="h"){
               lightUp(24,204,51,0); 
              //Green;
            
              }
              else if(letter=="i"){
              lightUp(14,204,51,0);
              //Green;
            
              }
              else if(letter=="j"){
              lightUp(15,153,51,0);
              //DarkRed;
            
              }
              else if(letter=="k"){
              lightUp(16,101,255,255);
              //CornflowerBlue;
            
              }
              else if(letter=="l"){
              lightUp(17,204,51,0);
              //Green;
            
              }
              else if(letter=="m"){
              lightUp(18,255,204,102);
              //Orange;
            
              }
              else if(letter=="n"){
              lightUp(19,204,51,0);
              //Red;
            
              }
              else if(letter=="o"){
              lightUp(20,255,204,255);
              //Pink;
            
              }
              else if(letter=="p"){
              lightUp(21,0,102,0);
              //DarkGreen;
            
              }
              else if(letter=="q"){
              lightUp(22,204,51,0);
              //Red;
            
              }
              else if(letter=="r"){
              lightUp(11,204,51,0);
              //Green;
            
              }
              else if(letter=="s"){
              lightUp(10,255,255,102);
              //Yellow;
            
              }
              else if(letter=="t"){
              lightUp(9,255,204,102);
              //Orange;
            
              }
              else if(letter=="u"){
              lightUp(8,0,102,255);
              //Blue;
            
              }
              else if(letter=="v"){
              lightUp(7,255,204,255);
              //Pink;
            
              }
              else if(letter=="w"){
              lightUp(6,101,255,255);
              //CornflowerBlue;
            
              }
              else if(letter=="x"){              
              lightUp(5,255,204,102);
              //Orange;
            
              }
              else if(letter=="y"){
              lightUp(4,204,51,0);
             //Red;
            
              }
              else if(letter=="z"){
              lightUp(3,204,51,0);
              //Red;
            
              }
              else if(letter==" "){
                delay(500);
              }

           //FastLED.show();
            //delay(1000);
           //FastLED.clear();
          }
       glowup();
       glowdown();
     }
       //#leds[0] = CRGB::Red; 
       // FastLED.show(); 
       // delay(30); 

}



void lightUp(int ledNum, int r,int g,int b)
{
  leds[ledNum].r = r;
  leds[ledNum].g = g;
  leds[ledNum].b = b;
  FastLED.show();
  delay(1500);
  leds[ledNum].r = 0;
  leds[ledNum].g = 0;
  leds[ledNum].b = 0;
  FastLED.show();

  delay(200);
  //FastLED.clear();



}

void glowup() {
  FastLED.clear();
  //Setting i determines your lowest power value. the second condition determines the max value and the y determines your step
  for( int i = 0; i < 255; i = i + y ) {

      int r = i;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
          //Serial.print("derp")
      }
          
      FastLED.show();
      delay(5); 
    }
}

void glowdown() {
  //Same thing as glowup, except in reverse
  for (int i = 255; i > -1; i = i - y){

      int r = i;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(5); 
    }
    FastLED.show();      
}
