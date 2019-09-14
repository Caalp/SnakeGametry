#pragma once
#include "Grid.h"
#include "Goal.h"
#include <vector>
class Snake
{
private:
	class Segments
	{
	public:
		Segments(const Location& in_loc);
		Segments(Color in_c);
		void draw(Grid& grid);
		void InitHead(const Location& in_loc);
		void InitBody();
		void Follow(const Segments& next_segment);
		void Moveby(const Location& delta_loc);
		 Location GetLocation() const;
	
	private:
		Location loc;
		Color c;
	};
public:
	
	Snake(const Location& loc);
	void draw(Grid& grid);
	void Moveby(const Location& loc);
	void GrowAndMoveby(const Location& delta_loc);
	bool CheckTiles(const Location& target); //check tiles position
	bool CheckIsInGrid(const Location& headLocation) const;
	bool IsEaten(const Goal& goal, const Location& delta_loc) const;
	Location GetHeadLocation(const Location& delta_loc) const ; // returns to next head location
	
private:
	 static constexpr Color headColor = Colors::Yellow;
	 static constexpr Color bodyColor = Colors::Green;
	 static constexpr int nMaxSegments = 100;
	 std::vector<Segments> nSegments;
	
};