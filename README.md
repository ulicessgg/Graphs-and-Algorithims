Due date:  Wednesday, March 20

## Problem description:  Each small group work together to solve the following problems:

1. generate a histogram of 20,000 randomly generated integer numbers according to a normal distribution with a user-specified mean and standard deviation.

2. generate a histogram of 20,000 randomly generated floating-point numbers according to a uniform distribution with a user-specified range.

3. implement an almost generic randomized-QuickSort algorithm to sort an array of TokenFreq objects by a given sorting criterion. To realize this, you will use

- function templates 
- function objects, Lambda expressions, or a pointer to functions
4. implement an almost generic algorithm (the randomized version) to find the k-th ranked object in an array without first sorting this array.  Same as above, you will use. function templates and function objects. 

## Deliverables:

Please follow the problem solving process and submit the following steps in one set of  documents as a group:

A design-doc that describes the problem-solving process for all the above problems. For each problem, include the following aspects: 
- input and output of the problem
- your algorithm in pseudo code with comments
- worst-case time complexity analysis
- your choice of data structures with a brief justification in the final coding stage (e.g., "We declared a user-defined struct for ... because ...")
Your program files.  one for each problem.  Each program file will consist of the following information:

A header file:
- the function prototype to generate  x uniformly distributed random numbers 
- the function prototype to generate x random numbers following a specified normal distribution
- the function prototype to calculate the underlying data of a histogram, given a collection of numbers
 the function prototype to print out a histogram using a user-specified symbol (e.g., *)
- the function prototype of the partition subroutine that's shared by the quickSort and k-th ranked  object algorithms
- the function prototype of the almost generic quicksort algorithm
- the function prototype of the almost generic k-th ranked algorithm
- your CPP file with comments
  - define the above functions
- a header file consisting of your unit tests: 
  - at least two unit tests per function
- Submission link:  A submission link will be open soon on Canvas. 