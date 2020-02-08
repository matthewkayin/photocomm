const int MIC1 = A0;

void setup(){

    Serial.begin(9600);
    pinMode(MIC1, INPUT);
}

void loop(){

    int x = analogRead(MIC1);

    Serial.print(x);
    Serial.print("\n");
}
