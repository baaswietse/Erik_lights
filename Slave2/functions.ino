void declarePins(){
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}

void setHashMap(){
 //nummer - poort
  hashMap[0](69,2);
  hashMap[1](70,3);


}
void relayChange() {
  if(data != ""){
    Serial.print("port: ");
    Serial.println(hashMap.getValueOf(data.toInt()));
    
    digitalWrite(hashMap.getValueOf(data.toInt()), LOW);
    delay(delayTime);
    digitalWrite(hashMap.getValueOf(data.toInt()), HIGH);
    data = "";
  }
}
