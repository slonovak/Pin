#include <iostream>
#include<string>
#include<unistd.h>
#include"pinpi.h"

using namespace std;

int main()
{
    string mod;
    int pin;
    //pinMode(20,INPUT);
    //digitalWrite(20, HIGH);
    while(1)
    {
        cin>> pin >> mod;
        if(mod == "q")
            return 0;
        pinMode(pin, mod);
        cout << pin << mod;
        cin >> mod;
        cout << mod;
        digitalWrite(pin, mod);
    }
    return 0;
}
