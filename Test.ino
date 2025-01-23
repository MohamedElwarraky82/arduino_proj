String res; 
void setup() { 
	Serial.begin(115200); 
	Serial.setTimeout(1);
	
} 
void loop() { 
  while (!Serial.available()); 
  res = Serial.readString();
  if (res.equals("Test")){
    Serial.print("Passed");
  }else{
    Serial.print("Failed");
  }
} 
