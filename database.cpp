#include "stdafx.h"
#include "sqlite3.h"
#include <iostream>
#include <fstream>
#include <string>
#include "database.h"

using namespace std;
double sweights[12];
double NClass[2][7];
double NNode[6][12];
double nweights[4][11];
double jweights[48][11];
string jdecision[48];
int k;
int j;
int l;
int m;
int n;
database::database() {
	
	rc = sqlite3_open("C:\\SqlLite3\\CMSDatabase.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
}
	static int svmcallback(void *data, int argc, char **argv, char **azColName) {

		//fprintf(stderr, "%s: ", (const char*)data);
		string id;
		string name;
		for (int i = 0; i<argc; i++) {
			//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			sweights[j] = atof(argv[i]);
		}
		j++;
		printf("\n");
		
		return 0;
	}
	static int nnclasscallback(void *data, int argc, char **argv, char **azColName) {
		
		//fprintf(stderr, "%s: ", (const char*)data);
		string id;
		string name;
		for (int i = 0; i<argc; i++) {
			//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			NClass[k][i] = atof(argv[i]);

		}
		
		printf("\n");
		k++;
		return 0;
	}
	static int nnnodecallback(void *data, int argc, char **argv, char **azColName) {

		//fprintf(stderr, "%s: ", (const char*)data);
		string id;
		string name;
		for (int i = 0; i<argc; i++) {
			//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			NNode[l][i] = atof(argv[i]);

		}

		printf("\n");
		l++;
		return 0;
	}
	static int nbcallback(void *data, int argc, char **argv, char **azColName) {

		//fprintf(stderr, "%s: ", (const char*)data);
		string id;
		string name;
		for (int i = 0; i<argc; i++) {
			//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			nweights[m][i] = atof(argv[i]);

		}

		printf("\n");
		m++;
		return 0;
	}
	static int j48callback(void *data, int argc, char **argv, char **azColName) {

		//fprintf(stderr, "%s: ", (const char*)data);
		string id;
		string name;
		for (int i = 0; i<argc; i++) {
			//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			if (i == 11)
			{
				jdecision[n] = (string)argv[i];
				break;
			}
			jweights[n][i] = atof(argv[i]);

		}

		printf("\n");
		n++;
		return 0;
	}
	void database::readSVMtable()
	{
		string sq = " select * from SVMWeights;";
		sql = (char *)sq.c_str();
		rc = sqlite3_exec(db, sql, svmcallback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}

		
		for (int i = 0; i < 12; i++)
		{
			svmweights[i] = sweights[i];
		}
	}
	void database::readNNClasstable()
	{
		k = 0;
		string sq = "select * from NNClass;";
		sql = (char *)sq.c_str();
		rc = sqlite3_exec(db, sql, nnclasscallback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}

		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				NNClass[i][j] = NClass[i][j];
			}
		}
	}
	void database::readNNNodetable()
	{
		l = 0;
		string sq = "select * from NNNode;";
		sql = (char *)sq.c_str();
		rc = sqlite3_exec(db, sql, nnnodecallback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				NNNode[i][j] = NNode[i][j];
			}
		}
	}
	void database::readNBtable()
	{
		m = 0;
		string sq = "select * from NBWeights;";
		sql = (char *)sq.c_str();
		rc = sqlite3_exec(db, sql, nbcallback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				NBWeights[i][j] = nweights[i][j];
			}
		}
	}
	void database::readJ48table()
	{
		n = 0;
		string sq = "select * from J48Weights;";
		sql = (char *)sq.c_str();
		rc = sqlite3_exec(db, sql, j48callback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}
		for (int i = 0; i < 48; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				J48Weights[i][j] = jweights[i][j];
			}
			J48Decision[i] = jdecision[i];
		}
	}
	void database::databaseclose()
	{
		sqlite3_close(db);
	}

