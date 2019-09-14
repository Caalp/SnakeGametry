#include "Grid.h"

Grid::Grid(Graphics& gfx):
	gfx(gfx)
{
}

void Grid::DrawCell(Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension, dimension, c);
}




