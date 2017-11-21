#include<Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo Brazo;
Servo Brazoo;
Servo Cuerpo;
Servo Pinza;
int a=50;
int b=80;
int c=30;
int d=20;
int f=0;
void setup(){
  lcd.begin(16, 2);
  Serial1.begin(9600);
  pinMode(10,INPUT);
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);
  Brazo.attach(9);
  Brazoo.attach(8);
  Cuerpo.attach(7);
  Pinza.attach(6);
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido");
  Brazo.write(a) ;
  delay(200);
  Brazoo.write(b) ;
  delay(200);
  Cuerpo.write(c) ;
  delay(200);
  Pinza.write(d) ;
  delay(200);
  while(digitalRead(10)==0){
    lcd.clear();
    lcd.setCursor(0, 0);
  
    f=analogRead(A0);
         if (f<340){
           lcd.clear();
           lcd.print( "BLUETOOTH");
           digitalWrite(33,1);
           digitalWrite(34,0);
           digitalWrite(35,0);
           delay(20);
         }
         if(f<680&&f>340){
           lcd.clear();
           lcd.print("AUTOMATIZACION");
           digitalWrite(34,1);
           digitalWrite(35,0);
           digitalWrite(33,0);
           delay(20);
           }
         if(f>680){
           lcd.clear();
           lcd.print("TEST SERVOS");
           digitalWrite(35,1);
           digitalWrite(34,0);
           digitalWrite(33,0);
           delay(20);
        }
     }
   if(f<680&&f>340){
      for(c=30;c<102;c++){
     Cuerpo.write(c);
     delay(50);
     }
     for(a=50;a>0;a--){
     Brazo.write(a);
     delay(50);
     }
     for(b=80;b<160;b++){
     Brazoo.write(b);
     delay(50);
   } 
   
     for(d=20;d<30;d++){
     Pinza.write(d);
     delay(50);
   } 
   }  
}  
void loop() 
{  
   if(f<340){//BLUETOOTH    

      if (Serial1.available())
      

      switch (Serial1.read())
      { 
        case 'F': 
          a++ ;
          if(a>100){
            a=100;
            }
          Brazo.write(a) ;
          delay(50);
          break; 
        case 'B': 
          a--;
          if(a<0){
             a=0;
            }
          Brazo.write(a);
          delay(50);
          break; 
        case 'R':
          b++;
          if(b>145){
            b=145;
          }
          Brazoo.write(b);
          delay(50);
          break; 
        case 'L': 
          b--;
          if(b<80){
            b=80;
          }
          Brazoo.write(b);
          delay(50);
          break; 
        case 'G':
          c++;
          if(c>180){
            c=180;
          }
          Cuerpo.write(c);
          delay(50);
          break; 
        case 'J':
          c--;
          if(c<0){
            c=0;
          }
          Cuerpo.write(c); 
          delay(50);
          break; 
        case 'I':
          d++;
          if(d>70){
            d=70;
          }
          Pinza.write(d);
          delay(50);
          break; 
        case 'H':
          d--;
          if(d<0){
           d=0;
          }
          Pinza.write(d); 
          delay(50);
            break; 
      }
     
    }
   if(f<680&&f>340){//AUTOMATIZACION
 
  for(d=30;d>0;d--){
    Pinza.write(d);
    delay(50);
    }
  for(a=0;a<50;a++){
    Brazo.write(a);
    delay(50);
    
   }
     for(c=102;c>76;c--){
    Cuerpo.write(c);
    delay(50);
    }
    for(d=0;d<30;d++){
     Pinza.write(d);
    delay(50); 
    }
   for(c=76;c<102;c++){
    Cuerpo.write(c);
    delay(50);
    }
    for(a=50;a>0;a--){
    Brazo.write(a);
    delay(50);
    }

 }
   
   if(f>680 && f<1500){//TEST DE FUNCIONAMIENTO'0
   f=2000;
   for(a=0;a<100;a++){
     Brazo.write(a);
     delay(50);
     }
   for(a=100;a>50;a--){
     Brazo.write(a);
     delay(50);
   }
   for(b=80;b<130;b++){
     Brazoo.write(b);
     delay(50);
     }
   for(b=130;b>115;b--){
     Brazoo.write(b);
     delay(50);
   }
   for(c=30;c<180;c++){
     Cuerpo.write(c);
     delay(50);
     }
   for(c=180;c>90;c--){
     Cuerpo.write(c);
     delay(50);
   }
   for(d=20;d<70;d++){
     Pinza.write(d);
     delay(50);
     }
   for(d=70;d>0;d--){
     Pinza.write(d);
     delay(50);
     }
     }
     }
     
