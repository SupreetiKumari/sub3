void relu(vector<float> vec){
    
    vector<float> output();
    //relu function is defined as relu(x)=max(x,0)
    for(auto x:vec){
    if(x>0){
    output.push_back(x);}
    else{
    output.push_back(0);}}
    return;
}


void softmax(string fileinput,string fileoutput){
    ifstream file1 (fileinput);
    string line;
    int n;
    //Checks if the input file exists
    //If not found, displays an error message
    if(!file1.is_open()){
         cout<<"File containing inputvector cannot be opened."<<"\n";
         return;
    }
    getline(file1,line);
    n=stoi(line);
    int i;
    float sum=0;
    float inputvector[n];
        for(i=0;i<n;i++)
            {
                getline(file1,line);
                inputvector[i]=stof(line);
                //Calculates sum of e^x values of all elements of entire vector
                sum+=exp(stof(line));
            }
    file1.close();
    float outputvector[n];
    for(i=0;i<n;i++){
        //softmax function is defined as softmax(x)=(e^x/sum of e^x values of all elements of entire vector)
        float x=exp(inputvector[i]);
        outputvector[i]=(x/sum);
    }
    ofstream file2(fileoutput);
    file2<<n<<"\n";
    for(i=0;i<n;i++){
        file2<<outputvector[i]<<"\n";
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
