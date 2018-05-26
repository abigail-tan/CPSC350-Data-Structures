#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h> 
using namespace std;

//functions to do the calculations and the 1000 dna strings
string computeCountProbability(int ACount, int CCount, int TCount,int GCount,int letterCount,
	double& AProb, double& CProb, double& TProb, double& GProb);

string computeBigramProbability(int bigramAA, int bigramAC, int bigramAT, int bigramAG,
	int bigramCA, int bigramCC, int bigramCT, int bigramCG,
	int bigramTA, int bigramTC, int bigramTT, int bigramTG, 
	int bigramGA, int bigramGC, int bigramGT, int bigramGG,
	int letterCount, int lineCount);

string computeVarStdDev(int letterCount, int lineCount, double& variance, double& deviation, int varianceSum);

string generateDNAStrings(double mean, double deviation, double AProb, double CProb, double TProb, double GProb);

int main(int argc, char** argv) {
	//makes sure the user runs the code with a text file 
	if(!(argc==2)) 
	{
		cout<<"Yikes. You dun screwed up."<<endl
			<<"You need either more or less arguments."<<endl;
		exit(0);
	}
	string filename = argv[1];
	ifstream myFile;
	ofstream outputFile; 
	string text; 
	string outputText;
	char cont; 

	do{
		int letterCount = 0, lineCount = 0, ACount = 0, CCount = 0, TCount = 0, GCount = 0;
		int bigramAA = 0, bigramAC = 0, bigramAT = 0, bigramAG = 0; 
		int bigramCA = 0, bigramCC = 0, bigramCT = 0, bigramCG = 0; 
		int bigramTA = 0, bigramTC = 0, bigramTT = 0, bigramTG = 0; 
		int bigramGA = 0, bigramGC = 0, bigramGT = 0, bigramGG = 0; 
		double AProb, CProb, TProb, GProb;
		double mean, variance, deviation;
		int varianceSum = 0; 

		//first read from file
	    myFile.open(filename.c_str());
	    if(myFile.is_open()){
	   		while(!myFile.eof()){
	   			//lettersInLine & varianceSum used later to determine variance and std deviation
	   			int lettersInLine = 0; 
		    	lineCount++;
		    	getline(myFile, text);

		    	//counts ACTG letters
		   		for(double i = 0; i < text.length(); ++i){
		    		if(toupper(text[i]) == 'A'){
						lettersInLine++;
		    			ACount++; 
		    		}
		    		else if(toupper(text[i]) == 'C'){
		    			lettersInLine++;
		   				CCount++; 
		    		}
		   			else if(toupper(text[i]) == 'T'){
		   				lettersInLine++;
		   				TCount++;
		   			}
		   			else if(toupper(text[i]) == 'G'){
		   				lettersInLine++;
	    				GCount++; 	
		   			}
	    		}

		   		varianceSum += pow(lettersInLine,2);
	    		lettersInLine = 0;

	    		//counts any bigrams in file
		    	for(double i = 0; i < text.length()-1; ++i){
		    		if(toupper(text[i]) == 'A' && toupper(text[i+1])=='A')
		   				bigramAA++; 
		   			else if(toupper(text[i]) == 'A' && toupper(text[i+1])=='C')
		   				bigramAC++; 
		   			else if(toupper(text[i]) == 'A' && toupper(text[i+1])=='T')
	    				bigramAT++; 	    			
	    			else if(toupper(text[i]) == 'A' && toupper(text[i+1])=='G')
		    			bigramAG++; 
		    		else if(toupper(text[i]) == 'C' && toupper(text[i+1])=='A')
		   				bigramCA++; 
		   			else if(toupper(text[i]) == 'C' && toupper(text[i+1])=='C')
		   				bigramCC++; 
		   			else if(toupper(text[i]) == 'C' && toupper(text[i+1])=='T')
	    				bigramCT++;	    			
	    			else if(toupper(text[i]) == 'C' && toupper(text[i+1])=='G')
		    			bigramCG++;  
		    		else if(toupper(text[i]) == 'T' && toupper(text[i+1])=='A')
		   				bigramTA++; 
		   			else if(toupper(text[i]) == 'T' && toupper(text[i+1])=='C')
		   				bigramTC++; 
		   			else if(toupper(text[i]) == 'T' && toupper(text[i+1])=='T')
	    				bigramTT++;	    			
	    			else if(toupper(text[i]) == 'T' && toupper(text[i+1])=='G')
		    			bigramTG++;   
		   			else if(toupper(text[i]) == 'G' && toupper(text[i+1])=='A')
		   				bigramGA++; 
		   			else if(toupper(text[i]) == 'G' && toupper(text[i+1])=='C')
		   				bigramGC++; 
	    			else if(toupper(text[i]) == 'G' && toupper(text[i+1])=='T')	    				
	    				bigramGT++;
		    		else if(toupper(text[i]) == 'G' && toupper(text[i+1])=='G')
		    			bigramGG++;
		   		}
		    }
		}
		myFile.close();

		//calculations
		letterCount = ACount + CCount + TCount + GCount;
		mean = (double)letterCount/(double)lineCount;

		//write results to a new file 
		outputFile.open("abbytan.out"); 
		outputFile<<"Abby Tan\n2276413\ntan177@mail.chapman.edu\nCPSC350-02\nAssignment 1\n\n";
		outputFile<<"SUM: "<<letterCount<<"\n\nMEAN: "<<mean<<"\n\n";
	    outputText = computeCountProbability(ACount, CCount,TCount, GCount, letterCount, AProb, CProb, TProb, GProb);
	    outputFile<<outputText;
	    outputText = computeBigramProbability(bigramAA, bigramAC, bigramAT, bigramAG,
			bigramCA, bigramCC, bigramCT, bigramCG,
			bigramTA, bigramTC, bigramTT, bigramTG, 
			bigramGA, bigramGC, bigramGT, bigramGG, letterCount, lineCount);
	    outputFile<<outputText;
	    outputText = computeVarStdDev(letterCount, lineCount, variance, deviation, varianceSum);
	    outputFile<<outputText;
	    outputText = generateDNAStrings(mean, deviation, AProb, CProb, TProb, GProb);
	    outputFile<<outputText;
	    outputFile.close();

	    //lets user know where the results went
	    cout<<"Your results have been printed out into abbytan.out.\n";

	    //alows user to compute again with a different file
		cout << "Would you like to compute this again? (Y/N) ";
		cin >> cont;
		if(tolower(cont) == 'y'){ 
			cout << "Enter the name for your file: ";
			cin >> filename;
		}
	} while(tolower(cont) == 'y');
}

//calculates probability for the different letters
string computeCountProbability(int ACount, int CCount, int TCount,int GCount,int letterCount,
	double& AProb, double& CProb, double& TProb, double& GProb){
		AProb = 100*((double)ACount/(double)letterCount);
		CProb = 100*((double)CCount/(double)letterCount);
		TProb = 100*((double)TCount/(double)letterCount);
		GProb = 100*((double)GCount/(double)letterCount);
		stringstream text;
		text<<"LETTER PROBABILITIES:\nA: "<<AProb<<"%. C: "<<CProb<<"%. T: "<<TProb<<"%. G: "<<GProb<<"%.\n\n";
	    return text.str();
}

////calculates probability for the different bigrams
string computeBigramProbability(int bigramAA, int bigramAC, int bigramAT, int bigramAG,
	int bigramCA, int bigramCC, int bigramCT, int bigramCG,
	int bigramTA, int bigramTC, int bigramTT, int bigramTG, 
	int bigramGA, int bigramGC, int bigramGT, int bigramGG,
	int letterCount, int lineCount){
		double denom = letterCount - lineCount;
		double AAProb = 100*((double)bigramAA/denom);
		double ACProb = 100*((double)bigramAC/denom);
		double ATProb = 100*((double)bigramAT/denom);
		double AGProb = 100*((double)bigramAG/denom);
		double CAProb = 100*((double)bigramCA/denom);
		double CCProb = 100*((double)bigramCC/denom);
		double CTProb = 100*((double)bigramCT/denom);
		double CGProb = 100*((double)bigramCG/denom);
		double TAProb = 100*((double)bigramTA/denom);
		double TCProb = 100*((double)bigramTC/denom);
		double TTProb = 100*((double)bigramTT/denom);
		double TGProb = 100*((double)bigramTG/denom);
		double GAProb = 100*((double)bigramGA/denom);
		double GCProb = 100*((double)bigramGC/denom);
		double GTProb = 100*((double)bigramGT/denom);
		double GGProb = 100*((double)bigramGG/denom);
		stringstream text;
		text<<"BIGRAM PROBABILITIES:\nAA: "
			<<AAProb<<"%. AC: "<<ACProb<<"%. AT: "<<ATProb<<"%. AG: "<<AGProb<<"%.\nCA: "
			<<CAProb<<"%. CC: "<<CCProb<<"%. CT: "<<CTProb<<"%. CG: "<<CGProb<<"%.\nTA: "
			<<TAProb<<"%. TC: "<<TCProb<<"%. TT: "<<TTProb<<"%. TG: "<<TGProb<<"%.\nGA: "
			<<GAProb<<"%. GC: "<<GCProb<<"%. GT: "<<GTProb<<"%. GG: "<<GGProb<<"%.\n\n";
		return text.str();
}

//calculates variance and std deviation
string computeVarStdDev(int letterCount, int lineCount, double& variance, double& deviation, int varianceSum){
	int sumSquared = pow(letterCount, 2);
	double sumSquaredDiv = (double)sumSquared / (double)lineCount; 
	double subSums = (double)varianceSum - sumSquaredDiv;
	variance = (double)subSums /(double)(lineCount-1);
	deviation = sqrt(variance);
	stringstream text;
	text<<"VARIANCE: "<<variance<<"\n\nSTANDARD DEVIATION: "<<deviation<<"\n\n";
	return text.str();
}

//generates 1000 strings w same probability w/random lengths as the user given file 
string generateDNAStrings(double mean, double deviation, double AProb, double CProb, double TProb, double GProb){
	stringstream text;
	text<<"1000 DNA STRINGS:\n";
	for(int i = 0; i < 1000; ++i){
		//generates two random numbers between (0,1]
		double r1 = ((double)rand() / (RAND_MAX));
		double r2 = ((double)rand() / (RAND_MAX));

		//makes sure it doesn't equal to 1
		while(r1 == 1 || r2 ==1){
			r1 = ((double)rand() / (RAND_MAX));
			r2 = ((double)rand() / (RAND_MAX));

		}

		//calculates for standard Gaussian (C)
		double gaussian = pow(-2*log(r1),0.5)*cos(2*M_PI*r2);

		//calculates random variable D
		double d = (deviation*gaussian)+mean;


		//this next block of code fills in the 1000 strings with the 
		//appropriate letters
		string dna = ""; 
		for(int j = 0; j < d; ++j){
			double rA = AProb / 100;
			double rC = (AProb+CProb) / 100;
			double rT = (AProb+CProb+TProb) / 100;
			double rG = (AProb+CProb+TProb+GProb) / 100;

			double r3 = ((double)rand() / (RAND_MAX));

			if(r3 >= 0 && r3 <= rA)
				dna += 'A';
			else if(r3 > rA && r3 <= rC)
				dna += 'C';
			else if(r3 > rC && r3 <= rT)
				dna += 'T';
			else if(r3 > rT && r3 <= rG)
				dna += 'G';

		}
		text<<dna<<"\n";
	} 
	return text.str();
}