#ifndef START_GAME_COMMAND_H
#define START_GAME_COMMAND_H

#include "Command.h"

class StartGameCommand : public Command
{
public:
	StartGameCommand(Chess * p) : Command(p) {}
	void execute() {
		pgame->Start();
	}
};

#endif