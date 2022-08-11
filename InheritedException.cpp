#include "InheritedException.h"

const char* InheritedException::What() const throw()
{
    return "Exception: InheritedExcetion: side can't be == 0";
}
