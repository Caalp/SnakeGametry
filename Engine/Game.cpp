 /****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	grid(gfx),
	snek({1,1}),
	rng(rd()),
	xdist(8,50),
	ydist(8,32),
	goal({ xdist(rng),ydist(rng) })
	

{
	
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (snek.CheckTiles(snek.GetHeadLocation(delta_loc))|| snek.CheckIsInGrid(snek.GetHeadLocation(delta_loc)))
	{
		GameOver = true;
	}
	else {
		GameOver = false;
	}
	
	if(!GameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			SnekMoveCounter += 5;
		}

		//const auto adjustedTime =  new_delta_loc* dt * 60;
		++SnekMoveCounter;
		if (SnekMoveCounter >= SnekMoveRate)
		{

			if (!snek.IsEaten(goal,delta_loc))
			{
				
				goal.draw(grid);
			}
			else
			{
				snek.GrowAndMoveby(delta_loc);
				goal.SetNewPos({ xdist(rng),ydist(rng) });
   				//goal.SetColor({(unsigned char)(xdist(rng)*3),(unsigned char)(xdist(rng) * 3) ,(unsigned char)(xdist(rng) * 3) });
			}
			SnekMoveCounter = 0;
			snek.Moveby(delta_loc);
		}
		goal.draw(grid);
	}
	
}

void Game::ComposeFrame()
{
	if (GameOver)
	{
		SpriteCodex::DrawGameOver(325, 200, gfx);
	}
	snek.draw(grid);
	
	

	
}
