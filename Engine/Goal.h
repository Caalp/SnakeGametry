#pragma once
#include "Grid.h"


class Goal
{
public:
	
	Goal(const Location& goal_loc);
	void draw(Grid& grid);
	const Location& GetGoalLocation() const;
	void SetNewPos(Location newloc);
	void SetColor(Color dist);
	

private:
	static constexpr Color GoalColor = Colors::Magenta;
	
	Location loc;
	Color c;



};