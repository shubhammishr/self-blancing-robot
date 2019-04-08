#define RIGHT_MOTOR_FORWARD 8
#define RIGHT_MOTOR_BACKWARD 9
#define LEFT_MOTOR_FORWARD 10
#define LEFT_MOTOR_BACKWARD 11
#define RIGHT_MOTOR_PWM 5
#define LEFT_MOTOR_PWM 6
double  Kp,Kd,Ki=0;
double currentAngle=0,accelAngle=0,gyroAngle=0, currentyaw=0,gyrozAngle=0;
double MotorASpeed,MotorBSpeed, motorSpeedo,MOTORSLACK=25,Output;
long previousTime=0, currentTime=0;
//Vector normAccel;
//Vector normGyro;
unsigned long lastTime;
double errSum, lastErr;
float erroffset;
String content = "";
char manual ;
char tunning ;
char character;
int pos=0;
int d_speed=2.8,d_dir=3;
int Flg=0;
