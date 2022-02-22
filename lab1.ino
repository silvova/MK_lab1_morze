String morze[] = {
 ".-", "-..." ,"-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

String encode(String fio) {
  String result;
  String space = { " " };
  String separator = { "|" };
  fio.toLowerCase();
  char x;
  for( int i=0; i<fio.length(); i++){
    if(fio[i] == ' ') { result.concat(space); }
    else { 
      x = fio[i];
      result.concat(morze[x-97]);
      result.concat(separator);
    }
  }
  return result;
}

void dot() {
  digitalWrite(2,HIGH);
  delay(250);
  digitalWrite(2,LOW);
}

void dash() {
  digitalWrite(2,HIGH);
  delay(750);
  digitalWrite(2,LOW);
}

void pause(int a) {
  delay(250*a);
}

void show(String fio){
  Serial.println(fio);
  for( int i=0; i<fio.length(); i++){
    if(fio[i]=='.'){
      dot();
      pause(1);
    }
    else if(fio[i]=='-'){
      dash();
      pause(1);
    }
    else if(fio[i]=='|') { pause(3); }
    else if(fio[i]==' ') { pause(4); }
  }
}
  
void setup() {
  Serial.begin (9600);
  pinMode(2, OUTPUT);

}

void loop() {
  String FIO ("Silchenko Vladimir Andreevich");
  show(encode(FIO));
}
