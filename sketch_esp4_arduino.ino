/* RELAZIONE ESPERIENZA DI LABORATORIO 4 - ALTOMARE ANDREA 5^A:
Obiettivo: Realizzare un contatore a due cifre utilizzando due display a 7 segmenti separati.
Analisi: Due display a 7 segmenti richiedono un numero di pin che eccede quelli comandabili in modo digitale da una sechedqa arduino, bisogna quindi trovare il modo di comandarli con
quelli disponibili.
Soluzione: Come una TV a tubo catodico (dove i pixel venivano aggiornati riga per riga e non tutti insieme), i display vanno accesi uno alla volta (poiché non ci sono abbastanza pin
sulla scheda Arduino per accenderli insieme) con una frequenza di aggiornamento elevata (periodo quindi molto breve), in modo che l'occhio umano abbia l'illusione che siano accesi entrambi
nello stasso momento.
Realizzazione: Si collegano due pin diversi (dalla scheda Arduino) alle Vcc di ogni display in modo da poterli accendere e spegnere in modo alternato. Poi con dei fili si collegano i diodi
(segmenti) rispettivi dei due display (a-a ; b-b; c-c; ecc...). Col software (che verrà caricato nella scheda Arduino) si modificano alternatamente le configurazioni dei due display
contemporaneamente, ma solo su uno si vedrà la cifra da mostrare in quel momento poiché l'altro resterà spento dato che non gli verrà fornita la tensione (grazie alle due Vcc tenute separate).
*/

// variabili per i LED
int Vcc1=2; // alimentazione display delle unità
int Vcc2=3; // alimentazione display delle decine
int a=9;
int b=10;
int c=4;
int d=5;
int e=6;
int f=8;
int g=7;
// altre variabili
int i; // indice
int j; // secondo indice

void setup() {
  // put your setup code here, to run once:
  pinMode(Vcc1,OUTPUT);
  pinMode(Vcc2,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // parto con tutti e due i display spenti
  digitalWrite(Vcc1,LOW);
  digitalWrite(Vcc2,LOW);
  
  // ciclo per mostrare i numeri da 00 a 99
  for(i=0;i<100;i++)
  {
    printNumber(i);
  }
}

// la funzione scompone in due cifre il numero da stampare e le "invia" ad un'altra funzione adibita a mostrare le singole cifre
void printNumber(int number)
{
  int digit1; // cifra delle unità
  int digit2; // cifra delle decine
  int j=0; // inizializzazione indice j
  
  // ricavo il valore delle due cifre
  digit1=number%10;
  digit2=(number-digit1)/10;
  
  // il ciclo va da 0 a 11500 perché la sua esecuzione occupa uno spazio totale di circa 1 secondo (ovvero il tempo che ci deve essere fra un numero e l'altro, ad esempio fra 20 e 21)
  while(j<11500)
  {
  // mostro alternatamente le due cifre
  digitalWrite(Vcc2,LOW); // spengo il display delle decine
  displayNumber(digit1); // mostro la prima cifra
  digitalWrite(Vcc1,HIGH); // accendo il display delle unità
  digitalWrite(Vcc1,LOW); // spengo il display delle unità
  displayNumber(digit2); // mostro la seconda cifra
  digitalWrite(Vcc2,HIGH); // accendo il display delle decine
  j++; // incremento j
  }
}

// riceve le singole cifre e le mostra nei display
void displayNumber(int digit)
{
  // accendo i LED dei display a seconda della cifra da mostrare
  switch(digit)
  {
    case 0:
      // 0
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
      break;
      
    case 1:
      // 1
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;
      
    case 2:
      // 2
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
      break;
      
    case 3:
      // 3
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
      break;
      
    case 4:
      // 4
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;
      
    case 5:
      // 5
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;
      
    case 6:
      // 6
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;
      
    case 7:
      // 7
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;
      
    case 8:
      // 8
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;
      
    case 9:
      // 9
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;
      
    default:
      // Tutti i LED spenti
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;
  }
}
