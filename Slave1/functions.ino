void declarePins(){
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}

void setHashMap(){
 //     (nummer,poort)
  hashMap[0](0,2);
  hashMap[1](1,3);
  hashMap[2](2,2);
  hashMap[3](3,3);
  hashMap[4](4,2);
  hashMap[5](5,3);
  hashMap[6](6,2);
  hashMap[7](7,3);
  hashMap[8](8,2);
  hashMap[9](9,3);
  hashMap[10](10,2);
  hashMap[11](11,3);
  hashMap[12](12,2);
  hashMap[13](13,3);
  hashMap[14](14,2);
  hashMap[15](15,3);
  hashMap[16](16,2);
  hashMap[17](17,3);
  hashMap[18](18,2);
  hashMap[19](19,3);
  hashMap[20](20,2);
  hashMap[21](21,3);
  hashMap[22](22,2);
  hashMap[23](23,3);

  
}
void relayChange() {
  if(data != ""){
    Serial.print("port: ");
    Serial.println(hashMap.getValueOf(data.toInt()));
    Serial.println();
    
    digitalWrite(hashMap.getValueOf(data.toInt()), LOW);
    delay(delayTime);
    digitalWrite(hashMap.getValueOf(data.toInt()), HIGH);
    data = "";
  }
}
