/* this code is from the OOP344 notes: http://www.20133notes/SecB/07-Sep27/CIO */
/* and has been partly modified */

#include "console.h"

namespace cio{
    Console console;
    bool Console::_insertMode = true;

    void Console::display(const char* str, int row, int col, int len, int curPosition){
        int i=0;
        setPos(row, col);
        if(len){ //limited number of chars
          for(;i<len&&str[i];i++){
            putChar(str[i]);
          }
          for(;i<len;i++){
            putChar(' ');
          }
        }
        else{  // print the whole thing
          for(;str[i];i++){
            putChar(str[i]);
          }    
        }
        if(curPosition >= 0){
          setPos(row, col + curPosition);
        }
    }
}