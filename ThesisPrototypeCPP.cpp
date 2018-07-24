// ThesisPrototypeCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "database.h"


using namespace std;
database d;

double sout;
double nsucsum=0;
double nfaisum=0;
string J48decision(double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
{
	string decision;
	/*if (sadness <= 0.0724)
	{
		if (disgust <= 0.7575)
		{
			if (joy <= 99.8443)
			{
				if (contempt <= 0.1928)
				{
					if (joyful <= 0)
					{
						if (contempt <= 0.0003)
							decision = "FAIL";
						else
						{
							if (surprise <= 0.2415)
								decision = "SUCCESS";
							else
							{
								if (sadness <= 0.007)
									decision = "SUCCESS";
								else
									decision = "FAIL";
							}
						}
					}
					else
						decision = "FAIL";
				}
				else
					decision = "FAIL";
			}
			else
				decision = "FAIL";
		}
		else
		{
			if (disgust <=99.5258)
			{
				if (calm <= 30)
				{
					if (sadness <= 0.0246)
						decision = "FAIL";
					else
					{
						if (angered <= 20)
						{
							if (disgust <= 77.4014)
							{
								if (joyful <= 23)
								{
									if (anger <= 0.0152)
									{
										if (fear <= 0.0152)
										{
											if (sadness <= 0.0334)
											{
												if (joy <= 0.0316)
												{
													if (sadness <= 0.0268)
														decision = "SUCCESS";
													else
													{
														if (calm <= 26)
														{
															if (joyful <= 6)
																decision = "SUCCESS";
															else
																decision = "FAIL";
														}
													}
												}
												else
													decision = "FAIL";
											}
											else
												decision = "FAIL";
										}
										else
										{
											if (contempt <= 90.1423)
												decision = "SUCCESS";
											else
												decision = "FAIL";
										}
									}
									else
									{
										if (fear <= 0.2814)
											decision = "FAIL";
										else
										{
											if (sorrow <= 9)
												decision = "FAIL";
											else
												decision = "SUCCESS";
										}
									}
								}
								else
								{
									decision = "FAIL";
								}
							}
							else
								decision = "FAIL";
						}
						else
							decision = "SUCCESS";
					}
				}
				else
				{
					if (fear <= 0.0064)
						decision = "FAIL";
					else
					{
						if (calm <= 43)
						{
							if (anger <= 0.0028)
							{
								if (anger <= 0.0002)
									decision = "FAIL";
								else
								{
									if (sadness <= 0.245)
										decision = "SUCCESS";
									else
									{
										if (joy <= 51.592)
											decision = "SUCCESS";
										else
											decision = "FAIL";
									}
								}
							}
							else
								decision = "FAIL";
						}
						else
							decision = "SUCCESS";
					}
				}
			}
			else
			{
				if (angered <= 4)
				{
					if (sorrow <= 3)
						decision = "SUCCESS";
					else
					{
						if (fear <= 0.572)
							decision = "SUCCESS";
						else
							decision = "FAIL";
					}
				}
				else
					decision = "FAIL";
			}
		}
	}
	else
	{
		if (calm <= 33)
			decision = "FAIL";
		else
		{
			if (surprise <= 0.2312)
				decision = "SUCCESS";
			else 
			{
				if (joy <= 0.0019)
				{
					if (calm <= 41)
						decision = "FAIL";
					else 
					{
						if (anger <= 0.0047)
							decision = "SUCCESS";
						else
						{
							if (disgust <= 0.4551)
								decision = "FAIL";
							else
							{
								if (sadness <= 43.7258)
									decision = "SUCCESS";
								else
									decision = "FAIL";
							}
						}
					}
				}
				else 
				{
					if (joy <= 99.5701)
						decision = "SUCCESS";
					else
					{
						if (contempt <= 0.2655)
							decision = "FAIL";
						else 
						{
							if (sadness <= 9.2052)
							{
								if (anger <= 52.2878)
								{
									if (sorrow <= 6)
										decision = "SUCCESS";
									else
									{
										if (sadness <= 1)
											decision = "FAIL";
										else
											decision = "SUCCESS";
									}
								}
								else
									decision = "FAIL";
							}
							else
							{
								if (sorrow <= 2)
									decision = "FAIL";
								else
									decision = "SUCCESS";
							}
						}
					}
				}
			}
		}
	}*/
double input[11];
input[0] = joy;
input[1] = fear;
input[2] = disgust;
input[3] = sadness;
input[4] = anger;
input[5] = surprise;
input[6] = contempt;
input[7] = calm;
input[8] = angered;
input[9] = joyful;
input[10] = sorrow;
int a = 0;
int b = 0;
int c = 0;
for (int i = 0; i < 48; i++)
{
	for (int j = 0; j <11; j++)
	{

		if (input[j] > d.J48Weights[i][j])
		{
			a++;
		}
		
	}
	if (a == 10)
	{
		b = i;
		c = a;
		break;
	}
	a = 0;
}
decision = d.J48Decision[b];
	return decision;
}
string SVMdecision(double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
{
	
	
	/*
	double bias = 1.0922;
	double joyweight = 0.0017;
	double fearweight = -0.6345;
	double disgustweight = -0.0074;
	double sadnessweight = 0.4053;
	double angerweight = -2.5047;
	double surpriseweight = -0.0067;
	double contemptweight = 0.0131;
	double calmweight = -0.0315;
	double angeredweight = 0.0029;
	double joyfulweight = 0.0029;
	double sorrowweight = 0.0187;
	*/
	double judgment = d.svmweights[0] + joy * d.svmweights[1] + fear * d.svmweights[2] + disgust * d.svmweights[3] + sadness * d.svmweights[4] + anger * d.svmweights[5] + surprise * d.svmweights[6] + contempt * d.svmweights[7] + calm * d.svmweights[8] + angered * d.svmweights[9] + joyful * d.svmweights[10] + sorrow * d.svmweights[11];
	sout = judgment;
	if (judgment < 0)
		return "FAIL";
	else
		return "SUCCESS";
	

}
string NBdecision(double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
{
	double input[11];
	input[0] = joy;
	input[1] = fear;
	input[2] = disgust;
	input[3] = sadness;
	input[4] = anger;
	input[5] = surprise;
	input[6] = contempt;
	input[7] = calm;
	input[8] = angered;
	input[9] = joyful;
	input[10] = sorrow;
	double inputMeanSuccess[11];
	/*inputMeanSuccess[0] = 3.1249;
	inputMeanSuccess[1] = 2.1108;
	inputMeanSuccess[2] = 26.0189;
	inputMeanSuccess[3] = 3.3424;
	inputMeanSuccess[4] = 2.5984;
	inputMeanSuccess[5] = 17.2688;
	inputMeanSuccess[6] = 14.1097;
	inputMeanSuccess[7] = 34.6099;
	inputMeanSuccess[8] = 2.5869;
	inputMeanSuccess[9] = 6.0399;
	inputMeanSuccess[10] = 4.9393;*/
	for (int i = 0; i < 11; i++)
	{
		inputMeanSuccess[i] = d.NBWeights[0][i];
	}
	double inputMeanFail[11];
	/*inputMeanFail[0] = 40.6032;
	inputMeanFail[1] = 1.0318;
	inputMeanFail[2] = 17.2982;
	inputMeanFail[3] = 2.2583;
	inputMeanFail[4] = 1.0152;
	inputMeanFail[5] = 12.1138;
	inputMeanFail[6] = 11.5452;
	inputMeanFail[7] = 29.8941;
	inputMeanFail[8] = 3.4818;
	inputMeanFail[9] = 8.6972;
	inputMeanFail[10] = 6.1471;*/
	for (int i = 0; i < 11; i++)
	{
		inputMeanFail[i] = d.NBWeights[1][i];
	}
	double inputVarianceSuccess[11];
	/*inputVarianceSuccess[0] = 2257.3426;
	inputVarianceSuccess[1] = 87.3870;
	inputVarianceSuccess[2] = 1520.8128;
	inputVarianceSuccess[3] = 170.9164;
	inputVarianceSuccess[4] = 84.4579;
	inputVarianceSuccess[5] = 791.5276;
	inputVarianceSuccess[6] = 921.1346;
	inputVarianceSuccess[7] = 148.7497;
	inputVarianceSuccess[8] = 24.6592;
	inputVarianceSuccess[9] = 67.9058;
	inputVarianceSuccess[10] = 45.2512;*/
	for (int i = 0; i < 11; i++)
	{
		inputVarianceSuccess[i] = d.NBWeights[2][i];
	}
	double inputVarianceFail[11];
	/*inputVarianceFail[0] = 2310.6576;
	inputVarianceFail[1] = 40.7452;
	inputVarianceFail[2] = 1080.8840;
	inputVarianceFail[3] = 138.8603;
	inputVarianceFail[4] = 40.7695;
	inputVarianceFail[5] = 564.0768;
	inputVarianceFail[6] = 760.1104;
	inputVarianceFail[7] = 173.8337;
	inputVarianceFail[8] = 36.6158;
	inputVarianceFail[9] = 111.4228;
	inputVarianceFail[10] = 58.1452;*/
	for (int i = 0; i < 11; i++)
	{
		inputVarianceFail[i] = d.NBWeights[3][i];
	}
	double probableSuccess[11];
	double probableFail[11];
	double label[2]; 
	for (int i = 0; i < 11; i++)
	{
		probableSuccess[i] = 1 / sqrt(2 * 3.14 * inputVarianceSuccess[i]) * exp(-(input[i] - inputMeanSuccess[i])* (input[i] - inputMeanSuccess[i]) / (2 * inputVarianceSuccess[i]));
		probableFail[i] = 1 / sqrt(2 * 3.14 * inputVarianceFail[i]) * exp(-(input[i] - inputMeanFail[i])* (input[i] - inputMeanFail[i]) / (2 * inputVarianceFail[i]));
	}
	for (int i = 0; i < 11; i++)
	{
		label[0] = label[0] * probableSuccess[i];
		label[1] = label[1] * probableFail[i];
	}
	if (label[0] > label[1])
		return "Success";
	else
		return "Fail";
}
void NNdecision(double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
{
	double sigmoidnode0[7];
	/*sigmoidnode0[0] = 0.804680577449594;
	sigmoidnode0[1] = -4.245697246747405;
	sigmoidnode0[2] = -1.420063943108316;
	sigmoidnode0[3] = -1.3330678274087004;
	sigmoidnode0[4] = -1.4729447579702182;
	sigmoidnode0[5] = -1.4729447579702182;
	sigmoidnode0[6] = -2.1117325801889084;*/
	for (int i = 0; i < 7; i++)
	{
		sigmoidnode0[i] = d.NNClass[0][i];
	}
	double sigmoidnode1[7];
	/*sigmoidnode1[0] = -0.8046805774496594;
	sigmoidnode1[1] = 4.245697246747405;
	sigmoidnode1[2] = 1.420063943108316;
	sigmoidnode1[3] = 1.3330678274087004;
	sigmoidnode1[4] = 1.4729447579702182;
	sigmoidnode1[5] = -2.5144998825918723;
	sigmoidnode1[6] = 2.1117325801889084;*/
	for (int i = 0; i < 7; i++)
	{
		sigmoidnode1[i] = d.NNClass[1][i];
	}
	double sigmoidnode2[12];
	/*sigmoidnode2[0] = -12.144811586491553;
	sigmoidnode2[1] = 1.3418230161045663;
	sigmoidnode2[2] = -2.5174280670573244;
	sigmoidnode2[3] = -17.73570185924864;
	sigmoidnode2[4] = 5.171621053033813;
	sigmoidnode2[5] = -4.090904271113604;
	sigmoidnode2[6] = -3.0051003452501015;
	sigmoidnode2[7] = 5.359864853144869;
	sigmoidnode2[8] = -3.6885759719044366;
	sigmoidnode2[9] = -0.8971095781309818;
	sigmoidnode2[10] = 14.833622100361394;
	sigmoidnode2[11] = 5.976107030400978;*/
	for (int i = 0; i < 12; i++)
	{
		sigmoidnode2[i] = d.NNNode[0][i];
	}
	double sigmoidnode3[12];
	/*sigmoidnode3[0] = -7.8747154861709285;
	sigmoidnode3[1] = 2.9134097638333727;
	sigmoidnode3[2] = 5.465521944978445;
	sigmoidnode3[3] = -2.841618946565676;
	sigmoidnode3[4] = -7.9865002230279645;
	sigmoidnode3[5] = -13.178292762934126;
	sigmoidnode3[6] = 4.718536985262529;
	sigmoidnode3[7] = -6.727819449141782;
	sigmoidnode3[8] = -2.836105232153538;
	sigmoidnode3[9] = 12.298742081701944;
	sigmoidnode3[10] = -0.35657213343903366;
	sigmoidnode3[11] = 9.044701600562144;*/
	for (int i = 0; i < 12; i++)
	{
		sigmoidnode3[i] = d.NNNode[1][i];
	}
	double sigmoidnode4[12];
	/*sigmoidnode4[0] = -3.9544029417899704;
	sigmoidnode4[1] = -2.8169055075815796;
	sigmoidnode4[2] = -3.867095415579263;
	sigmoidnode4[3] = -0.02677732040043623;
	sigmoidnode4[4] = 4.676718930269602;
	sigmoidnode4[5] = -8.307041866863253;
	sigmoidnode4[6] = -12.701541216582623;
	sigmoidnode4[7] = -1.161960746817769;
	sigmoidnode4[8] = -9.580602864737989;
	sigmoidnode4[9] = 0.9571498645435002;
	sigmoidnode4[10] = 10.839930046794844;
	sigmoidnode4[11] = 5.619857676102202;*/
	for (int i = 0; i < 12; i++)
	{
		sigmoidnode4[i] = d.NNNode[2][i];
	}
	double sigmoidnode5[12];
	/*sigmoidnode5[0] = -15.393668144694647;
	sigmoidnode5[1] = 23.817405497852633;
	sigmoidnode5[2] = 4.21805033173585;
	sigmoidnode5[3] = -22.66220998116557;
	sigmoidnode5[4] = 7.254688954537451;
	sigmoidnode5[5] = -20.129766764454427;
	sigmoidnode5[6] = -24.51164907430425;
	sigmoidnode5[7] = 0.8029991100752082;
	sigmoidnode5[8] = 10.410231865707422;
	sigmoidnode5[9] = 8.623615926385158;
	sigmoidnode5[10] = 6.920297824506983;
	sigmoidnode5[11] = 8.740407353719997;*/
	for (int i = 0; i < 12; i++)
	{
		sigmoidnode5[i] = d.NNNode[3][i];
	}
	double sigmoidnode6[12];
	/*sigmoidnode6[0] = -1.1890181946415472;
	sigmoidnode6[1] = 4.443743950919829;
	sigmoidnode6[2] = 2.320071315848898;
	sigmoidnode6[3] = -4.448267468090674;
	sigmoidnode6[4] = 5.6377857664839235;
	sigmoidnode6[5] = -0.333379977092494;
	sigmoidnode6[6] = -11.254448794852653;
	sigmoidnode6[7] = 3.7811526540462017;
	sigmoidnode6[8] = -9.384578541987338;
	sigmoidnode6[9] = -2.932829576975326;
	sigmoidnode6[10] = 11.39029162930972;
	sigmoidnode6[11] = 7.348932793224209;*/
	for (int i = 0; i < 12; i++)
	{
		sigmoidnode6[i] = d.NNNode[4][i];
	}
	double sigmoidnode7[12];
	/*sigmoidnode7[0] = -3.1885103043792893;
	sigmoidnode7[1] = -9.53881595195595;
	sigmoidnode7[2] = -3.150999767174384;
	sigmoidnode7[3] = 8.995129336646286;
	sigmoidnode7[4] = 4.558545398329673;
	sigmoidnode7[5] = -0.71983130450572;
	sigmoidnode7[6] = 9.227853984111233;
	sigmoidnode7[7] = -2.289832263939641;
	sigmoidnode7[8] = -0.740989550197029;
	sigmoidnode7[9] = 11.230612330377557;
	sigmoidnode7[10] = 2.0857774181381;
	sigmoidnode7[11] = -2.1023081549918734;*/
	for (int i = 0; i < 12; i++)
	{
		sigmoidnode7[i] = d.NNNode[5][i];
	}
	double firstcom[6];
	firstcom[0] = sigmoidnode2[0] + sigmoidnode2[1] * joy + sigmoidnode2[2] * fear + sigmoidnode2[3] * disgust + sigmoidnode2[4] * sadness + sigmoidnode2[5] * anger + sigmoidnode2[6] * surprise + sigmoidnode2[7] * contempt + sigmoidnode2[8] * calm + sigmoidnode2[9] * angered + sigmoidnode2[10] * joyful + sigmoidnode2[11] * sorrow;
	firstcom[1] = sigmoidnode3[0] + sigmoidnode3[1] * joy + sigmoidnode3[2] * fear + sigmoidnode3[3] * disgust + sigmoidnode3[4] * sadness + sigmoidnode3[5] * anger + sigmoidnode3[6] * surprise + sigmoidnode3[7] * contempt + sigmoidnode3[8] * calm + sigmoidnode3[9] * angered + sigmoidnode3[10] * joyful + sigmoidnode3[11] * sorrow;
	firstcom[2] = sigmoidnode4[0] + sigmoidnode4[1] * joy + sigmoidnode4[2] * fear + sigmoidnode4[3] * disgust + sigmoidnode4[4] * sadness + sigmoidnode4[5] * anger + sigmoidnode4[6] * surprise + sigmoidnode4[7] * contempt + sigmoidnode4[8] * calm + sigmoidnode4[9] * angered + sigmoidnode4[10] * joyful + sigmoidnode4[11] * sorrow;
	firstcom[3] = sigmoidnode5[0] + sigmoidnode5[1] * joy + sigmoidnode5[2] * fear + sigmoidnode5[3] * disgust + sigmoidnode5[4] * sadness + sigmoidnode5[5] * anger + sigmoidnode5[6] * surprise + sigmoidnode5[7] * contempt + sigmoidnode5[8] * calm + sigmoidnode5[9] * angered + sigmoidnode5[10] * joyful + sigmoidnode5[11] * sorrow;
	firstcom[4] = sigmoidnode6[0] + sigmoidnode6[1] * joy + sigmoidnode6[2] * fear + sigmoidnode6[3] * disgust + sigmoidnode6[4] * sadness + sigmoidnode6[5] * anger + sigmoidnode6[6] * surprise + sigmoidnode6[7] * contempt + sigmoidnode6[8] * calm + sigmoidnode6[9] * angered + sigmoidnode6[10] * joyful + sigmoidnode6[11] * sorrow;
	firstcom[5] = sigmoidnode7[0] + sigmoidnode7[1] * joy + sigmoidnode7[2] * fear + sigmoidnode7[3] * disgust + sigmoidnode7[4] * sadness + sigmoidnode7[5] * anger + sigmoidnode7[6] * surprise + sigmoidnode7[7] * contempt + sigmoidnode7[8] * calm + sigmoidnode7[9] * angered + sigmoidnode7[10] * joyful + sigmoidnode7[11] * sorrow;
	double secondcomp[6];
	for (int i = 0; i < 6; i++)
	{
		//secondcomp[i]= ((1 - (exp(-(2 * firstcom[i])))) / (1 + (exp(-(2 * firstcom[i])))));
		//secondcomp[i] = (1 / (1+(exp(-firstcom[i]))));
		secondcomp[i] = tanh(firstcom[i]);
	}
	double successcalc1 = sigmoidnode0[0] + sigmoidnode0[1] * secondcomp[0] + sigmoidnode0[2] * secondcomp[1] + sigmoidnode0[3] * secondcomp[2] + sigmoidnode0[4] * secondcomp[3] + sigmoidnode0[5] * secondcomp[4] + sigmoidnode0[6] * secondcomp[5];
	//double successcalc2 = ((1 - (exp(-(2 * successcalc1)))) / (1 + (exp(-(2 * successcalc1)))));
	//double successcalc2 = (1 / (1 + (exp(-successcalc1))));
	double successcalc2 = tanh(successcalc1);
	double failcalc1 = sigmoidnode1[0] + sigmoidnode1[1] * secondcomp[0] + sigmoidnode1[2] * secondcomp[1] + sigmoidnode1[3] * secondcomp[2] + sigmoidnode1[4] * secondcomp[3] + sigmoidnode1[5] * secondcomp[4] + sigmoidnode1[6] * secondcomp[5];
	//double failcalc2 = ((1 - (exp(-(2 * failcalc1)))) / (1 + (exp(-(2 * failcalc1)))));
	//double failcalc2 = (1 / (1 + (exp(-failcalc1))));
	double failcalc2 = tanh(failcalc1);
	cout<<"SUCCESS: " << successcalc2<<"  FAIL "<< failcalc2 << endl;
	nsucsum = successcalc2 + nsucsum;
	nfaisum = failcalc2 + nfaisum;
}
int main()
{
	d.readSVMtable();
	d.readNNClasstable();
	d.readNNNodetable();
	d.readNBtable();
	d.readJ48table();
	
	int NBSuccess = 0;
	int NBFail = 0;
	string NBfinaldecision;
	int J48Success = 0;
	int J48fail = 0;
	string J48finaldecision;
	int SVMSuccess = 0;
	int SVMfail = 0;
	string SVMfinaldecision;
	int i = 1;
	double joy;
	double fear;
	double disgust;
	double sadness;
	double anger;
	double surprise;
	double contempt;
	double calm;
	double angered;
	double joyful;
	double sorrow;
	string in;
	ifstream sample("C:\\Users\\Lenovo\\Documents\\Visual Studio 2015\\Projects\\ThesisPrototypeCPP\\ThesisPrototypeCPP\\PrototypeTester.csv");
	if (!sample.is_open())
		cout << "Error: File Open" << '\n';
	try {
		while (sample.good())
		{

			getline(sample, in, ',');
			joy = stod(in); in = "";
			getline(sample, in, ',');
			fear = stod(in); in = "";
			getline(sample, in, ',');
			disgust = stod(in); in = "";
			getline(sample, in, ',');
			sadness = stod(in); in = "";
			getline(sample, in, ',');
			anger = stod(in); in = "";
			getline(sample, in, ',');
			surprise = stod(in); in = "";
			getline(sample, in, ',');
			contempt = stod(in); in = "";
			getline(sample, in, ',');
			calm = stod(in); in = "";
			getline(sample, in, ',');
			angered = stod(in); in = "";
			getline(sample, in, ',');
			joyful = stod(in); in = "";
			getline(sample, in, '\n');
			sorrow = stod(in); in = "";
			string dec = SVMdecision(joy, fear, disgust, sadness, anger, surprise, contempt, calm, angered, joyful, sorrow);
			string dec1 = J48decision(joy, fear, disgust, sadness, anger, surprise, contempt, calm, angered, joyful, sorrow);
			string dec2 = NBdecision(joy, fear, disgust, sadness, anger, surprise, contempt, calm, angered, joyful, sorrow);

			cout << i <<". NB: "<<dec2 << " SVM: " << dec << " Value: " << sout << " J48: " << dec1 << " Neural: ";
			NNdecision(joy, fear, disgust, sadness, anger, surprise, contempt, calm, angered, joyful, sorrow);
			if (dec2 == "Success")
				NBSuccess++;
			else
				NBFail++;
			if (dec == "SUCCESS")
				SVMSuccess++;
			else
				SVMfail++;
			if (dec1 == "SUCCESS")
				J48Success++;
			else
				J48fail++;
			i++;

		}
	}
	catch (exception e) {
		sample.close();
	}
	sample.close();
	if (NBSuccess > NBFail)
		NBfinaldecision = "SUCCESS";
	else
		NBfinaldecision = "FAIL";
	if (SVMSuccess > SVMfail)
		SVMfinaldecision = "SUCCESS";
	else
		SVMfinaldecision = "FAIL";
	if (J48Success > J48fail)
		J48finaldecision = "SUCCESS";
	else
		J48finaldecision = "FAIL";
	double nsucmean = nsucsum / 34;
	double nfaimean = nfaisum / 34;
	string NNfinaldecision;
	if (nsucmean > nfaimean)
		NNfinaldecision = "SUCCESS";
	else
		NNfinaldecision = "FAIL";
	cout << "Final Decision: NB: "<<NBfinaldecision <<" SVM: " << SVMfinaldecision << " J48: " << J48finaldecision<<" NN: "<<NNfinaldecision;
	
	//d.readSVMtable();
	d.databaseclose();
	system("PAUSE");
    return 0;
}

