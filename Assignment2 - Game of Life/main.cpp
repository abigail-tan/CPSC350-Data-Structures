#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "UserInput.h"
#include "LifeGrid.h"


using namespace std; 

int main(int argc, char** argv){

	cout << "Hello and welcome to the Game of Life!" << endl;

	UserInput ui;
	char cont;
	int fileType = ui.getFileType();
	int mode = ui.gameMode(); 
	int outputMethod = ui.getOutputMethod(); 
	string filePath = ui.getFilePath(); 
	int height = ui.getHeight(); 
	int width = ui.getWidth(); 
	double density = ui.getDensity(); 

	LifeGrid lg(width, height);
	char** gameBoard;
	ofstream outputFile; 
	int genNum = 0;

	//make initial gameboard
	if(fileType == 0){
		gameBoard = lg.makeGrid(filePath, width);
	}
	else if(fileType == 1){
		gameBoard = lg.makeGrid(height, width, density);
	}
	
	//printing through terminal
	if(outputMethod == 0){
		cout<<"\nStarting/Original Generation: "<<genNum<<"\n";
		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				cout << gameBoard[i][j];
			}
			cout << "\n";
		}
		genNum++;
		cout << "\nTo continue, enter 'y'. If not, enter literally anything else: ";
		cin >> cont;

		while(tolower(cont) == 'y'){
			gameBoard = lg.simulation(gameBoard, height, width, mode);

			cout<<"\nGeneration number: "<<genNum<<"\n";
			for(int i = 0; i < height; ++i)
			{
				for(int j = 0; j < width; ++j)
				{
					cout << gameBoard[i][j];
				}
				cout << "\n";
			}
			cout<<"\n";
			genNum++;

			if(lg.isEmpty(gameBoard, height, width) == true){
				cout<<"This world of cells has died off.\n";
				break;
			}
			if(genNum >= 999){
				cout<<"This world of cells has stabilized.\n";
				break;
			}
			cout << "To continue, enter 'y'. If not, enter literally anything else: ";
			cin >> cont;
		}
	}

	//writing to a file
	else if(outputMethod == 1){
		outputFile.open("YourGameOfLife.out"); 
		outputFile<<"Abby Tan\nPartner: Alex Hamel\n2276413\ntan177@mail.chapman.edu\nCPSC350-02\nGameOfLife\n\n";

		outputFile<<"\nStarting/Original Generation: "<<genNum<<"\n";
		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				outputFile << gameBoard[i][j];
			}
			outputFile << "\n";
		}
		genNum++;
		outputFile << "\n";

		while(lg.isEmpty(gameBoard, height, width) != true && genNum < 1000){
			gameBoard = lg.simulation(gameBoard, height, width, mode);

			outputFile<<"Generation Number: "<<genNum<<"\n";
			for(int i = 0; i < height; ++i)
			{
				for(int j = 0; j < width; ++j)
				{
					outputFile << gameBoard[i][j];
				}
				outputFile << "\n";
			}
			outputFile << "\n";
			genNum++;

			if(lg.isEmpty(gameBoard, height, width) == true){
				outputFile<<"This world of cells has died off.\n";
				break;
			}
			if(genNum >= 999){
				outputFile<<"This world of cells has stabilized.\n";
				break;
			}
		}
		outputFile.close(); //lets user know where the results went
	    cout<<"\nYour Game Of Life has been printed out into YourGameOfLife.out.\n";
	}
	    
	return 0;

}