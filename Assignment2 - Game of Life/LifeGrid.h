#include <iostream> 

using namespace std; 

class LifeGrid{
	public: 
		LifeGrid();
		LifeGrid(int height, int width);
		~LifeGrid();

		char** makeGrid(string fileName, int width); 
		char** makeGrid(int height, int  width, double density);
		void checkEdge(int i, int j, int height, int width);
		void reset();
		void update(char** array, int i, int j, int neighbors);
		char** simulation(char** array, int height, int width, int mode);
		bool isEmpty(char** array, int height, int width);

	private:
		char** originalArray;
		char** holderArray;

		bool topLeftCorner;
		bool topRightCorner;
		bool bottomLeftCorner;
		bool bottomRightCorner;
		bool leftEdge;
		bool rightEdge;
		bool topEdge; 
		bool bottomEdge;

};