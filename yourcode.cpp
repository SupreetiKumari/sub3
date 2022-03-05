#include <vector>
#include <math.h>
#include <string>
#include <map>
#include <fstream>
#include "helper.h"
using namespace std;

typedef struct{
int label;
float prob;
}pred_t;
 extern pred_t* libaudioAPI(const char* audiofeatures,pred_t* pred);

int main(int argc, char **argv)
{

map<int,string> m{
	{0,"_silence_"},
	{1,"_unknown_"},
	{2,"yes"},
	{3,"no"},
	{4,"up"},
	{5,"down"},
	{6,"left"},
	{7,"right"},
	{8,"on"},
	{9,"off"},
	{10,"stop"},
	{11,"go"},};
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
            pred_t pred1[3];
            pred1[0].label=0;pred1[0].prob=0.0;
            pred1[1].label=0;pred1[1].prob=0.0;pred1[2].label=0;pred1[2].prob=0.0;
	pred_t* pred =  pred1;
	const char* inp = inputfeaturefile.c_str();
	
          libaudioAPI(inp,pred);
	 string highest,middle,lowest;
  float probhighest,probmiddle,problowest;
  int inthighest = (pred[0]).label;
	probhighest= (pred[0]).prob;
 int  intmiddle= (pred[1]).label;
  probmiddle = (pred[1]).prob ;
  int  intlowest = (pred[2]).label; problowest = (pred[2]).prob;
	highest=m[inthighest];middle=m[intmiddle];lowest=m[intlowest];
	ofstream outfile;
	outfile.open("outputfile.txt",std::ios_base::app);
	
	outfile<<inputfeaturefile<<" "<<highest<<" "<<middle<<" "<<lowest<<" "<<probhighest<<" "<<probmiddle<<" "<<problowest<<"\n";
  return 0;
  
         
	   
}
         
	   

