// A very stupid predictor.  It will always predict not taken.
#include <math.h>

#define HBSIZE 256

void init_predictor () 
{

//history buffer and pattern history table

int PHTSIZE = pow(HBSIZE,2)-1;
int PHT[PHTSIZE]; 
int HB[HBSIZE];


//initialize History buffer to be all not taken
for(int i =0; i < HBSIZE; i++) {
	HB[i] = 0;
}

//initialize Pattern History table to strongly not taken
for(int i = 0; i < PHTSIZE; i++ ) {
	PHT[i] = 0;
}

}


 bool make_prediction (unsigned int pc)
{
  /*
  0 strongly not taken
  1 weakly not taken
  2 weakly taken
  3 strongly taken
  */
  if (PHT[pc] > 1) {
  	return true;
  }
  else {
  	return false;
  }
}

void train_predictor (unsigned int pc, bool outcome)
{
	//still need to a find a way to shift the outcome into the rightmost part of the HB
	PHT[HB[index]];
	index = pc ^ HB;


	//take care of saturing counters
	if(PHT[index] == 3 && outcome == 1) {
		return;
	}

	else if(PHT[index] == 0 && outcome == 0) {
		return;
	}


	else if(outcome == 1) {
		PHT[index]++;
		return;
	}

	else if(outcome == 0) {
		PHT[index]--;
		return;
	}

	else {
		return;
	}

}
