//Program for generating and reading input data for Project 1
// by Prof. Murali Subbarao, ESE 344

#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <fstream>
#include <vector>
using namespace std;

//Program for generating input data for Project 1
// by Prof. Murali Subbarao, ESE 344

// generate random data for a 3d tensor
void data3d(int s1, int s2, int s3) {
	srand((unsigned int)time(NULL));// seed rand() with system time
	//Generating input for project 1
	for (int i3 = 0; i3 < s3; i3++) {
		for (int i2 = 0; i2 < s2; i2++) {
			for (int i1 = 0; i1 < s1; i1++) {
				cout << (double)((rand() % 100) / 100.0) << "   ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

// generate random data for a 2d tensor
void data2d(int s1, int s2) {
	srand((unsigned int)time(NULL));// seed rand() with system time
	//Generating input for project 1
	for (int i2 = 0; i2 < s2; i2++) {
		for (int i1 = 0; i1 < s1; i1++) {
			cout << (double)((rand() % 100) / 100.0) << "   ";
		}
		cout << endl;
	}
	cout << endl << endl;
}


// generate random data for a 4d tensor
void data4d(int s1, int s2, int s3, int s4) {

	srand((unsigned int)time(NULL));// seed rand() with system time

	//Generating input for project 1
	for (int i4 = 0; i4 < s4; i4++) {
		for (int i3 = 0; i3 < s3; i3++) {
			for (int i2 = 0; i2 < s2; i2++) {
				for (int i1 = 0; i1 < s1; i1++) {
					cout << (double)((rand() % 100) / 100.0) << "   ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

// generate random data for a 1d vector
void data1d(int s1) {
	srand((unsigned int)time(NULL));// seed rand() with system time
	//Generating input for project 1
	for (int i1 = 0; i1 < s1; i1++) {
		cout << (double)((rand() % 100) / 100.0) << "   ";
	}
	cout << endl << endl;
}


// allocate memory for a 1d vector
void alloc1d(vector<double>& tn1d, int s1) {
	// allocate memory for a 1d tensor tn1d of size s1
	tn1d.resize(s1);
}

// read data for a 1d tensor
void read1d(vector<double>& tn1d, int s1, istream& input_file) {
	for (int i1 = 0; i1 < s1; i1++)
	{
		input_file >> tn1d[i1];
	}
}
// print data for a 1d tensor
void print1d(vector<double>& tn1d, int s1) {
	cout << endl << endl;
	for (int i1 = 0; i1 < s1; i1++)
	{
		cout << tn1d[i1] << "   ";
	}
	cout << endl << endl;
}

// allocate memory for a 2d tensor
void alloc2d(vector<vector<double>>& tn2d, int s1, int s2) {
	// allocate memory for a 2d tensor tn2d of size s1, s2
	tn2d.resize(s1);
	for (int i1 = 0; i1 < s1; i1++) {
		tn2d[i1].resize(s2);
	}
}

// read data for a 2d tensor
void read2d(vector<vector<double>>& tn2d, int s1, int s2, istream& input_file) {

	for (int i2 = 0; i2 < s2; i2++) {
		for (int i1 = 0; i1 < s1; i1++)
		{
			input_file >> tn2d[i1][i2];
		}
	}
}

// print data for a 2d tensor
void print2d(vector<vector<double>>& tn2d, int s1, int s2) {
	cout << endl << endl;
	for (int i2 = 0; i2 < s2; i2++) {
		for (int i1 = 0; i1 < s1; i1++)
		{
			cout << tn2d[i1][i2] << "   ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

// allocate memory for a 3d tensor
void alloc3d(vector<vector<vector<double>>>& tn3d, int s1, int s2, int s3) {
	// allocate memory for a 3d tensor tn3d of size s1, s2, s3
	tn3d.resize(s1);
	for (int i1 = 0; i1 < s1; i1++) {
		tn3d[i1].resize(s2);
		for (int i2 = 0; i2 < s2; i2++) {
			tn3d[i1][i2].resize(s3);
		}
	}
}

// read data for a 3d tensor
void read3d(vector<vector<vector<double>>>& tn3d, int s1, int s2, int s3, istream& input_file) {
	for (int i3 = 0; i3 < s3; i3++) {
		for (int i2 = 0; i2 < s2; i2++) {
			for (int i1 = 0; i1 < s1; i1++)
			{
				input_file >> tn3d[i1][i2][i3];
			}
		}
	}
}

// print data for a 3d tensor
void print3d(vector<vector<vector<double>>>& tn3d, int s1, int s2, int s3) {
	cout << endl << endl;
	for (int i3 = 0; i3 < s3; i3++) {
		for (int i2 = 0; i2 < s2; i2++) {
			for (int i1 = 0; i1 < s1; i1++)
			{
				cout << tn3d[i1][i2][i3] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

// allocate memory for a 4d tensor tn4d of size s1, s2, s3, s4
void alloc4d(vector<vector<vector<vector<double>>>>& tn4d, int s1, int s2, int s3, int s4) {

	tn4d.resize(s1);

	for (int i1 = 0; i1 < s1; i1++) {
		tn4d[i1].resize(s2);
		for (int i2 = 0; i2 < s2; i2++) {
			tn4d[i1][i2].resize(s3);
			for (int i3 = 0; i3 < s3; i3++)
			{
				tn4d[i1][i2][i3].resize(s4);
			}
		}
	}
}

// read a 4d tensor tn4d of size s1, s2, s3, s4
void read4d(vector<vector<vector<vector<double>>>>& tn4d, int s1, int s2, int s3, int s4, istream& input_file) {

	for (int i4 = 0; i4 < s4; i4++) {
		for (int i3 = 0; i3 < s3; i3++) {
			for (int i2 = 0; i2 < s2; i2++) {
				for (int i1 = 0; i1 < s1; i1++) {
					input_file >> tn4d[i1][i2][i3][i4];
				}
			}
		}
	}
}

// print a 4d tensor tn4d of size s1, s2, s3, s4
void print4d(vector<vector<vector<vector<double>>>>& tn4d, int s1, int s2, int s3, int s4) {
	cout << endl << endl;
	for (int i4 = 0; i4 < s4; i4++) {
		for (int i3 = 0; i3 < s3; i3++) {
			for (int i2 = 0; i2 < s2; i2++) {
				for (int i1 = 0; i1 < s1; i1++) {
					cout << tn4d[i1][i2][i3][i4] << "   ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

double max(double maxParam1, double maxParam2, double maxParam3, double maxParam4) {
	vector<double> maxParamValues;
	maxParamValues.push_back(maxParam1);
	maxParamValues.push_back(maxParam2);
	maxParamValues.push_back(maxParam3);
	maxParamValues.push_back(maxParam4);

	double actualMax = -DBL_MAX;

	for (int i = 0; i < maxParamValues.size(); i++) {
		if (actualMax < maxParamValues.at(i)) {
			actualMax = maxParamValues.at(i);
		}
	}
	return actualMax;
}

void maxPooling(vector<vector<vector<double>>>& mpInput, vector<vector<vector<double>>>& mpOutput, int maxPoolingStride) {
	int maxPoolM = mpInput.size(), maxPoolN = mpInput[0].size();
	int maxPoolI = mpOutput.size(), maxPoolJ = mpOutput[0].size();
	int maxPoolK = mpOutput[0][0].size();
	int maxPoolStride = maxPoolingStride;
	int i, j, k, m, n;
	for (k = 0; k < maxPoolK; k++) {  // for each cross section k
		for (m = 0, i = 0; m < maxPoolM; m += maxPoolStride, i++) { //for row m
			for (n = 0, j = 0; n < maxPoolN; n += maxPoolStride, j++) { // for column n
				mpOutput[i][j][k] = max(mpInput[m][n][k], mpInput[m + 1][n][k], mpInput[m][n + 1][k], mpInput[m + 1][n + 1][k]);
			}
		}
	}
}

void reLU(vector<vector<vector<double>>>& mpInput, vector<vector<vector<double>>>& mpOutput) {
	for (int i = 0; i < mpInput.size(); i++) {
		for (int j = 0; j < mpInput[0].size(); j++) {
			for (int k = 0; k < mpInput[0][0].size(); k++) {
//				mpOutput[i][j][k] = mpInput[i][j][k];
				if (mpInput[i][j][k] <= 0) {
					mpOutput[i][j][k] = 0.0;
				}
				else {
					mpOutput[i][j][k] = mpInput[i][j][k];
				}
			}
		}
	}
}

void dotProduct(vector<vector<vector<vector<double>>>>& dpParam_4D, vector<vector<vector<double>>>& dpParam_3D, vector<double>& dpResult, vector<double>& dpBias) {
	
	int tn4s1 = dpParam_3D.size(), tn4s2 = dpParam_3D[0].size(), tn4s3 = dpParam_3D[0][0].size(); 
	int tn4s4 = 10;
//	int tn4s4 = dpParam_4D[0][0][0].size();				// Or this is valid as well!

	// tn4 => 4D => D18
	// tn1 => 3D => D16

	for (int tn4i4 = 0; tn4i4 < tn4s4; tn4i4++) {
		// note tn1s1=tn4s1 tn1s2=tn4s2, tn1s3=tn4s3
		double tmpsum = 0.0;
		for (int tn4i3 = 0; tn4i3 < tn4s3; tn4i3++) {
			for (int tn4i1 = 0; tn4i1 < tn4s1; tn4i1++) {
				for (int tn4i2 = 0; tn4i2 < tn4s2; tn4i2++) {
					tmpsum += dpParam_4D[tn4i1][tn4i2][tn4i3][tn4i4] * dpParam_3D[tn4i1][tn4i2][tn4i3];
				}
			}
		}
		dpResult[tn4i4] = tmpsum + dpBias[tn4i4];
	}

}

void normalize(vector<double>& almostOutput ) {
	double tmpsum = 0.0;
	// output.size() => can be replaced with 10
	for (int i = 0; i < almostOutput.size(); i++) {
		tmpsum += (almostOutput[i] * almostOutput[i]);
	}
	tmpsum = sqrt(tmpsum);
	for (int i = 0; i < almostOutput.size(); i++) {
		almostOutput[i] /= tmpsum;
	}
}

void softmax(vector<double>& almostOutput, vector<double>& output) {
	double tmpsum = 0.0;
	// output.size() => can be replaced with 10
	for (int i = 0; i < almostOutput.size(); i++) {
		tmpsum += (exp(almostOutput[i]));
	}

	cout << "Softmax probabilities : " << endl;
	for (int i = 0; i < almostOutput.size(); i++) {
		almostOutput[i] = (exp(almostOutput[i])) / tmpsum;
		output[i] = almostOutput[i];
	}
}

void printFinalOutput(vector<double>& output) {
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << "   ";
	}
}

int main()
{
	ifstream input_file;							// CNN Weights and convolutions
	ifstream input_image;							// Test image as a text file
	input_file.open("CNN_weights.txt");
	input_image.open("Test_image.txt");

	/*
	  //   Part 1 is to generate data.
	  //   Part 2 is to read and print data.

	  // Part 1: Generate input data for project 1

		  data3d(32, 32, 3); //D1
		  data4d(5, 5, 3, 16); //D3
		  data1d(16); //D4
		  data4d(5, 5, 16, 20); //D8
		  data1d(20); //D9
		  data4d(5, 5, 20,20);  //D13
		  data1d(20); //D14
		  data4d(4,4,20,10); //D18
		  data1d(10);  //D19

	  //	cout << endl << "Enter any char to continue : ";
	  //	cin >> c;

	  */

	  // Comment this part when generating input data

	  //Part 2:  Allocate memory and,  Read and print input data generated above
	vector<vector<vector<double>>> D1, D2, D5, D6, D7, D10, D11, D12, D15, D16;
	vector<vector<vector<vector<double>>>> D3, D8, D13, D18;
	vector<double> D4, D9, D14, D19, D17, D20;


	//////////////////////////////////////////////////// Stage 1: Input /////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////// Layer L1: input layer //////////////////////////////////////////////////////////////////////////////////
	
	// D1 <- this should be image thats loaded
	cout << endl << "D1: 32x32x3";
	alloc3d(D1, 32, 32, 3);
	// M1 <- Method to read input_image and initialize input layer in 1a
	read3d(D1, 32, 32, 3, input_image);	
	// Prints D1
	print3d(D1, 32, 32, 3);


	///////////////////////////////////////// Stage 2: First Conv + ReLU + Max pool /////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////// Layer L2: Convolution, Stride = 1 ///////////////////////////////////////////////////////////////////////////

	cout << endl << "D2: 32x32x16";
	// D2 <- 3D array of floating point numbers to store output of L2
	alloc3d(D2, 32, 32, 16);

	cout << endl << "D3: 5x5x3x16";
	// D3 <- 4D array to store 16 convolution filters with zero padding (in file)
	alloc4d(D3, 5, 5, 3, 16);
	// M2 <- Method to read input_file and initialize D3
	read4d(D3, 5, 5, 3, 16, input_file); //D3
	// Prints D3
	print4d(D3, 5, 5, 3, 16); //D3

	cout << endl << "D4: 1x16";
	// D4 <- 1D array to store bias vector (in file)
	alloc1d(D4, 16);
	// M3 <- Method to read input_file and initialize D4
	read1d(D4, 16, input_file);
	// Prints D4
	print1d(D4, 16);

	// M4 <- Convolve D1 and D3 together, added with D4, and storing the result into D4 (stride = 1)
	// tn1 <= D1 (3D)
	// tn3 <= D2 (4D)
	// tn2 <= D3 (3D)
	// tn4 <= D4 (1D)
	
		// "Convolve" tn1 with tn2 with stride 2 to obtain tn3
	int convStride1 = 1;
	// tn1
	int tn1s1 = D1.size(), tn1s2 = D1[0].size(), tn1s3 = D1[0][0].size();
	// tn3
	int tn2s1 = D3.size(), tn2s2 = D3[0].size(), tn2s3 = tn1s3, tn2s4 = D3[0][0][0].size();
	int tn2s1by2 = tn2s1 / 2;	// 2
	int tn2s2by2 = tn2s2 / 2;	// 2
	int tn3s1 = tn1s1 / convStride1, tn3s2 = tn1s2 / convStride1, tn3s3 = tn2s4;
	int tn4s1 = tn1s1, tn4s2 = tn1s2, tn4s3 = tn1s3, tn4s4 = 10;

	// First Convolution
	cout << "Output of First Convolution layer: tn3" << endl;
	for (int tn2i4 = 0, tn3i3 = 0; tn2i4 < tn2s4; tn2i4++, tn3i3++) {
		for (int tn1i1 = 0, tn3i1 = 0; tn1i1 < tn1s1; tn1i1 += convStride1, tn3i1++) {
			for (int tn1i2 = 0, tn3i2 = 0; tn1i2 < tn1s2; tn1i2 += convStride1, tn3i2++) {
				double tmpsum = 0.0;
				for (int tn2i3 = 0; tn2i3 < tn2s3; tn2i3++) {
					// note tn1s3=tn2s3
					for (int tn2i1 = -tn2s1by2; tn2i1 <= tn2s1by2; tn2i1++) {
						for (int tn2i2 = -tn2s2by2; tn2i2 <= tn2s2by2; tn2i2++) {
							if (((tn1i1 + tn2i1) >= 0) && ((tn1i1 + tn2i1) < tn1s1) && ((tn1i2 + tn2i2) >= 0) && ((tn1i2 + tn2i2) < tn1s1)) { // zero padding of tn1
								tmpsum += D3[tn2i1 + tn2s1by2][tn2i2 + tn2s2by2][tn2i3][tn2i4] * D1[tn1i1 + tn2i1][tn1i2 + tn2i2][tn2i3];
							}
						}
					}
				}
				D2[tn3i1][tn3i2][tn3i3] = tmpsum + D4[tn3i3];
				cout << D2[tn3i1][tn3i2][tn3i3] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}


	/////////////////////////////////////////// Layer L3: ReLU Activation Function //////////////////////////////////////////////////////////////////////////

	cout << endl << "D5: 32x32x16";
	// D5 <- Stores output from M5 for layer L3
	alloc3d(D5, 32, 32, 16);
	// M5 <- Computing D5 using D2: Z = max(0, x)
	reLU(D2, D5);
	// Prints D5
	print3d(D5, 32, 32, 16);


	////////////////////////////////// Layer L4: Maxpooling: Filter Size 2x2, Stride = 2 /////////////////////////////////////////////////////////////////
	
	cout << endl << "D6: 16x16x16";
	// D6 <- Stores output from M6 for layer L4
	alloc3d(D6, 16, 16, 16);
	// M6 <- Does the maxpooling of D5 with a filter size of 2x2 and a stride of 2
	maxPooling(D5, D6, 2);
	// Prints D6
	print3d(D6, 16, 16, 16);


	///////////////////////////////////////// Stage 3: Second Conv + ReLU + Max pool ////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////// Layer L5: Convolution, Stride = 1 ///////////////////////////////////////////////////////////////////////////

	cout << endl << "D7: 16x16x20";
	// D7 <- Stores output of layer L5
	alloc3d(D7, 16, 16, 20);

	cout << endl << "D8: 5x5x16x20";
	// D8 <- Stores 20 convolution filters with zero padding from input_file (in file)
	alloc4d(D8, 5, 5, 16, 20);
	// M7 <- Reads from input_file and initializes D8
	read4d(D8, 5, 5, 16, 20, input_file); //D8
	// Prints D8
	print4d(D8, 5, 5, 16, 20); //D8

	cout << endl << "D9: 1x20";
	// D9 <- Stores bias vector from input_file (in file)
	alloc1d(D9, 20);
	// M8 <- Reads from input_file and initializes D9
	read1d(D9, 20, input_file); 
	// Prints D9
	print1d(D9, 20); 

	// M9 <- Convolve D6 and D8 together, added with D9, and storing the result into D7 (stride = 1)
	int convStride2 = 1;
	// tn1
	tn1s1 = D6.size(), tn1s2 = D6[0].size(), tn1s3 = D6[0][0].size();
	// tn3
	tn2s1 = D8.size(), tn2s2 = D8[0].size(), tn2s3 = tn1s3, tn2s4 = D8[0][0][0].size();
	tn2s1by2 = tn2s1 / 2;	// 2
	tn2s2by2 = tn2s2 / 2;	// 2
	tn3s1 = tn1s1 / convStride1, tn3s2 = tn1s2 / convStride1, tn3s3 = tn2s4;
	tn4s1 = tn1s1, tn4s2 = tn1s2, tn4s3 = tn1s3, tn4s4 = 10;

	// Second Convolution
	cout << "Output of Second Convolution layer: tn3" << endl;
	for (int tn2i4 = 0, tn3i3 = 0; tn2i4 < tn2s4; tn2i4++, tn3i3++) {
		for (int tn1i1 = 0, tn3i1 = 0; tn1i1 < tn1s1; tn1i1 += convStride2, tn3i1++) {
			for (int tn1i2 = 0, tn3i2 = 0; tn1i2 < tn1s2; tn1i2 += convStride2, tn3i2++) {
				double tmpsum = 0.0;
				for (int tn2i3 = 0; tn2i3 < tn2s3; tn2i3++) {
					// note tn1s3=tn2s3
					for (int tn2i1 = -tn2s1by2; tn2i1 <= tn2s1by2; tn2i1++) {
						for (int tn2i2 = -tn2s2by2; tn2i2 <= tn2s2by2; tn2i2++) {
							if (((tn1i1 + tn2i1) >= 0) && ((tn1i1 + tn2i1) < tn1s1) && ((tn1i2 + tn2i2) >= 0) && ((tn1i2 + tn2i2) < tn1s1)) { // zero padding of tn1
								tmpsum += D8[tn2i1 + tn2s1by2][tn2i2 + tn2s2by2][tn2i3][tn2i4] * D6[tn1i1 + tn2i1][tn1i2 + tn2i2][tn2i3];
							}
						}
					}
				}
				D7[tn3i1][tn3i2][tn3i3] = tmpsum + D9[tn3i3];
				cout << D7[tn3i1][tn3i2][tn3i3] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}


	//////////////////////////////////////// Layer L6: ReLU Activation Function //////////////////////////////////////////////////////////////////////////
	
	cout << endl << "D10: 16x16x20";
	// D10 <- Storing the output for the layer L6
	alloc3d(D10, 16, 16, 20);
	// M10 <- Computes and stores D10 using D7: Z = max(0, x)
	reLU(D7, D10);
	// Prints D10
	print3d(D10, 16, 16, 20);


	////////////////////////////////// Layer L7: Maxpooling: Filter Size 2x2, Stride = 2 /////////////////////////////////////////////////////////////////

	cout << endl << "D11: 8x8x20";
	// D11 <- Storing the output of layer L7
	alloc3d(D11, 8, 8, 20);
	// M11 <- Does the maxpooling of D10 with a filter size of 2x2 and a stride of 2
	maxPooling(D10, D11, 2);
	// Prints D11
	print3d(D11, 8, 8, 20);


	///////////////////////////////////////// Stage 4: Third Conv + ReLU + Max pool /////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////// Layer L8: Convolution, Stride = 1 ////////////////////////////////////////////////////////////////////////////

	cout << endl << "D12: 8x8x20";
	// D12 <- Stores the output of layer L8
	alloc3d(D12, 8, 8, 20);

	cout << endl << "D13: 5x5x20x20";
	// D13 <- Stores the 20 convolution filters with zero padding from input_file (in file)
	alloc4d(D13, 5, 5, 20, 20);
	// M12 <- Reads the convolution filers from input_file and stores them into D13
	read4d(D13, 5, 5, 20, 20, input_file); 
	// Prints D13
	print4d(D13, 5, 5, 20, 20); 

	cout << endl << "D14: 1x20";
	// D14 <- Stores the bias vector (in file)
	alloc1d(D14, 20);
	// M13 <- Reads the bias vector from input_file and stores it into D14
	read1d(D14, 20, input_file); 
	// Prints D14
	print1d(D14, 20); 	

	// M9 <- Convolve D11 and D13 together, added with D14, and storing the result into D12 (stride = 1)
	int convStride3 = 1;
	// tn1
	tn1s1 = D11.size(), tn1s2 = D11[0].size(), tn1s3 = D11[0][0].size();
	// tn3
	tn2s1 = D13.size(), tn2s2 = D13[0].size(), tn2s3 = tn1s3, tn2s4 = D13[0][0][0].size();
	tn2s1by2 = tn2s1 / 2;	// 2
	tn2s2by2 = tn2s2 / 2;	// 2
	tn3s1 = tn1s1 / convStride1, tn3s2 = tn1s2 / convStride1, tn3s3 = tn2s4;
	tn4s1 = tn1s1, tn4s2 = tn1s2, tn4s3 = tn1s3, tn4s4 = 10;

	// Third Convolution
	cout << "Output of Third Convolution layer: tn3" << endl;
	for (int tn2i4 = 0, tn3i3 = 0; tn2i4 < tn2s4; tn2i4++, tn3i3++) {
		for (int tn1i1 = 0, tn3i1 = 0; tn1i1 < tn1s1; tn1i1 += convStride3, tn3i1++) {
			for (int tn1i2 = 0, tn3i2 = 0; tn1i2 < tn1s2; tn1i2 += convStride3, tn3i2++) {
				double tmpsum = 0.0;
				for (int tn2i3 = 0; tn2i3 < tn2s3; tn2i3++) {
					// note tn1s3=tn2s3
					for (int tn2i1 = -tn2s1by2; tn2i1 <= tn2s1by2; tn2i1++) {
						for (int tn2i2 = -tn2s2by2; tn2i2 <= tn2s2by2; tn2i2++) {
							if (((tn1i1 + tn2i1) >= 0) && ((tn1i1 + tn2i1) < tn1s1) && ((tn1i2 + tn2i2) >= 0) && ((tn1i2 + tn2i2) < tn1s1)) { // zero padding of tn1
								tmpsum += D13[tn2i1 + tn2s1by2][tn2i2 + tn2s2by2][tn2i3][tn2i4] * D11[tn1i1 + tn2i1][tn1i2 + tn2i2][tn2i3];
							}
						}
					}
				}
				D12[tn3i1][tn3i2][tn3i3] = tmpsum + D14[tn3i3];
				cout << D12[tn3i1][tn3i2][tn3i3] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}


	//////////////////////////////////////// Layer L9: ReLU Activation Function //////////////////////////////////////////////////////////////////////////
	cout << endl << "D15: 8x8x20";
	// D15 <- Stores the output of layer L9
	alloc3d(D15, 8, 8, 20);
	// M15 <- Computes and stores D15 using D12: Z = max(0, x)
	reLU(D12, D15);
	// Prints D15
	print3d(D15, 8, 8, 20);


	///////////////////////////////// Layer L10: Maxpooling: Filter Size 2x2, Stride = 2 /////////////////////////////////////////////////////////////////
	cout << endl << "D16: 4x4x20";
	// D16 <- Stores the output of layer L10
	alloc3d(D16, 4, 4, 20);
	// M16 <- Does the maxpooling of D15 with a filter size of 2x2 and a stride of 2
	maxPooling(D15, D16, 2);
	// Prints D16
	print3d(D16, 4, 4, 20);


	/////////////////////////////////// Stage 5: Last Layer: Fully Connected + Softmax ///////////////////////////////////////////////////////////////////
	//////////////////////////////////////// Layer L11: Fully Connected Layer ////////////////////////////////////////////////////////////////////////////

	cout << endl << "D17: 1x10";
	// D17 <- Stores the output of layer L11
	alloc1d(D17, 10);

	cout << endl << "D18: 4x4x20x10";
	// D18 <- Stores 10 full connection filters (dot product) (in file)
	alloc4d(D18, 4, 4, 20, 10);
	// M17 <- Reads 10 full connection filters from input_file to initialize D18 
	read4d(D18, 4, 4, 20, 10, input_file); 
	// Prints D18
	print4d(D18, 4, 4, 20, 10); 

	cout << endl << "D19: 1x10";
	// D19 <- Stores the bias vector (in file)
	alloc1d(D19, 10);
	// M18 <- Reads the bias vector from input_file to initialize D19
	read1d(D19, 10, input_file); 
	// Print D19
	print1d(D19, 10); 	

	// M19 <- Computing D17 by taking the dot-product of D16 with 10 different 4x4x20 filters stored in D18, then storing the output to D17
	dotProduct(D18, D16, D17, D19);


	/////////////////////////////////////////////////// Layer L12: Softmax Layer ////////////////////////////////////////////////////////////////////////////

	// D20 <- Stores the output of layer L12
	alloc1d(D20, 10);
	// M20 <- Normalizing contents of D17 before softmaxing
	normalize(D17);
	// M21 <- Softmaxing D17 and storing the results into D20
	softmax(D17, D20);
	// M22 <- Prints the output of the whole CNN (Prints D20)
	printFinalOutput(D20);

	cout << endl << "All printed." << endl;
	return 0;
}