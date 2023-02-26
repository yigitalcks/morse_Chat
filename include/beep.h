#ifndef BEEP_H
#define BEEP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "failcase.h"
#include "isspace.h"

#define MU 150

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) // if windows
#include <windows.h>

void delay(DWORD mSecond);
void beep_(DWORD freq, DWORD ms);

#elif _linux_ //if linux 
#include <unistd.h>
void delay(unsigned int mSecond);
void beep_(int freq, int ms);

#endif

void ditdah(char dat);
void LV(char let);
void WV(char *WORD);


#endif