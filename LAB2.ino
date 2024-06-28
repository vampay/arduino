#include <LiquidCrystal.h>
float energy=0, Unit=0 ,Bath = 0,KUnit=0,FT=0, Vat = 0,Price = 0;

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {

  lcd.begin(20, 4);
  
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Eng=");
  lcd.print(energy,0);
  energy = energy+10000;
  Unit = energy/1000;

  lcd.setCursor(0, 1);
  lcd.print("Unit:");
  lcd.print(Unit,1);
  
 
    
    if(Unit >=400){
    KUnit= Unit - 400;
    Bath = KUnit * 4.4217 + (250*4.2218) + (50*3.7171) + (65*3.6237) + (10*3.2405) +(10*2.9882) +(15*2.3488);
    }else if(Unit > 150){
      KUnit = Unit-150;
      Bath = (KUnit * 4.2218) +(50*3.7171) + (65*3.6237) + (10*3.2405) +(10*2.9882) +(15*2.3488);
    }

    else if(Unit>100){
    KUnit= Unit - 100;
    Bath = KUnit * 3.7171 + (65*3.6237) + (10*3.2405) +(10*2.9882) +(15*2.3488);
    }else if(Unit > 35){
      KUnit= Unit - 35;
    Bath = (KUnit*3.6237) + (10*3.2405) +(10*2.9882) +(15*2.3488);
    }else if(Unit > 25){
      KUnit= Unit - 25;
    Bath =  (KUnit*3.2405) +(10*2.9882) +(15*2.3488);
    }else if(Unit > 15){
      KUnit= Unit - 15;
    Bath =  (KUnit*2.9882) +(15*2.3488);
    }else if(Unit >= 1 ){
      KUnit= Unit;
    Bath = (KUnit*2.3488);
    }

  

  
    Bath = Bath +8.19;
  

  FT = Unit*0.3972;
  Vat = (Bath + FT)*0.07;


  lcd.setCursor(0, 2);
  lcd.print("FT:");
  lcd.print(FT,2);
  lcd.setCursor(10, 2);
  lcd.print("Vat:");
  lcd.print(Vat,2);

  Price = Bath + FT + Vat;

lcd.setCursor(0, 3);
  lcd.print("Bath:");
  lcd.print(Price,2);


delay(100);





}
