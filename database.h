#pragma once
#include <iostream>
#include <string>
#include "sqlite3.h"
using namespace std;
class database {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "Callback function called";
	int j;

public:
	database();
	double svmweights[12];
	double NNClass[2][7];
	double NNNode[6][12];
	double NBWeights[4][11];
	double J48Weights[48][11];
	void readSVMtable();
	void readNNNodetable();
	void readNNClasstable();
	void readNBtable();
	void readJ48table();
	void databaseclose();
	string J48Decision[48];
	
};