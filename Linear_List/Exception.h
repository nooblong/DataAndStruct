//
// Created by lyl on 2019/9/11.
//

#include <math.h>

class outOfRange: public _exception{
public:
    const char* what()const throw(){
        return "Error,Out of Range\n";
    }
};
class badSize:public _exception{
public:
    const char* what()const throw(){
        return "Error,Bad Size";
    }
};