const int SIZE = 512;
const long SLEEP_TIME = 5000;
const int8_t NULL_TEMP = -127;
int8_t temp[SIZE];
int16_t currentIndex;


void setup() {
 // put your setup code here, to run once:
 for (int i=0; i < SIZE; ++i) {
   temp[i] = NULL_TEMP;
 }
 
 currentIndex=0;

 Serial.begin();
}

void loop() {
 publishInfo();
 
 int8_t t = takeTemp();
 temp[currentIndex] = t;
 currentIndex = ((currentIndex + 1) % SIZE);
 
 Bean.sleep(SLEEP_TIME);
}

void publishInfo() {
 Serial.print("[");
 for (int i=currentIndex; i < SIZE; ++i) {
   if (temp[i] == NULL_TEMP) {
     break;
   }
   Serial.print(temp[i]);
   Serial.print(" ");  
 }
 
 for (int i=0; i < currentIndex; ++i) {
   Serial.print(temp[i]);
   Serial.print(" ");  
 }
 Serial.println("]");
 Serial.println(millis());
}

int8_t takeTemp() {
 return (char) Bean.getTemperature();
}
