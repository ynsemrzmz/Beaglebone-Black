#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(){
 FILE *exportFILE = NULL;
 FILE *directionFILE = NULL;
 FILE *valueFILE =  NULL;
 FILE *unexportFILE = NULL;     //We define necessary FILEs

 char gpioPin[] = "60";
 char gpioHigh[] = "1";         //We define gpio variables for easy usage
 char gpioLow[] = "0";
 char gpioDirectionOut[] = "out";
 
 int ledBlinkCounter = 0;
 int ledBlinkDelay = 0; 

 exportFILE = fopen("/sys/class/gpio/export","w");
 fwrite(gpioPin,1,sizeof(gpioPin),exportFILE);             //We open export file , write gpio pin number to this file 
 fclose(exportFILE);
 cout<<"Gpio "<<gpioPin<<" is exported"<<endl;

 directionFILE = fopen("/sys/class/gpio/gpio60/direction","w");
 fwrite(gpioDirectionOut,1,sizeof(gpioDirectionOut),directionFILE);   //We open gpio60 direction file,we write "out" for set the direction of pin to  output
 fclose(directionFILE);
 cout<<"Gpio "<<gpioPin<<" direction is set for out "<<endl;

 cout<<"How many times do you want led to blink ?"<<endl;
 cin>>ledBlinkCounter;
 
 cout<<"How many seconds do you want led to delay ?"<<endl;     //We ask user to blink delay and blink num
 cin>>ledBlinkDelay;

 cout<<"Led blink has started"<<endl;

  for(int i = 0;i<ledBlinkCounter;i++){
        cout<<"Led Blink No : "<<i+1<<endl;

        valueFILE = fopen("/sys/class/gpio/gpio60/value","w");
        fwrite(gpioHigh,1,sizeof(gpioHigh),valueFILE);
        fclose(valueFILE);

        sleep(ledBlinkDelay);

        valueFILE = fopen("/sys/class/gpio/gpio60/value","w");          //For each blink we write 1 to gpio60 value file to make gpio HIGH and we write 0 to make gpio pin LOW 
        fwrite(gpioLow,1,sizeof(gpioLow),valueFILE);
        fclose(valueFILE); 

        sleep(ledBlinkDelay);

 }
 cout<<"Led blink has stopped"<<endl;

 unexportFILE = fopen("/sys/class/gpio/unexport", "w");
 fwrite(gpioPin, 1, sizeof(gpioPin),unexportFILE);              //After the blinks are done , we open unexport file  , write gpio pin number to unexport pin
 fclose(unexportFILE);
 cout<<"Gpio "<<gpioPin<<" is unexported"<<endl;
 
 return 0;
}


