
// based on SerialEvent
// created by Romilly Cocking
// http://www.rareschool.com
// and placed in the public domain

const int MAX = 4;
char *greetings[MAX] = {"These", "are", "some", "strings"};
int index = 0;
boolean reply = false;

void setup() {
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // print the string when a newline arrives:
  if (reply) {
    Serial.println(greetings[index++]);
    reply = false;
    if (index == MAX) {
      index = 0;
    }
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char c = (char) Serial.read();
    if (c == '\n') {
      reply = true; 
    }  
  }
}


