#include "Goal.h"



Goal::Goal(const Location& goal_loc)
{
	loc = goal_loc;
	
	c = GoalColor;
}


void Goal::draw(Grid& grid)
{
	grid.DrawCell(loc, c);
}


 const Location& Goal::GetGoalLocation() const
{
	return loc;
}

 void Goal::SetNewPos(Location newloc)
 {
	 loc = newloc;
 }

 void Goal::SetColor(Color dist)
 {
	 c = dist;
 }

