COP 290

This is the readme file for COP290 Task1 Subtask3: Hierarchical code design, creating library and API.
Contributed by: Arushi Goyal(2020CS50418) and Supreeti Kumari(2020CS1200396)

Objective: Implement a deep neural network (DNN) inference for classifying across 12 audio keywords (silence, unknown, yes, no, up, down, left, right, on, off, stop, go).

This folder consists of the following files:
1. helper.h : Consists of the fcblas(Openblas implementation of fullyconnected), relu and softmax function definitions.
2. filecheck.h : Checks if the input audiofeatures file exists or not.
3. IO.h : Facilitates input and output from files to vectors and vice-versa respectively.
4. audio.cpp : Consists of pred_t* structue definition and libaudioAPI function which takes in as input filename and an empty placeholder array. It returns the array 
with the 3 highest probabilities among the 12 audio features.
5.yourcode.cpp : The main file which links to the audio library and outputs the top 3 audio keywords with the maximum softmax probability

Function description:

*libaudioAPI: Takes as input filename of the audiofeatures file and an empty placeholder array. It outputs the array storing the 3 highest softmax probabilities 
among the 12 audio keywords.
It executes the functions fcblas,relu and softmax in the order: FCBLAS1 [250x144] -> RELU -> FCBLAS2 [144x144] -> RELU -> FCBLAS3 [144X144] -> 
RELU -> FCBLAS4 [144x12] -> softmax.
*relu: Performs relu operation on a vector of type float.
*softmax: Applies the softmax function on a vector of type float.
*fcblas: Performs the operation A*B+C on inputmatrix A, weightmatrix B and biasmatricx C; returns the outputmatrix in the form of a vector.
NOTE: We have used the Openblas implementation of fullyconnected function.





