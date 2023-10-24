#include "mbed.h"
#include "C12832.h"
#include "ClockDisplay.h"

C12832 lcd(D11, D13, D12, D7, D10);
ClockDisplay cd;
int main() {
    cd.setTime(11,58,50);
    char zerohour,zerominute,zerosecond;
    while(1) {
       lcd.locate(40,12);
       lcd.cls();
       if (cd.getHours()<10) zerohour = '0'; else zerohour = '\0';
       if (cd.getMinutes()<10) zerominute = '0'; else zerominute = '\0';
       if (cd.getSeconds()<10) zerosecond = '0'; else zerosecond = '\0';
       lcd.printf("%c%d:%c%d:%c%d", zerohour,cd.getHours(),zerominute,cd.getMinutes(),zerosecond,cd.getSeconds());
       wait(1);
       cd.tick();
    }  
}
