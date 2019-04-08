void readPIDTuningValues()
{
//   int potKp = analogRead(A0);
//    int potKd = analogRead(A1);
////   // int potKi = 0;//analogRead(A2);
////        
// Kp = map(potKp, 0, 1023, 0, 50) ; //0 - 250
// Kd = map(potKd, 0, 1023, 0, 600) ; //0 - 1000
  // Serial.println(Kd);
   // Ki = map(potKi, 0, 1023, 0, 500) / 100.0; //0 - 5
    pid.SetTunings(33,150,2);
}


