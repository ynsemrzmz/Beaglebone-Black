#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

  

  FILE *LedHandle = NULL;  //We define necessary FILE and file path to blink internal led
  char *ledBrightness = "/sys/class/leds/beaglebone:green:usr3/brightness";
  

  int ledBlinkCounter = 0;
  int ledBlinkDelay = 0; 

  cout<<"How many times do you want led to blink ?"<<endl;
  cin>>ledBlinkCounter;
 
  cout<<"How many seconds do you want led to delay ?"<<endl;     //We ask user to blink delay and blink num
  cin>>ledBlinkDelay; 

  cout<<"Led flash started"<<endl;

  for(int i = 0; i<ledBlinkCounter ; i++){
 
        if((LedHandle = fopen(ledBrightness,"r+"))!= NULL){
                fwrite("1",sizeof(char),1,LedHandle);
                fclose(LedHandle);                  //We open led file if exists and write 1 to blink led 
        }
        else{
                cout<<"Can't open a file"<<endl;
        }

        sleep(ledBlinkDelay);

        if((LedHandle = fopen(ledBrightness,"r+"))!= NULL){
                fwrite("0",sizeof(char),1,LedHandle);   //We open led file if exists and write 0 to off led 
                fclose(LedHandle);

        }  
        else{
                cout<<"Cant open a file"<<endl;
        }

        sleep(ledBlinkDelay);
        
        cout<<"Led blink no : "<<i+1<<endl;
}
  
  cout<<"Led flash stopped"<<endl;

  return 0;

}
