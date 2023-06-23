#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H

class Photoresistor
{
private:
    int ldrPin;

public:
    Photoresistor(int pin);

    int read();
};

#endif