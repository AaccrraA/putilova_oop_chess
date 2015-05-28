#ifndef COMMAND_H
#define COMMAND_H

#include "Chess.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command(Chess* p) : pgame(p) {}
	Chess* pgame;
};

#endif