void setup() {
Serial.begin(9600);
}

String input_string;
void loop() {
 
 if (Serial.available())
{
  char input_char=Serial.read();
     if(input_char=='\n')
     {
        Serial.println(input_string);  //displaying the input string
        int len=input_string.length();  //length of the input string
        // Serial.println(len);

     //.............................processing after recieving command encountered................................................     
  
     //...............segregating delimiters in the command ie: [ spaces and ]...............................
      int firstspace=input_string.indexOf(" ");  //firstspace=index of the first space location ie. between first two commands

     //.................when commands are entered in single line..........................................
     int space_count=0; 

    //.............................when a repeat command is recieved........................................... 
     if(input_string.startsWith("repeat"))   //if entered cmd is repeat
     {
        int openbracket=input_string.indexOf("[");    //index of open bracket
        int closebracket=input_string.indexOf("]");  //index of close bracket ]
      
        // ..................//finding the number of spaces in the looping command []....................      
        int i=openbracket+1;
        space_count=0;  //setting the space count to zero to count the space inside  []  
        
        for(i;i<closebracket;i++)
        {
          if(input_string[i]==32)
          space_count++;   //counting the number of spaces
         }
        int loop_cmd_no=space_count+1;  //total number of commands inside brackets  *****dont change this variable, its being used throughout*****
        int x,space[loop_cmd_no],offset=1;
        space[0]=firstspace; 
       for(x=1;x<loop_cmd_no;x++)
        {
           space[x]=input_string.indexOf(" ",space[x-1]+1);    //space[0]=first space, space[1]= second space and so on are the index of spaces inbetween commands to be looped
        }   
         
        //.............................storing the number of repetition...........................................................................      
        int repeat=input_string.substring(firstspace,openbracket).toInt();  //converting string 360 from test.substring() to integer 360 for looping*/

        
        //.......................................creating array of index of deimiters from [ to ]............................................................
       int deilmiter[space_count+2];   //considering [ and ] along with spaces
       deilmiter[0]=openbracket;
       deilmiter[space_count+1]=closebracket;
       for(int v=1;v<(space_count+1);v++)
       {
          deilmiter[v]=space[v];
        }  
     
     //......................................segregating each command inside bracket to be looped............................................
     String part[loop_cmd_no];
     for(int k=0;k<loop_cmd_no;k++)   
      {
        part[k]=input_string.substring((deilmiter[k]+1),deilmiter[k+1]);  //considering k from 0 to k+1=(n-1)+1=n=count+1=number of spaces +1 last delimiter ]
        //Serial.println("commands inside brackets: ");
        //Serial.println(part[k]);
      }     
      //.........................................................Actual looping process.....................................................................
      for(x=0;x<repeat;x++)        //reusing variable x for main repeat loop
      {
        Serial.print("........................loop");
        Serial.print(x+1);
        Serial.println("..................................");
        for(int j=0;j<loop_cmd_no;j++)  //reusing variable j to use cmds
        {
          
          if(part[j].startsWith("fd")) 
             fd(part[j+1]); 
          
          if(part[j].startsWith("rt")) 
             rt(part[j+1]); 
          
          if(part[j].startsWith("bk")) 
             bk(part[j+1]); 
          
          if(part[j].startsWith("lt")) 
             lt(part[j+1]); 
                     
          if(part[j].startsWith("pu")) 
             pu();
                 
          if(part[j].startsWith("pd")) 
             pd();
         }
      }
    }
//................................................basic commands..........................    
    else
    {
     int w; 
     for(w=0;w<len;w++)
     {
       if(input_string[w]==32)
       space_count++;
     }
     String cmds[space_count+1];   //arry of commands to split 
     
//.............................................multiple commands in single line......................      
     if(space_count>1)
     {
      
      int space_at[space_count];
      space_at[0]=firstspace;
      for(w=1;w<space_count;w++)
      {
        space_at[w]=input_string.indexOf(" ",space_at[w-1]+1);
      }
      cmds[0]=input_string.substring(0,space_at[0]);
      for(w=1;w<space_count;w++)
      {
        cmds[w]=input_string.substring(space_at[w-1]+1,space_at[w]);
      }
      cmds[space_count]=input_string.substring(space_at[space_count-1]+1);  //to get last command
     }
//................................................one command at a time...................................     
     else
     {
      cmds[0]=input_string.substring(0,firstspace);
      cmds[1]=input_string.substring(firstspace+1);
      }

//................................................interpreting recieved commands........................ 
      Serial.println("............basic commands................");     
     for(w=0;w<=space_count;w++)
     {
      if(cmds[w].startsWith("fd"))
        fd(cmds[w+1]);
      
      else if(cmds[w].startsWith("rt"))
        rt(cmds[w+1]);
      
      else if(cmds[w].startsWith("bk"))
        bk(cmds[w+1]);
      
      else if(cmds[w].startsWith("lt"))
        lt(cmds[w+1]);
      
      else if(cmds[w].startsWith("pu"))
          pu();
      
      else if(cmds[w].startsWith("pd"))
          pd();
      }
    }
    input_string="";
  }
  
    else
    input_string +=input_char;
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
