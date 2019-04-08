void motorInit()
{
  pinMode(LEFT_MOTOR_FORWARD,OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD,OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD,OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD,OUTPUT);
  pinMode(LEFT_MOTOR_PWM,OUTPUT);
  pinMode(RIGHT_MOTOR_PWM,OUTPUT);
}
// Motor control functions
void motorspeed(int MotorASpeed, int MotorBSpeed)
{
if (MotorASpeed >= 0 && MotorBSpeed >= 0) 
  {
    digitalWrite(LEFT_MOTOR_FORWARD,HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD,LOW);
    analogWrite(LEFT_MOTOR_PWM,abs(MotorASpeed));
    digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD,LOW);
    analogWrite(RIGHT_MOTOR_PWM, abs(MotorBSpeed));
  }
  else if (MotorASpeed < 0 &&  MotorBSpeed >= 0)
{
  digitalWrite(LEFT_MOTOR_FORWARD,LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD,HIGH);
   analogWrite(LEFT_MOTOR_PWM,abs(MotorASpeed));
   digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD,LOW);
      analogWrite(RIGHT_MOTOR_PWM, abs(MotorBSpeed));
}
  
  else if (MotorBSpeed < 0 && MotorASpeed >= 0) 
  {
    digitalWrite(RIGHT_MOTOR_FORWARD,LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD,HIGH);
     analogWrite(LEFT_MOTOR_PWM,abs(MotorASpeed));
    digitalWrite(LEFT_MOTOR_FORWARD,HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD,LOW);
       analogWrite(RIGHT_MOTOR_PWM, abs(MotorBSpeed));
  }
  else if (MotorBSpeed < 0 && MotorASpeed < 0) 
  {
  digitalWrite(RIGHT_MOTOR_FORWARD,LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD,HIGH);
  analogWrite(LEFT_MOTOR_PWM,abs(MotorASpeed));
   digitalWrite(LEFT_MOTOR_FORWARD,LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD,HIGH);
   
       analogWrite(RIGHT_MOTOR_PWM, abs(MotorBSpeed));
  }}
//void forward(int pwm){
//  digitalWrite(RIGHT_MOTOR_FORWARD,1);
//  digitalWrite(LEFT_MOTOR_FORWARD,1);
//  digitalWrite(RIGHT_MOTOR_BACKWARD,0);
//  digitalWrite(LEFT_MOTOR_BACKWARD,0);
//  analogWrite(LEFT_MOTOR_PWM,pwm);
//  analogWrite(RIGHT_MOTOR_PWM,pwm);
//}
//
//void backward(int pwm){
//  digitalWrite(RIGHT_MOTOR_FORWARD,0);
//  digitalWrite(LEFT_MOTOR_FORWARD,0);
//  digitalWrite(RIGHT_MOTOR_BACKWARD,1);
//  digitalWrite(LEFT_MOTOR_BACKWARD,1);
//  analogWrite(LEFT_MOTOR_PWM,pwm);
//  analogWrite(RIGHT_MOTOR_PWM,pwm);
//}
//
//void stp(){
//  digitalWrite(RIGHT_MOTOR_FORWARD,0);
//  digitalWrite(LEFT_MOTOR_FORWARD,0);
//  digitalWrite(RIGHT_MOTOR_BACKWARD,0);
//  digitalWrite(LEFT_MOTOR_BACKWARD,0);
//  analogWrite(LEFT_MOTOR_PWM,0);
//  analogWrite(RIGHT_MOTOR_PWM,0);
//}
