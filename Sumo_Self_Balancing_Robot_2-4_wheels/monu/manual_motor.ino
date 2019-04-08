void manualmotor()
{  digitalWrite(LEFT_MOTOR_PWM,HIGH);         //M1E
   digitalWrite(RIGHT_MOTOR_PWM,HIGH); 
      while(1)
         {
  
  if(blue.available() > 0)
  {
    char c= blue.read(); 
    if (c=='P')
  {
     digitalWrite(resetpin, LOW);
   Serial.println("this never happens");
     flag=0;
  
  }
      if (c=='H')
  {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);  
  }
 delay(5000);                     
   while(1)
   {
     getvalues(); 
  readPIDTuningValues();
  //Serial.println(currentAngle);
  npid();
  Bt_control(); 
  //ysetpoint=ysetpoint;
  //Serial.println(currentAngle);
 
  }}
     if (c == 'S' || c=='D') {
      digitalWrite(LEFT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
      digitalWrite(LEFT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high
      digitalWrite(RIGHT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
      digitalWrite(RIGHT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high
   flag=0;
    }
    // if the state is '1' the motor will turn right
    else if (c == 'B') {
        digitalWrite(LEFT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
        digitalWrite(LEFT_MOTOR_BACKWARD, HIGH); // set pin 7 on L293D high
        digitalWrite(RIGHT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
        digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH); // set pin 7 on L293D high
     flag=0;

    }
    
    // if the state is '2' the motor will turn left
    else if (c== 'F') {
        digitalWrite(LEFT_MOTOR_FORWARD, HIGH); // set pin 2 on L293D low
        digitalWrite(LEFT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high
        digitalWrite(RIGHT_MOTOR_FORWARD, HIGH); // set pin 2 on L293D low
        digitalWrite(RIGHT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high
  flag=0;
    }
     else if (c== 'L') {
        digitalWrite(LEFT_MOTOR_FORWARD, HIGH); // set pin 2 on L293D low
          digitalWrite(RIGHT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
        digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH); // set pin 7 on L293D high
        digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
      flag=0;
}
 else if (c == 'R') {
        digitalWrite(LEFT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
        digitalWrite(LEFT_MOTOR_BACKWARD, HIGH); // set pin 7 on L293D high
          digitalWrite(RIGHT_MOTOR_FORWARD, HIGH); // set pin 2 on L293D low
        digitalWrite(RIGHT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high
        flag=0;
 }
        if(flag == 0){
          Serial.println(c);
          flag=1;

 }
 }
 }
 }

