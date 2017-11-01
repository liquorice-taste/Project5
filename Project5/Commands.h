#ifndef _DIGGER_COMMANDS_H_
#define _DIGGER_COMMANDS_H_

#include "Main.h"


class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class GoLeft : public Command
{
public:
	virtual void execute() {
		//change coordinates and direction
	}
};



#endif