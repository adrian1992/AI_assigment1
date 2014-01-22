
#include "agent.h";

/**
	\file		agent.cpp
	\date		20140122 - Magnus Øverbø
	\brief 	Functions for the agent class
**/

/**
Cell* current;			/*< Pointer to the cell the agent located at *
Cell*	charger;			/*< Pointer to the cell where the charger is located*
int		performance;	/*< Performance counter for the agent *
int		battery;			/*< Battery info, for each action the battery is
													depleted by 1 *

**/

/**
	\brief 	Functions for the agent class
	\date		20140122 - Magnus Øverbø
	\param	
	\retval	
**/
Agent::Agent(){}
/**
	\brief 	
	\date		20140122 - Magnus Øverbø
	\param	
	\retval	
**/
Agent::Agent(Cell* tLocation){
	current = tLocation;
	charger = NULL;
	performance = INIT_PERFORMANCE;
	battery	= MAX_BAT;
}
/**
	\brief 	
	\date		20140122 - Magnus Øverbø
	\param	
	\retval	
**/
Agent::Agent(Cell* tLocation, Cell* tCharger){
	current = tLocation;
	charger = tCharger;
	performance = INIT_PERFORMANCE;
	battery	= MAX_BAT;
}
/**
	\brief 	
	\date		20140122 - Magnus Øverbø
	\param	
	\retval	
**/
Agent::~Agent(){}


/**
	\brief 	Moves the agent to an adjacent cell or cleans the current cell

	If the cell is dirty, the cell is cleaned and a performance point is awarded.
	If the cell is clean, it will check if the cell on the

	\date		20140122 - Magnus Øverbø
	\param	
	\retval	
**/
bool Agent::move(){
	bool ret = false;
		//	Check if location is dirty and clean it
	if( current->getDirty() ){
		clean();
		ret = true;
		performance++;
		cout << "\nAction:\t\tCleaned cell";
	}
		//	Try going right
	else if( current->getNeighbor(4)->isSpace() ){
		current = current->getNeightbor(4);
		ret = true;
		performance--;
		cout << "\nAction:\t\tMoved right";
	}
		//	Try going down
	else if( current->getNeighbor(1)->isSpace() ){
		current = current->getNeightbor(1);
		ret = true;
		performance--;
		cout << "\nAction:\t\tMoved down";
	}
		//	Try going left
	else if( current->getNeighbor(3)->isSpace() ){
		current = current->getNeightbor(3);
		ret = true;
		performance--;
		cout << "\nAction:\t\tMoved left";
	}
		//	Try Going up
	else if( current->getNeighbor(2)->isSpace() ){
		current = current->getNeightbor(2);
		ret = true;
		performance--;
		cout << "\nAction:\t\tMoved up";
	}
	else{
		ret = true;
		cout << "\nAction:\t\tNo operation performed";
	}
	return ret;
}

/**
	\brief 	Cleans the current cell
	\date		20140122 - Magnus Øverbø
	\retval	true	If the clel is clean
	\retval false	If the cell is still dirty
**/
bool Agent::clean(){
	current->setDirty( false );
	current->resetAge();
	if( !current->getDirty() )
		return true;
	return false;
}

#endif  // __AGENT_H_INCLUDED__ 