#pragma once
struct Location
{
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	Location operator*(const int val_loc)
	{
		x *= val_loc;
		y *= val_loc;
		return *this;
	}
	bool operator ==(const Location& target) const
	{
		return x == target.x && y == target.y;
	}
	
	int x;
	int y;
};