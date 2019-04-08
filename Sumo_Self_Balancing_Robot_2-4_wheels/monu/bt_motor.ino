void Bt_control()
{
if(blue.available()>0)
  {
    
  char content=blue.read();
    if(content=='H')
   {           
     digitalWrite(LEFT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
      digitalWrite(LEFT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high
      digitalWrite(RIGHT_MOTOR_FORWARD, LOW); // set pin 2 on L293D low
      digitalWrite(RIGHT_MOTOR_BACKWARD, LOW); // set pin 7 on L293D high// waits 15ms for the servo to reach the position
                   
                    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
                    myservo.write(pos); 
                    delay(15);
                    }
                    while(1){
                      
                    manualmotor();  //manual device control
                  }
  }
     if(content=='F')
     referenceAngle = orireferenceAngle - d_speed;//Serial.println(referenceAngle);}            //forward
     else if(content=='B')
     referenceAngle = orireferenceAngle + d_speed;//Serial.println(referenceAngle);}            //backward
     else if(content=='A')
      referenceAngle = orireferenceAngle - 4.75;
       else if(content=='C')
      referenceAngle = orireferenceAngle + 4.75;
 else if(content=='L')
   left();//Serial.println(ysetpoint);}      //left
     else if(content=='R')
     right();//Serial.println( ysetpoint);}        //right
  else if(content=='S')
     referenceAngle = 2.94;//Serial.println(d_speed);}            //set speed slider
    else if(content=='D')
     ysetpoint = 0;//Serial.println(d_dir);}     //set direction slider
else if(content=='P')
 Flg = !Flg;
  }

}
