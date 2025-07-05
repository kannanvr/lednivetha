#define F_CPU 16000000UL  // 1 MHz clock, change if needed
#include <avr/io.h>
#include <util/delay.h>
#include "include/defines.h"
#include "include/playlist.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


extern void output_grb(u8 * ptr, u16 count); // declaration of our ASM function

volatile unsigned long timer0_millis = 0;

u8 buf[NUM_LEDS];










unsigned long millis(void) {
 
 timer0_millis = timer0_millis+1;
 return timer0_millis;
 
}



void BouncingColoredBalls(int BallCount, uint8_t colors[][3], bool continuous) 
{
  float Gravity = -9.81;
  int StartHeight = 3;
  
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
  bool ballBouncing[BallCount];
  bool ballsStillBouncing = true;
  
  for (int i = 0 ; i < BallCount ; i++) {   
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0; 
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - i/pow(BallCount,2);
    ballBouncing[i]=true; 
  }

  int repeatCount = 5; // repeat the animation 5 times
  while (repeatCount > 0) {
    repeatCount--;
    
    ballsStillBouncing = true; // assume balls bouncing
    while (ballsStillBouncing) {
      for (int i = 0 ; i < BallCount ; i++) {
        TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
        Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
    
        if ( Height[i] < 0 ) {                      
          Height[i] = 0;
          ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
          ClockTimeSinceLastBounce[i] = millis();
    
          if ( ImpactVelocity[i] < 0.01 ) {
            if (continuous) {
              ImpactVelocity[i] = ImpactVelocityStart;
            } else {
              ballBouncing[i]=false;
            }
          }
        }
        Position[i] = round( Height[i] * (NUM_LEDS - 1) / StartHeight);
      }
  
      ballsStillBouncing = false; // assume no balls bouncing
      for (int i = 0 ; i < BallCount ; i++) {
        setPixel(Position[i],colors[i][0],colors[i][1],colors[i][2]);
        if ( ballBouncing[i] ) {
          ballsStillBouncing = true;
        }
      }
      
      showStrip();
      setAll(0,0,0);
    }
	   _delay_ms(1000);	//time delay

  }
}


void showStrip() {

	output_grb(buf,NUM_LEDS);

}

void setPixel(int Pixel, uint8_t red, uint8_t green, uint8_t blue) {
   // FastLED
   buf[(Pixel*3)+0] = red;
   buf[(Pixel*3)+1] = green;
   buf[(Pixel*3)+2] = blue;
}

void setAll(uint8_t red, uint8_t green, uint8_t blue) {

    memset(buf, 0, sizeof(buf));	//assign memory location

}




int main(void) {
	//DDRD = 1<<PD2;		// Set PD2 as input (Using for interupt INT0)
	cli();

	DDRD |= (1 << DDD3); // set PD3 to OUTPUT
	DDRD |= (1 << DDD4); // set PD4 to OUTPUT
	
	
	
	//PORTD = 1<<PD2;		// Enable PD2 pull-up resistor


    MCUCR |= (1 << ISC11);
    MCUCR |= (1 << ISC10);


    GICR = (1 << INT1); // Turns on INT0
    TIMSK |= (1 << OCIE2); // Enable Timer0 Compare Match Interrupt

 
	sei();				//Enable Global Interrupt

	
   DDRC=0xff;	//channel port
   PORTC=0xff;		//select channel 0
   DDRB =0xff;   //PB1 is enable output and PB0 is data output
   PORTB=0xff;		//disable output and also data
   _delay_ms(100);	//time delay
   
   
    memset(buf, 0, sizeof(buf));	//assign memory location
	
	while(1)
	{
	
	BouncingColoredBalls(2, colors, false);
	
	   _delay_ms(100);	//time delay



    }	
	
}


 
