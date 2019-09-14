#include "Snake.h"



Snake::Segments::Segments(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

Snake::Segments::Segments(Color in_c)
{
	c = in_c;
}

void Snake::Segments::draw(Grid& grid)
{
	grid.DrawCell(loc, c);
}

void Snake::Segments::InitHead(const Location& in_loc)
{
	c = Snake::headColor;
	loc = in_loc;
}

void Snake::Segments::InitBody()
{
	
	c = Snake::bodyColor;
}

void Snake::Segments::Follow(const Segments& next_segment)
{
	loc = next_segment.loc;
}

void Snake::Segments::Moveby(const Location& delta_loc)
{
	loc.Add(delta_loc);
}

 Location Snake::Segments::GetLocation() const
{

	return loc;
}

Snake::Snake(const Location& loc)
{
	nSegments.emplace_back(loc);
}

void Snake::draw(Grid& grid)
{
	for (auto& s : nSegments)
	{
		s.draw(grid);
	}
}

void Snake::Moveby(const Location& delta_loc)
{
	for (int i = nSegments.size()-1; i > 0; --i)
	{
		nSegments[i].Follow(nSegments[i - 1]);
	}
	nSegments.front().Moveby(delta_loc);
}

void Snake::GrowAndMoveby(const Location& delta_loc)
{

	nSegments.emplace_back(Snake::bodyColor);
	Moveby(delta_loc);

	
}

bool Snake::CheckTiles(const Location& target)
{
	
	for (auto s = 0; s < nSegments.size() - 1; ++s)
	{
		if (nSegments[s].GetLocation() == target)
		{
			return true;
		}

	}
	

	return false;
}

bool Snake::CheckIsInGrid(const Location& headLocation) const
{
	if (headLocation.x == -1.0 || headLocation.x == Graphics::ScreenWidth/10 || headLocation.y == Graphics::ScreenHeight/10 || headLocation.y == -1.0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Snake::IsEaten(const Goal& goal, const Location& delta_loc) const
{
	if (goal.GetGoalLocation() == GetHeadLocation(delta_loc))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Location Snake::GetHeadLocation(const Location& delta_loc) const
{
	Location l(nSegments[0].GetLocation());
	l.Add(delta_loc);
	
	return l;
}



