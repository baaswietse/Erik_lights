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
  hashMap[0](72,2);
  hashMap[1](73,3);
  hashMap[2](74,2);
  hashMap[3](75,3);
  hashMap[4](76,2);
  hashMap[5](77,3);
  hashMap[6](78,2);
  hashMap[7](79,3);
  hashMap[8](80,2);
  hashMap[9](81,3);
  hashMap[10](82,2);
  hashMap[11](83,3);
  hashMap[12](84,2);
  hashMap[13](85,3);
  hashMap[14](86,2);
  hashMap[15](87,3);
  hashMap[16](88,2);
  hashMap[17](89,3);
  hashMap[18](90,2);
  hashMap[19](91,3);
  hashMap[20](92,2);
  hashMap[21](93,3);
  hashMap[22](94,2);
  hashMap[23](95,3);

  
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
