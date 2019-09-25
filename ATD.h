/*
Author: JOSEPH OWENS

FUNCTIONALITY: This class allows for the use of the Analog to Digital converters

CREATION DATE: 2/25/19
LAST UPDATE: 2/25/19
*/

#ifndef ATD_H
#define ATD_H

#include "Arduino.h"
#include "math.h"

class ATD{
public:
	ATD();
	~ATD();
	void setPin(int pin);
	void setJustified(bool left);
	void setPrescale(int div);
	void setRef(int ref);
	int getData();
	int getData(int sampleSize, int confidence);
private:

};

ATD* name = new ATD();

ATD::ATD(){
	ADMUX = 0x00;
	ADCSRA = 0x00;
}

void ATD::setPin(int pin){
	if (pin <0 || pin >= 8){
		return;
	}
	ADMUX &= 0xE0; 
	ADMUX |= pin;   
}

void ATD::setJustified(bool left){
	if(left){
		ADMUX |= 0x20;
	}
	else{
		ADMUX &= ~0x20;
	}
}

void ATD::setPrescale(int div){
	if(div < 0 || div > 7 ) return;
	ADCSRA &= 0xF8;
	ADCSRA |= div;
}

void ATD::setRef(int ref){
	if(ref < 0 || ref > 4) return;// 0b00000011
	ADMUX |= (ref<<6);
}

int ATD::getData(){
	ADCSRA |= 0x40;
	while(!(ADCSRA & 0x10));
	int val = ADC;
	return val;
}


#endif
