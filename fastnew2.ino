#define LM1 6
#define LM2 9
#define RM1 10
#define RM2 11
int v=63;
boolean SL,SML,SMR,SR;
byte etat_prec;


void setup() {
  // put your setup code here, to run once:
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT); 
avancer(v);
delay(400);
}

void loop() {
  // put your main code here, to run repeatedly:
check_ALL();
if (millis()>20000) v=75;
if(!SL&&SML&&SMR&&!SR) {
avancer(v);
etat_prec=0;
}

else if ((SL&&SML&&SMR&&SR)){avancer(v); delay(100) ;
                              }

 
else if(!SL&&SML&&!SMR&&!SR) gauche();
else if(!SR&&SMR&&!SML&&!SL) droite();
else if(SL){ if (millis()<6000)
avancer(v);
else
{gauche1() ; etat_prec=1;}}
                                
else if (SR) {if (millis()<32000)
  {droite1(); if (millis()>9000) delay(100) ; etat_prec=2;}
  else
 {  avancer(v); delay(100);}
 }
              
else if(!SL&&!SML&&!SMR&&!SR) {
switch(etat_prec) {
 
  case 1: gauche1(); break;
  case 2: droite1(); break;
}
}
}


void check_ALL() {
SL=digitalRead(A0);
SML=digitalRead(A1);
SMR=digitalRead(A2);
SR=digitalRead(A3);
}

void avancer (int v){
    analogWrite(LM1,v) ;
    analogWrite(LM2,0) ;
    analogWrite(RM1,v-20) ;
    analogWrite(RM2,0) ;
}

void droite() {
    analogWrite(LM1,v) ;
    analogWrite(LM2,0) ;
    analogWrite(RM1,30) ;
    analogWrite(RM2,0) ;
}
void gauche() {
    analogWrite(LM1,30) ;
    analogWrite(LM2,0) ;
    analogWrite(RM1,v-20) ;
    analogWrite(RM2,0) ;
}
void stope() {
    analogWrite(LM1,0) ;
    analogWrite(LM2,0) ;
    analogWrite(RM1,0) ;
    analogWrite(RM2,0) ;
}
void gauche1() {
    analogWrite(LM1,0) ;
    analogWrite(LM2,v) ;
    analogWrite(RM1,v) ;
    analogWrite(RM2,0) ;
}

void droite1() {
    analogWrite(LM1,v) ;
    analogWrite(LM2,0) ;
    analogWrite(RM1,0) ;
    analogWrite(RM2,v) ;
}
