#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cblas.h>
#include "filecheck.h"
#include "IO.h"

void relu(vector<float> vec){
    int i=0;
    //relu function is defined as relu(x)=max(x,0)
    for(auto x:vec){
    if(x>0){
    vec[i++]=x;}
    else{
    vec[i++]=0;}}
    return;
}


void softmax(vector<float> v){
    float sum=0;
        for(auto i=v.begin();i!=v.end();i++)
            {
                //Calculates sum of e^x values of all elements of entire vector
                sum+=exp(v[i]);
            }
    for(auto j=v.begin();j!=v.end();j++){
        //softmax function is defined as softmax(x)=(e^x/sum of e^x values of all elements of entire vector)
        float x=exp(v[i]);
        v[i]=(x/sum);
    }
    return;
}

                co1=column(inputmatrixfile);
                row1=row(inputmatrixfile);
		//1D array inputmatrix1 is stored
                filetovector(inputmatrixfile,inputmatrix1); 
		//Column and row number for weightmatrix    
                co2=column(weightmatrixfile);
                row2=row(weightmatrixfile);
		//1D array weightmatrix is stored   
                filetovector(weightmatrixfile,weightmatrix1);  
		//Column and row number for biasmatrix
                co3=column(biasmatrixfile);
                row3=row(biasmatrixfile);
                int k=0;   
		//1D aaray biasmatrix is stored
                filetovector(biasmatrixfile,biasmatrix1);
		//Sets outputmatrix=inputmatrix*weightmatrix
                cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans,
                row1, co2, co1, 1.0, inputmatrix1, row1, weightmatrix1, co1, 0.0, outputmatrix1, row1);
                for(k=0;k<row1*co2;k++){                    
                 outputmatrix1[k]+=biasmatrix1[k];
                 }  
                vectortofile(outputmatrixfile,outputmatrix1,row1,co2);
