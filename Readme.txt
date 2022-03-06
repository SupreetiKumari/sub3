COP 290-

This is the readme file for COP290 Task1 Subtask3: Hierarchical code design, creating library and API.
Contributed by: Arushi Goyal(2020CS50418) and Supreeti Kumari(2020CS1200396)

OBJECTIVE

Implement a deep neural network (DNN) inference for classifying across 12 audio keywords (silence, unknown, yes, no, up, down, left, right, on, off, stop, go).

FILES DESCRIPTION-

This folder consists of the following files:
1. helper.h : Consists of the fcblas(Openblas implementation of fullyconnected), relu which is used to diand softmax function which is ultimately being used to calulate the probabilites . 
2. IO.h : Facilitates input and output from files to vectors and vice-versa respectively.
3. audio.cpp : Consists of pred_t* structue definition and libaudioAPI function which takes in as input filename and an empty placeholder array. It returns the array . This the file with the help of which we have created our library. This file uses helper.h .
with the 3 highest probabilities among the 12 audio features.
4.yourcode.cpp : The main file which links to the audio library and outputs the top 3 audio keywords with the maximum softmax probability
5.libaudio.so : This is the library that we are creating with the help of audio.cpp.

FUNCTION DESCRIPTION

It executes the functions fcblas,relu and softmax in the order: FCBLAS1 [250x144] -> RELU -> FCBLAS2 [144x144] -> RELU -> FCBLAS3 [144X144] -> 
RELU -> FCBLAS4 [144x12] -> softmax.

We have been given an inputfeaturematrix file . It is a 1x250 vector in row major order. From this we perform fullyconnected(1) which results in a 1x144 matrix, followed by relu which results in a new 1x144 matrix , followed by fullyconnected(2) which results in a new 1x144 matrix , followed by another relu which results in a new 1x144 matrix, followed by another fullyconnected(3) which results in another 1x144 matrix , followed by another relu which results in a new 1x144 matrix, followed by another fullyconnected(4) which results in another 1x12 matrix , finally followed by a softmax which is the final probabiltiy 1x12 matrix.

*libaudioAPI: Takes as input filename of the audiofeatures file and an empty placeholder array. It outputs the array storing the 3 highest softmax probabilities 
among the 12 audio keywords.
*relu: Performs relu operation on a vector of type float.
*softmax: Applies the softmax function on a vector of type float.
*fcblas: Performs the operation A*B+C on inputmatrix A, weightmatrix B and biasmatricx C; returns the outputmatrix in the form of a vector.
NOTE: We have used the Openblas implementation of fullyconnected function.

HOW TO EXECUTE-

First we go to the folder where we have the cpp and header files.
Open the terminal-

1. Set the LD_LIBRARY_PATH-
For example-
export LD_LIBRARY_PATH=/home/arushi/Desktop/subtask3/audio:$LD_LIBRARY_PATH

2. Set the MKL_BLAS_PATH
For example-
export MKL_BLAS_PATH=/home/arushi/Desktop/subtask3:$MKL_BLAS_PATH

3. Run the make file by executing the command 'make' .

4. To remove the .out files, execute the command 'make clean' .

5. Finally to get the oupute in output.txt file run-
./yourcode.out inputfile.txt output.txt . 






