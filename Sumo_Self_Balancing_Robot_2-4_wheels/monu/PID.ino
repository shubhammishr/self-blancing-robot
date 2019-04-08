void npid(){
pid.Compute();
rot.Compute();
MotorASpeed=compensate_slack(motorSpeedo,yout,1);
MotorBSpeed=compensate_slack(motorSpeedo,yout,0);
motorspeed(MotorASpeed, MotorBSpeed);
//Serial.println(motorSpeed);
//  Serial.println("\n");
//**************************************************************************
//  if(motorSpeed<0)
//  
//  {
//   motorSpeed=abs(motorSpeed);
//    if(motorSpeed>255)
//      motorSpeed=255;
//    backward(motorSpeed);
//  }
//  else
//  {     
//    if(motorSpeed>255)
//      motorSpeed=255;
//    forward(motorSpeed);
//  }*************************************************************************
}
