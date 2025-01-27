#include <Arduino.h>
#line 1 "H:\\Mohamed Elwarraky files\\DevOps course\\Projects\\arduino_proj\\Test\\Test.ino"
void serial_init();
void start_tests();
void end_test();
String read_data();
void write_data(String res);
void assert_equal(String name, int x, int y);
void assert_not_equal(String name, int x, int y);


#line 10 "H:\\Mohamed Elwarraky files\\DevOps course\\Projects\\arduino_proj\\Test\\Test.ino"
void test1();
#line 16 "H:\\Mohamed Elwarraky files\\DevOps course\\Projects\\arduino_proj\\Test\\Test.ino"
void test2();
#line 22 "H:\\Mohamed Elwarraky files\\DevOps course\\Projects\\arduino_proj\\Test\\Test.ino"
void setup();
#line 27 "H:\\Mohamed Elwarraky files\\DevOps course\\Projects\\arduino_proj\\Test\\Test.ino"
void loop();
#line 10 "H:\\Mohamed Elwarraky files\\DevOps course\\Projects\\arduino_proj\\Test\\Test.ino"
void test1(){
  int x = 5;
  int y = 5;
  assert_equal("Test2", x, y);
}

void test2(){
  int x = 5;
  int y = 6;
  assert_not_equal("Test2", x, y);
}

void setup() { 
	serial_init();
	start_tests();
} 

void loop() { 
  test1();
  test2();
  end_test();
  return;
} 

void serial_init(){
  Serial.begin(115200); 
	Serial.setTimeout(1); 
}

void start_tests(){
  while (!read_data().equals("S"));
  write_data("1");
}

void end_test(){
  write_data("End");
  Serial.end();
}

String read_data(){
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    return Serial.readString();
  }
}

void write_data(String res){
  Serial.write(res.c_str());
  Serial.flush();
}


void assert_equal(String name, int x, int y){
  if(x==y){
    write_data(name + ":1");
  }else{
    write_data(name + ":0");
  }
}

void assert_not_equal(String name, int x, int y){
  if(x==y){
    write_data(name + ":0");
  }else{
    write_data(name + ":1");
  }
}

