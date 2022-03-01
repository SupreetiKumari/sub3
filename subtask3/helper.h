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
void openblas(vector<float> input,vector<float> weight, vector<float> bias,vector<float> output, int a, int b,int c){
                int k=0;   
                cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                a, c, b, 1.0, input, b, weight, c, 0.0, output, c);
                for(k=0;k<a*c;k++){                    
                 output[k]+=bias[k];
                 }  
                }
