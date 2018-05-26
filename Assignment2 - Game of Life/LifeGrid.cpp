#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>	//rand
#include "LifeGrid.h"

using namespace std; 

//default constructor
LifeGrid::LifeGrid()
{
}

//overloaded constructor
LifeGrid::LifeGrid(int height, int width){
	originalArray = new char*[height];
	for(int i = 0; i < height; ++i)
	{
		originalArray[i] = new char[width];
	}

	holderArray = new char*[height];
	for(int i = 0; i < height; ++i)
	{
		holderArray[i] = new char[width];
	}

	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j){
			originalArray[i][j] = '-';
			holderArray[i][j] = '-';
		}
	}

	topLeftCorner = false;
	topRightCorner = false;
	bottomLeftCorner = false;
	bottomRightCorner = false;
	leftEdge = false;
	rightEdge = false;
	topEdge = false; 
	bottomEdge = false;
}

//destructor
LifeGrid::~LifeGrid()
{
	delete [] originalArray;
}

char** LifeGrid::makeGrid(string filePath, int width)
{
	string myString;
	ifstream myFile;
	int lineCount = 0;

	//open file to draw initial grid
	myFile.open(filePath.c_str());
	if(myFile.is_open()){
	   	while(!myFile.eof()){
	   		lineCount++;
	   		getline(myFile, myString);
	   		if(lineCount>2){
	   			for(int i = 0; i < width; ++i){
	   				if(myString[i] == 'x' || myString[i] == 'X')
	   					originalArray[lineCount-3][i] = 'X';
	   				else if(myString[i] == '-')
	   					originalArray[lineCount-3][i] = '-';
	   			}
	   		}
	   	}
	}
	myFile.close();

	return originalArray;
} 

char** LifeGrid::makeGrid(int height, int  width, double density)
{
	double r1;

	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			r1 = ((double)rand() / (RAND_MAX));

			if(r1 <= density)
				originalArray[i][j] = 'X';
			else
				originalArray[i][j] = '-';

		}
	}

	return originalArray; 
}

void LifeGrid::checkEdge(int i, int j, int height, int width)
{
	//check if edge or corner
	if(i == 0 && j == 0)
		topLeftCorner = true;
	else if(i == 0 && j == width - 1)
		topRightCorner = true;
	else if(i == height - 1 && j == width - 1)
		bottomRightCorner = true;
	else if(i == height - 1 && j == 0)
		bottomLeftCorner = true; 

	else if(j == 0)
		leftEdge = true; 
	else if(i == 0)
		topEdge = true;
	else if(j == width - 1)
		rightEdge = true;
	else if(i == height - 1)
		bottomEdge = true; 
}

void LifeGrid::reset()
{
	topLeftCorner = false;
	topRightCorner = false;
	bottomLeftCorner = false;
	bottomRightCorner = false;
	leftEdge = false;
	rightEdge = false;
	topEdge = false; 
	bottomEdge = false;
}

void LifeGrid::update(char** array, int i, int j, int neighbors)
{
	if(neighbors <= 1)
		array[i][j] = '-';
	else if(neighbors == 3)
		array[i][j] = 'X';
	else if(neighbors >= 4)
		array[i][j] = '-';
}

char** LifeGrid::simulation(char** array, int height, int width, int mode)
{
	int neighbors = 0;

	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			holderArray[i][j] = array[i][j];
		}
	}

	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; j++)
		{
			LifeGrid::checkEdge(i, j, height, width);
			if(topLeftCorner == true){
				if(array[i+1][j] == 'X')
					neighbors++;
				if(array[i+1][j+1] == 'X')
					neighbors++;
				if(array[i][j+1] == 'X')
					neighbors++;
				if (mode == 2)
				{
					if (array[height-1][0] == 'X')
						neighbors++;
					if (array[height-1][1] == 'X')
						neighbors++;
					if (array[height-1][width-1] == 'X')
						neighbors++;
					if (array[0][width-1] == 'X')
						neighbors++;
					if (array[1][width-1] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors += 3;
					if (array[i][j+1] == 'X')
						neighbors++;
					if (array[i+1][j] == 'X')
						neighbors++;
				}
			}

			//top right corner
			else if(topRightCorner == true){
				if(array[i+1][j] == 'X')
					neighbors++;
				if(array[i+1][j-1] == 'X')
					neighbors++;
				if(array[i][j-1] == 'X')
					neighbors++;
				if (mode == 2)
				{
					if (array[height-1][width-1] == 'X')
						neighbors++;
					if (array[height-1][width-2] == 'X')
						neighbors++;
					if (array[height-1][0] == 'X')
						neighbors++;
					if (array[0][0] == 'X')
						neighbors++;
					if (array[1][0] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors += 3;
					if (array[i][j-1] == 'X')
						neighbors++;
					if (array[i+1][j] == 'X')
						neighbors++;
				}
			}

			//bottom left corner
			else if(bottomLeftCorner == true){
				if(array[i-1][j] == 'X')
					neighbors++;
				if(array[i-1][j+1] == 'X')
					neighbors++;
				if(array[i][j+1] == 'X')
					neighbors++;
				if (mode == 2)
				{
					if (array[0][0] == 'X')
						neighbors++;
					if (array[0][1] == 'X')
						neighbors++;
					if (array[0][width-1] == 'X')
						neighbors++;
					if (array[height-1][width-1] == 'X')
						neighbors++;
					if (array[height-2][width-1] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors += 3;
					if (array[i][j+1] == 'X')
						neighbors++;
					if (array[i-1][j] == 'X')
						neighbors++;
				}
			}

			//bottom right corner
			else if(bottomRightCorner == true){
				if(array[i][j-1] == 'X')
					neighbors++;
				if(array[i-1][j-1] == 'X')
					neighbors++;
				if(array[i-1][j] == 'X')
					neighbors++;
				if (mode == 2)
				{
					if (array[0][0] == 'X')
						neighbors++;
					if (array[0][width-1] == 'X')
						neighbors++;
					if (array[0][width-2] == 'X')
						neighbors++;
					if (array[height-1][0] == 'X')
						neighbors++;
					if (array[height-2][0] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors += 3;
					if (array[i][j-1] == 'X')
						neighbors++;
					if (array[i-1][j] == 'X')
						neighbors++;
				}
			}

			//left edge
			else if(leftEdge == true){
				if(array[i-1][j] == 'X')
					neighbors++;
				if(array[i-1][j+1] == 'X')
					neighbors++;
				if(array[i][j+1] == 'X')
					neighbors++;
				if(array[i+1][j+1] == 'X')
					neighbors++;
				if(array[i+1][j] == 'X')
					neighbors++;
				if (mode == 2)
				{
					int tempDist = height - i;
					if (array[height-(tempDist-1)][width-1] == 'X')
						neighbors++;
					if (array[height-(tempDist+1)][width-1] == 'X')
						neighbors++;
					if (array[width-tempDist][width-1] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors++;
					if (array[i-1][j] == 'X')
						neighbors++;
					if (array[i+1][j] == 'X')
						neighbors++;
				}
			}

			//right edge
			else if(rightEdge == true){
				if(array[i-1][j] == 'X')
					neighbors++;
				if(array[i-1][j-1] == 'X')
					neighbors++;
				if(array[i][j-1] == 'X')
					neighbors++;
				if(array[i+1][j-1] == 'X')
					neighbors++;
				if(array[i+1][j] == 'X')
					neighbors++;
				if (mode == 2)
				{
					int tempDist = height - i;
					if (array[height-(tempDist-1)][0] == 'X')
						neighbors++;
					if (array[height-(tempDist+1)][0] == 'X')
						neighbors++;
					if (array[width-tempDist][0] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors++;
					if (array[i-1][j] == 'X')
						neighbors++;
					if (array[i+1][j] == 'X')
						neighbors++;
				}
			}

			//top edge
			else if(topEdge == true){
				if(array[i][j-1] == 'X')
					neighbors++;
				if(array[i+1][j-1] == 'X')
					neighbors++;
				if(array[i+1][j] == 'X')
					neighbors++;
				if(array[i+1][j+1] == 'X')
					neighbors++;
				if(array[i][j+1] == 'X')
					neighbors++;
				if (mode == 2)
				{
					int tempDist = width - j;
					if (array[height-1][width-tempDist] == 'X')
						neighbors++;
					if (array[height-1][width-(tempDist+1)] == 'X')
						neighbors++;
					if (array[height-1][width-(tempDist-1)] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors++;
					if (array[i][j+1] == 'X')
						neighbors++;
					if (array[i][j-1] == 'X')
						neighbors++;
				}
			}

			//bottom edge
			else if(bottomEdge == true){
				if(array[i][j-1] == 'X')
					neighbors++;
				if(array[i-1][j-1] == 'X')
					neighbors++;
				if(array[i-1][j] == 'X')
					neighbors++;
				if(array[i-1][j+1] == 'X')
					neighbors++;
				if(array[i][j+1] == 'X')
					neighbors++;
				if (mode == 2)
				{
					int tempDist = width - j;
					if (array[0][width-tempDist] == 'X')
						neighbors++;
					if (array[0][width-(tempDist+1)] == 'X')
						neighbors++;
					if (array[0][width-(tempDist-1)] == 'X')
						neighbors++;
				}
				if (mode == 3)
				{
					if (array[i][j] == 'X')
						neighbors++;
					if (array[i][j+1] == 'X')
						neighbors++;
					if (array[i][j-1] == 'X')
						neighbors++;
				}
			}

			//normal cells in the middle 
			else if(i != 0 && i != height - 1 && j != 0 && j != width - 1){
				if(array[i-1][j-1] == 'X')
					neighbors++;
				if(array[i-1][j] == 'X')
					neighbors++;
				if(array[i-1][j+1] == 'X')
					neighbors++;
				if(array[i][j+1] == 'X')
					neighbors++;
				if(array[i+1][j+1] == 'X')
					neighbors++;
				if(array[i+1][j] == 'X')
					neighbors++;
				if(array[i+1][j-1] == 'X')
					neighbors++;
				if(array[i][j-1] == 'X')
					neighbors++;
			}
			LifeGrid::reset();
			LifeGrid::update(holderArray, i, j, neighbors);
			neighbors = 0;
		}
	}

	return holderArray;
}

bool LifeGrid::isEmpty(char** array, int height, int width)
{
	int max = height* width; 
	int count = 0;
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if (array[i][j] == '-')
				count++;
		}
	}

	if(count == max)
		return true; 
	else
		return false;
}