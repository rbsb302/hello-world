#ifndef logoTurtle_h
#define logoTurtle_h

#include "Arduino.h"

class logoTurtle{
  private:
    int count;
    int firstspace;
    
    
 public:
    String input_string;
    int space_count;
    int simpleCmdCount;
    int repeat;
    String simpleCmds[20];

    void start(String input); 
    void SimpleCmdsfun(void);
    void Repeatfun(void);
};

#endif
