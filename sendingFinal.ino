#define LASERPIN 7  
void setup() {
  // put your setup code here, to run once:
  pinMode (LASERPIN, OUTPUT) ;

   char myText[] = "A quick brown fox jumped over the lazy dog Number 1";
 int length = sizeof(myText);
 int ar[20];
 int m;
 int bits[8];
 for (int i =0 ; i<length ; i++ ) {
  ar[i]= int(myText[i]);
 }
  for (int n =0 ; n<length ; n++ ){
  m=ar[n];
  int z;
  int bin[7];
  int newbin[7];
  for(z=0;z<8;z++){
    bin[z] = m%2;
    m = m /2 ; 
  }
  
  for (int j= 7 ; j>=0 ; j-- ){
    newbin[7-j] = bin[j] ;
  }
   for( int p=0 ; p<8 ; p++ ){
      if (newbin[p] == 1){
       bits[p] = HIGH ;
      }
      if ( newbin[p] == 0){
       bits[p] = LOW ;
      }
  }

  bits[0] = HIGH;
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(LASERPIN, bits[i]);
    delay(10);
  }

  digitalWrite(LASERPIN, LOW);

  delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
