#include<Arduino.h>
#include "logo.h"

void Logo::logo(String com)
{
  String part1;
  String part2;            //fd 130  i.e cmd(space)value
  part1=com.substring(0,com.indexOf(" "));   //string from 0 to spcae
  part2=com.substring(com.indexOf(" ")+1);   //string from space +1 position after space 
  Serial.println("in turtlt.logo(string com)");
  Serial.print(part1);
  Serial.print(part2);
  c=command(part1);  //function call to identify command
  p=parameter(part2);   //function call to identify parameter
  Serial.println(p);
  Serial.println(c);
}

char Logo::command(String cmd)
{
  Serial.println(" in command(part1)");
  if(cmd.equalsIgnoreCase("fd"))
  {
    char fwd='f';
    return(fwd);
  }
   
  else if(cmd.equalsIgnoreCase("bk"))
  {
    char back='b';
    return(back);
  }
   
   else if(cmd.equalsIgnoreCase("rt"))
  {
    char right='r';
    return(right);
  }
    
   else if(cmd.equalsIgnoreCase("lt"))
  {
    char left='l';
    return(left);
  }
    
  else if(cmd.equalsIgnoreCase("pu"))
  {
    char up='u';
    return(up);
     }  
  else if(cmd.equalsIgnoreCase("pd"))
  {
    char down='d';
    return(down);
     }         
  else
  {
    return("");
   }
  }

 int Logo::parameter(String para)
  {
    Serial.println("in parameter(part2)");
    int value=para.toInt();
    return(value);
    }
