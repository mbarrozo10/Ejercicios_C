/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned) time(0));
    printf("Your dice has been rolled! You got: \n ");
    int result = 1 + (rand() % 6);
    printf("%d \n", result);
   switch (result) {
    case 1:
        printf("Your prize is our original T-shirt!");
        break;
    case 2:
        printf("Your prize is our original cap!");
        break;
    case 3:
        printf("Your prize is our original necklace!");
        break;
    case 4:
        printf("Your prize is our original keychain!");
        break;
    case 5:
        printf("Your prize is our original cup set!");
        break;
    case 6:
        printf("Your prize is a set of original keychains!");
        break;
    default:
        printf("Error");
        break;
    }
}
// C++ code
//
#include<LiquidCrystal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 27
#define TAMLETRA 10
#define BUTTONRIGHT 8
#define BUTTONOK 9
#define BUTTONLEFT 10


//LiquidCrystal(rs, enable, d4, d5, d6, d7)

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

char abc[TAM]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lifes[4]="***";
char palabraTres[3][TAMLETRA]={"DAVIDGOOD","HOLAMUNDO","PROGRAMAR"};
char palabra[TAMLETRA];
char palabraDos[TAMLETRA]="_________";
int contador = 0;
int buttonRightBefore = 0;
int buttonLeftBefore = 0;
int buttonOkBefore = 0;
int buttonOn=0;
int contadorDos=1;
int flag=0;
int flagWin=0;
int flagLose=0;
int flagSelect=0;
int contLife=3;
int r=1;

void setup()
{
  lcd.begin(16, 2);
  pinMode(8,INPUT); //DERECHA
  pinMode(9,INPUT);//OK
  pinMode(10,INPUT);//IZQUIERDA

}

void setLifes(){
  lcd.setCursor(10,0);
  lcd.print("LP:");
  lcd.print(lifes);
}

void setAbc(){
  lcd.setCursor(6,0);
  lcd.print(abc[contador]);
}

void setWord(){
  strcpy(palabra,palabraTres[r]);
  int len = strlen(palabra);
  palabraDos[0]=palabra[0];
  palabraDos[len-1]=palabra[len-1];
  lcd.setCursor(4,1);
  lcd.print(palabraDos);
}

void cleanScreen(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void buttonRight()
{
  short buttonNow = digitalRead(BUTTONRIGHT);

  if (buttonNow == HIGH && buttonRightBefore == LOW)
  {
    if(flagSelect==0){
      if(r == 2)
      {
        r=0;
      }
      else{
        r++;
      }
    }
    else if(contador == 25)
    {
      contador = 0;
    }
    else{
      contador++;
    }
  }
  buttonRightBefore = buttonNow;
}

void buttonLeft()
{
  short buttonNow = digitalRead(BUTTONLEFT);

  if (buttonNow == HIGH && buttonLeftBefore == LOW)
  {
    if(flagSelect == 0)
    {
      if(r==0)
      {
        r=2;
      }
      else{
        r--;
      }

    }
    else{

      if(contador==0){
         contador=25;
      }
      else{
        contador--;
      }
    }
  }
  buttonLeftBefore = buttonNow;
}

void buttonOk()
{
  short buttonNow = digitalRead(BUTTONOK);

  if (buttonNow == HIGH && buttonOkBefore == LOW)
  {
    if(flagSelect == 0)
      {
        flagSelect = 1;
        lcd.setCursor(0,0);
  		lcd.print("                ");
    }
    else{
      buttonOn = 1;
      flag=0;
    }
  }
  buttonOkBefore = buttonNow;
}

void ganaste(){

 lcd.setCursor(0,0);
 lcd.print("================");
 lcd.setCursor(3,1);
 lcd.print("ganaste owo");
}

void perdiste(){

 lcd.setCursor(2,0);
 lcd.print("perdiste unu");
 lcd.setCursor(2,1);
 lcd.print(palabra);

}

void setAll(){
 if(flagSelect == 0){
    buttons();
    lcd.setCursor(2,0);
    lcd.print ("Elegi: ");
   	lcd.print(r);
 }
  else{

   setLifes();
   setWord();
   setAbc();
  }
}

void buttons(){
 buttonRight();
 buttonLeft();
 buttonOk();
}

void discountLifes(){
   switch(contLife){
   case 3:
     strcpy(lifes,"** ");
     break;
   case 2:
     strcpy(lifes,"*  ");
     break;
   case 1:
     flagLose = 1;
     cleanScreen();
     break;
  }
}

void reader(){
 if(abc[contador]==palabra[contadorDos]){
          palabraDos[contadorDos]=palabra[contadorDos];
         contadorDos++;
          flag=1;
      }else if(contadorDos==9){
          buttonOn=0;
          contadorDos=1;
        if(flag==0){
          discountLifes();
          contLife--;
        }
      }
      else{
      contadorDos++;
      }
}

void loop()
{
  if(flagWin==0 && flagLose == 0){
	setAll();
    buttons();

    if(buttonOn==1){
     reader();
    }
  }

  else{
    if(flagWin == 1)
    {
      ganaste();
    }
    else{
    	if(flagLose == 1)
        {
          perdiste();
        }
    }
  }
  if(strcmp(palabra,palabraDos)==0){
      	flagWin=1;
     cleanScreen();
  }

  delay(10);
}
