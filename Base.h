/*
Author: JOSEPH OWENS

FUNCTIONALITY: Stores position and containment information of the ping-pong ball
bases.

CREATION DATE: 4/29/19
LAST UPDATE: 4/29/19
*/

#ifndef BASE_H
#define BASE_H

#include "Arduino.h"
#include "math.h"

class Base{
public:
	Base();
  ~Base();
  void setPos(int);
  void setGrey(int);
  int getPos();
  int getGrey();
private:
  int pos;
  int greyscale;	
};

Base::Base(){
  pos = -1;
  greyscale = -1;
}

Base::~Base(){}

void Base::setPos(int val){
  pos = val;
}

void Base::setGrey(int val){
  greyscale = val;
}

int Base::getPos(){
  return pos;
}

int Base::getGrey(){
  return greyscale;
}

#endif
