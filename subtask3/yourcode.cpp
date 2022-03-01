#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <filecheck.h>
#include <IO.h>
#include <helper.h>
using namespace std;

typedef struct{
    int label;
    float prob;
}pred_t;

int main(int argc, char **argv)
{
        //Checks if second argument in command line is fully connected, returns an error message otherwise
     
            if (argc != 3)
            {
                cout << "Unfortunately you have put a wrong command."
                     << "\n";
                cout << "The correct command is ./yourcode.out feature.txt out.txt\n";
                return 0;
            }
	   //Extracts filenames for all 4 files from command line arguments
            std::string inputfeaturefile(argv[1]);
            string outputfile(argv[2]);
	    
	    //Checks if the given inputfile exists or not
            if (checkinputfile(inputfeaturefile) == 0)
            {
                cerr << "The inputmatrixfile file unfortunately could not be opened. Please give a valid file"
                     << "\n";
                return 0;
            }
          vector<float> out();
          out=filetovector(inputfeaturefile);
	  string t="";
	for(int i=0;i<250;i++)
	{
		t=t+to_string(out[i])+" ";}
	char* tt= t;
	pred_t* pred;
          extern libaudioAPI(tt,pred);
	 string highest,middle,lowest;
  int inthighest,intmiddle,intlowest;
  float probhighest,probmiddle,problowest;inthighest = *(pred).label;
	probhighest= *(pred).prob;
  intmiddle= *(pred +1).label; probmiddle = *(pred+1).prob ; intlowest = *(pred+2).label; problowest = *(pred+2).prob; 
	ofstream outfile;
	outfile.open("outputfile.txt",std::ios_base::app);
	outfile<<highest<<" "<<middle<<" "<<lowest<<" "<<probhighest<<" "<<robmiddle<<" "<<problowest<<"\n;
  return 0;
  
         
	   
}
