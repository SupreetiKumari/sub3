#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cblas.h>
#include "IO.h"

void relu(vector<float>& vec){
    int i=0;
    //relu function is defined as relu(x)=max(x,0)
    for(auto x:vec){
    if(x>0){
    vec[i++]=x;}
    else{
    vec[i++]=0;}}
    return;
}


void softmax(vector<float>& v){
    float sum=0;int n=v.size();
      for (int i=0;i<n;i++)
            {
                //Calculates sum of e^x values of all elements of entire vector
                sum+=exp(v[i]);
            }
    for(int i=0;i<n;i++)
    {
        //softmax function is defined as softmax(x)=(e^x/sum of e^x values of all elements of entire vector)
        float x=exp(v[i]);
        v[i]=(x/sum);
    }
    return;
}
vector<float> fcblas(vector<float> input,vector<float> weight, vector<float> bias, int a, int b,int c){
    //Conversion of input,weight and bias vectors into arrays
                int k=0,i;
                int n=input.size();
                float input1[n];
                for( i=0;i<n;i++)
                {
                input1[i]=input[i];}
                n=weight.size();
                float weight1[n];
                for(i=0;i<n;i++)
                {
                weight1[i]=weight[i];}
                float output1[a*c];
                
                 n=bias.size();
                float bias1[n];
                for(i=0;i<n;i++)
                {
                bias1[i]=bias[i];}
                //output1=input1*weight1
                cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                a, c, b, 1.0, input1, b, weight1, c, 0.0, output1, c);
                for(k=0;k<a*c;k++){                    
                 output1[k]+=bias1[k];
                 }  
                vector<float>output;
                //Returning output in the form of vector
                for(i=0;i<a*c;i++){
                output.push_back(output1[i]);
                
                } return output;
                }
                
                
                
                
         
