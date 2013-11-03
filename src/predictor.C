// A very stupid predictor.  It will always predict not taken.

void init_predictor () 
{
int LHT[LLHT];            //Local history table.
int GHT[LGHR];            //Global history table
int Bias[SATBITS];        //Bias 


/*
by default we will initalize our history as all branches taken
this assumption is fair since for loops are the most common
conditional branches and the ones that are the most likely taken
*/
for(int i =0; i < LLHT; i++) {
	LHT[i] = 1;
}

for(int i =0; i < LGHR; i++) {
	LGHR[i] = 1;
}

for(int i =0; i < SATBITS; i++) {
	Bias[i] = 1;
}

}

 bool make_prediction (unsigned int pc)
{
  return false;
}

void train_predictor (unsigned int pc, bool outcome)
{
}
