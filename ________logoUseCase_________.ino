#include <logoTurtle.h>

            
void setup(){
  Serial.begin(9600);
}
logoTurtle turtle;
String recieved_string;
void loop() {
 int i;
 if (Serial.available())
{
  char input_char=Serial.read();
     if(input_char=='\n')
     {
      turtle.start(recieved_string);
      int count=turtle.simpleCmdCount;
      int repeatLoop=turtle.repeat;
      Serial.println(count);
      //turtle.SimpleCmds(); 
      String action[count];
      for(i=0;i<count;i++){
          action[i]=turtle.simpleCmds[i];
      } 
      for(int k=0;k<repeatLoop;k++){
        Serial.print(".................loop");
        Serial.print(k+1);
        Serial.println("....................");
          for(i=0;i<count;i++){   
              if(action[i]=="fd")
                 fd(action[i+1]);
              else if(action[i]=="bk")
                     bk(action[i+1]);
              else if(action[i]=="rt")
                      rt(action[i+1]);
              else if(action[i]=="lt")
                      lt(action[i+1]);
              else if(action[i]=="pu")
                      pu();
              else if(action[i]=="pd")
                      pd();                                         
            }
      }    
      recieved_string ="";
      }
      else
      recieved_string += input_char;
}
}

void fd(String val)
{
  Serial.println("move forward:");
  int value=val.toInt();
  Serial.println(value);
}

void rt(String val)
{
  Serial.println("turn right:");
  int value=val.toInt();
  Serial.println(value);
}

void bk(String val)
{
  Serial.println("move back:");
  int value=val.toInt();
  Serial.println(value);
}

void lt(String val)
{
  Serial.println("turn left:");
  int value=val.toInt();
  Serial.println(value);
}
void pu(void)
{
  Serial.println("pen up");
}
void pd(void)
{
  Serial.println("pen down!! ink on!!");
}
