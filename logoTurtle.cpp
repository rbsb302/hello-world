#include<Arduino.h>
#include "logoTurtle.h"


void logoTurtle::start(String input){
     input_string=input; 
     int len=input_string.length();  //length of the input string
     int w; 
     simpleCmds[0]="\0";
     repeat=1;
     Serial.println("in turtle::start():");
     Serial.println(input_string);
     firstspace=input_string.indexOf(" ");
     space_count=0;  //initializing spcae_count
     for(w=0;w<len;w++)
     {
       if(input_string[w]==32)
       space_count++;
     }
     simpleCmdCount=space_count+1;
     if(input_string.startsWith("repeat"))   //if entered cmd is repeat
      Repeatfun();
     else
      SimpleCmdsfun(); 
}

void logoTurtle::Repeatfun(void){
     int openbracket=input_string.indexOf("[");    //index of open bracket
     int closebracket=input_string.indexOf("]");  //index of close bracket ]
     int i=openbracket+1;
     space_count=0;  //resetting the space count to zero to count the space inside  []  
     for(i;i<closebracket;i++){
         if(input_string[i]==32)
            space_count++;   //counting the number of spaces
      }
      simpleCmdCount=space_count+1;  //total number of commands inside brackets  *****dont change this variable, its being used throughout*****
      int x,space[simpleCmdCount];
      space[0]=firstspace; 
      for(x=1;x<simpleCmdCount;x++)
        {
           space[x]=input_string.indexOf(" ",space[x-1]+1);    //space[0]=first space, space[1]= second space and so on are the index of spaces inbetween commands to be looped
        } 
       //.............................storing the number of repetition...........................................................................      
       repeat=input_string.substring(firstspace,openbracket).toInt();  //converting string 360 from test.substring() to integer 360 for looping*/
       
       //.......................................creating array of index of deimiters from [ to ]............................................................
       int deilmiter[space_count+2];   //considering [ and ] along with spaces
       deilmiter[0]=openbracket;
       deilmiter[simpleCmdCount]=closebracket;
       for(int v=1;v<simpleCmdCount;v++)
       {
          deilmiter[v]=space[v];
        }  
       
       //......................................segregating each command inside bracket to be looped............................................
       String part[simpleCmdCount];
       for(int k=0;k<simpleCmdCount;k++)   
          {
             simpleCmds[k]=input_string.substring((deilmiter[k]+1),deilmiter[k+1]);  //considering k from 0 to k+1,number of spaces +1 last delimiter ]
          }  
}


void logoTurtle::SimpleCmdsfun(){
      
      int w;
      String cmds[space_count+1];   //arry of commands to split 
      int space_at[space_count];
      space_at[0]=firstspace;
      for(w=1;w<space_count;w++){
          space_at[w]=input_string.indexOf(" ",space_at[w-1]+1);
      }
      cmds[0]=input_string.substring(0,space_at[0]);
      for(w=1;w<space_count;w++){
          cmds[w]=input_string.substring(space_at[w-1]+1,space_at[w]);
      }
      cmds[space_count]=input_string.substring(space_at[space_count-1]+1);  //to get last command
      for(w=0;w<=space_count;w++){
          simpleCmds[w]=cmds[w];
      }
}
