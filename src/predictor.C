#include <math.h>

//size of history buffer
#define HBSIZE 32

//size of Pattern history table
#define PHTSIZE 4294967295 //2^HBSIZE - 1

extern unsigned int PHT[PHTSIZE]; 

extern unsigned int HB;

void init_predictor () 

{

//initialize History buffer to be all not taken
HB = 0;

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
	//cant xor an unsigned array of size 256 with a pc need to fix this issue
	unsigned int index = pc ^ HB;
	

	//update HB when new outcome is observed
	//take care of saturing counters
	//left shift, add a 0 in the end by default
	if(PHT[index] == 3 && outcome == 1) {
		HB = HB << 1;
		HB++;
		return;

	}

	else if(PHT[index] == 0 && outcome == 0) {
		HB = HB << 1;
		return;
	}


	else if(outcome == 1) {
		PHT[index]++;
		HB = HB << 1;
		HB++;
		return;
	}

	else if(outcome == 0) {
		HB = HB << 1;
		PHT[index]--;
		return;
	}

	else {
		return;
	}

}
