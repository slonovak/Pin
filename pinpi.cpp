#include "pinpi.h"
#include<cstdio>
#include<string>
#include <iostream>
using namespace std;

void pinMode(int pin, std::string mod)
{
    FILE *writer;
    if((writer = fopen("/sys/class/gpio/export", "w")) == NULL)
        printf("ERROR0");
    fprintf(writer, "%d", pin);
    fclose(writer);
    char *ch = new char[33];
    sprintf(ch, "test/gpio%d/direction", pin);
    writer = fopen(ch,"w");
    if(mod == "INPUT")
        fprintf(writer, "in");
    else if(mod == "OUTPUT")
        fprintf(writer, "out");
    else
    {
        printf("ERROR");
        fclose(writer);
        return;
    }
    fclose(writer);
    delete(ch);
}
void pinMode(int pin, char *mod)
{
    FILE *writer;
    if((writer = fopen("/sys/class/gpio/export", "w")) == NULL)
        printf("ERROR1");
    fprintf(writer, "%d", pin);
    fclose(writer);
    char *ch = new char[33];
    sprintf(ch, "test/gpio%d/direction", pin);
    writer = fopen(ch,"w");
    //if(mod == "in" || mod=="out")
    fprintf(writer,"%s", mod);
    /*else
    {
        printf("ERROR");
    }*/
    fclose(writer);
    delete(ch);
}

void digitalWrite(int pin, std::string mod)
{
    FILE *writer;
    char *ch=new char[33];
    sprintf(ch, "/sys/class/gpio/gpio%d/value", pin);
    if((writer = fopen(ch, "w")) == NULL)
        printf("ERROR2");
    if(mod=="HIGH")
        fprintf(writer, "%d", HIGH);
    else if(mod=="LOW")
        fprintf(writer, "%d", LOW);
    else
        printf("ERROR");
    fclose(writer);
    delete(ch);
}
void digitalWrite(int pin, int mod)
{
    FILE *writer;
    char *ch = new char[33];
    sprintf(ch, "/sys/class/gpio/gpio%d/value", pin);
    if((writer = fopen(ch, "w")) == NULL)
        printf("ERROR3");
    if(mod==1||mod==0)
        fprintf(writer, "%d", mod);
    else
        printf("ERROR");
    fclose(writer);
    delete(ch);
}
