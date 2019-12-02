#ifndef PINPI_H
#define PINPI_H

#include<string>
#define HIGH 1
#define LOW 0
#define INPUT "in"
#define OUTPUT "out"

void pinMode(int pin, std::string mode);
void pinMode(int pin, char *mode);
void digitalWrite(int pin, std::string mode);
void digitalWrite(int pin, int mode);

#endif // PINPI_H
