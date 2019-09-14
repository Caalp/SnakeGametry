#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Colors.h"

class Grid
{
public:

	Grid(Graphics& gfx);
	void DrawCell(Location& loc, Color c);
	
private:
	Graphics& gfx;
	static constexpr int dimension = 16;

};