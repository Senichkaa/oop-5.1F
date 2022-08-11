#include "Exception.h"

Exception::Exception()
	:message()
{
}

Exception::Exception(const string& m) throw()
	:message(m)
{
}
