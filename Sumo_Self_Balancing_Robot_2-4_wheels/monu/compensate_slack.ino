
double compensate_slack(double Output,double youtput,bool A)
  {
// Compensate for DC motor non-linear "dead" zone around 0 where small values don't result in movement
//yOutput is for left,right control
 if (Flg==0)
 {
 if(A==1)// switches between motor A and motor B.
  {
   if (Output >= 0) 
   Output = Output + MOTORSLACK - youtput;
   if (Output < 0) 
   Output = Output - MOTORSLACK - youtput;
  }
  else
  {
    if (Output >= 0) 
   Output = Output + MOTORSLACK + youtput;
   if (Output < 0) 
   Output = Output - MOTORSLACK + youtput;
  }
  Output = constrain(Output,-255, 255);
 return Output;
}
if (Flg==1)
{ if(A==1)// switches between motor A and motor B.
  {
   if (Output >= 0) 
   Output = Output + MOTORSLACK;
   if (Output < 0) 
   Output = Output - MOTORSLACK;
  }
  else
  {
    if (Output >= 0) 
   Output = Output + MOTORSLACK ;
   if (Output < 0) 
   Output = Output - MOTORSLACK ;
  }
  Output = constrain(Output,-255, 255);
 return Output;
  }
}


