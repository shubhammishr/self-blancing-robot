
void left()
{ 
  getvalues(); 
  pid.Compute();
  MotorASpeed=compensate_slack1(motorSpeedo,yout,1);
MotorBSpeed=compensate_slack1(motorSpeedo,yout,0);

motorspeed(MotorASpeed, MotorBSpeed);
//  digitalWrite(LEFT_MOTOR_FORWARD,HIGH);
//  digitalWrite(LEFT_MOTOR_BACKWARD,LOW);
//   analogWrite(LEFT_MOTOR_PWM,240);
//   digitalWrite(RIGHT_MOTOR_FORWARD,LOW);
//    digitalWrite(RIGHT_MOTOR_BACKWARD,HIGH);
//      analogWrite(RIGHT_MOTOR_PWM, abs(240));
//      //delay(20);
}
  
 void right()
  {
    getvalues(); 
  pid.Compute();
  MotorASpeed=compensate_slack2(motorSpeedo,yout,1);
MotorBSpeed=compensate_slack2(motorSpeedo,yout,0);

motorspeed(MotorASpeed, MotorBSpeed);
//    digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);
//    digitalWrite(RIGHT_MOTOR_BACKWARD,LOW);
//     analogWrite(LEFT_MOTOR_PWM,abs(240));
//    digitalWrite(LEFT_MOTOR_FORWARD,LOW);
//    digitalWrite(LEFT_MOTOR_BACKWARD,HIGH);
//       analogWrite(RIGHT_MOTOR_PWM, abs(240));
//       //delay(20);
  }
  double compensate_slack1(double Output,double youtput,bool A)
  {
// Compensate for DC motor non-linear "dead" zone around 0 where small values don't result in movement
//yOutput is for left,right control
 if(A==1)// switches between motor A and motor B.
  {
   if (Output >= 0) 
   Output = Output + MOTORSLACK - 40;
   if (Output < 0) 
   Output = Output - MOTORSLACK - 40;
  }
  else
  {
    if (Output >= 0) 
   Output = Output + MOTORSLACK + 40;
   if (Output < 0) 
   Output = Output - MOTORSLACK + 40;
  }
  Output = constrain(Output,-255, 255);
 return Output;
  }
   double compensate_slack2(double Output,double youtput,bool A)
  {
// Compensate for DC motor non-linear "dead" zone around 0 where small values don't result in movement
//yOutput is for left,right control
 if(A==1)// switches between motor A and motor B.
  {
   if (Output >= 0) 
   Output = Output + MOTORSLACK + 40;
   if (Output < 0) 
   Output = Output - MOTORSLACK + 40;
  }
  else
  {
    if (Output >= 0) 
   Output = Output + MOTORSLACK - 40;
   if (Output < 0) 
   Output = Output - MOTORSLACK - 40;
  }
  Output = constrain(Output,-255, 255);
 return Output;
  }
