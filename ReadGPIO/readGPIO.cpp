
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
 FILE *exportFILE = NULL;    //Define necessary FILE pointers for GPIO export , set direction , read value , unexport
 FILE *directionFILE = NULL;
 FILE *valueFILE = NULL;
 FILE *unexportFILE = NULL;

 char gpioPin[] = "115";   //Using GPIO115
 char gpioInput[] = "in";  //GPIO input variable
 char gpioValue[5];        //Variable for GPIO value

 exportFILE = fopen("/sys/class/gpio/export","w");     //Open export file , write gpio pin number to this file 
 fwrite(gpioPin,1,sizeof(gpioPin),exportFILE);
 fclose(exportFILE);
 cout<<"Gpio"<<gpioPin<<"is exported"<<endl;


 directionFILE = fopen("/sys/class/gpio/gpio115/direction","w");   //We open GPIO115 direction file,we write "in" for set the direction of pin to input
 fwrite(gpioInput,1,sizeof(gpioInput),directionFILE);
 fclose(directionFILE);
 cout<<"Gpio"<<gpioPin<<"set to input "<<endl;

 valueFILE = fopen("/sys/class/gpio/gpio115/value","r");          //We open GPIO115 value file,to read gpio value
 fread(&gpioValue,sizeof(char),1,valueFILE);
 fclose(valueFILE);

 cout<<"GPIO" <<gpioPin << "Value = "<<gpioValue[0]<<endl;       //Prompt gpio115 value to the user 
 

 unexportFILE = fopen("/sys/class/gpio/unexport","w");          //we open unexport file  , write gpio pin number to unexport pin
 fwrite(gpioPin,1,sizeof(gpioPin),unexportFILE);
 fclose(unexportFILE);

 cout<<"Gpio"<<gpioPin<<"is unexported"<<endl;


 return 0;
}
