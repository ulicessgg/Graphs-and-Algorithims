/*
-----------------------------------
________ genRandNormalDist ________
-----------------------------------

input of the problem
// one integer vector
// two double variables, mean and stdDev or standard deviation
output of the problem
// populates int vector passed into it and passes it along to calcNormalHistStats
your algorithm in pseudo code with comments
//
genRandNormalDist(integer vector, mean, standard deviation)
	{
		if mean or standard deviation are equal to 0
		{
			output message stating distribution is not possible with current mean and or standard deviation
			break function and return to original function
		}
		declare size of distribution as 20000 as specified in the project description
		declare default_random_engine used to generate numbers
		declare normal distribution using the mean and standard deviation
		declare temporary integer used to hold the value of numbers from random generation
		if the mean is lesser than 10 the size is set to the mean plus 6 to make it a range of 10
		{
			resize the vector using the mean plus 6 to make the range large enough to output 10 bins
		}
		if the mean is greater than 10 the size is set to the mean plus 11 to make it a range of 20
		{
			resize the vector using the mean plus 11 to make the range large enough to output 20 bins
		}
		for loop used to generate 20000 random integers
		{
			assign a random value from the distribution to temp and round it to a whole number for it to generate histogram
			temp = static_cast<int>(std::round(myDist(seed))); // generates a random value within the distribution and rounds it to an integer in order to create a histogram
			if random number is within 0 and our max size
			{
				increase the frequency of the number generated treating the number as an index in the vector
			}
		}
	}
//
worst-case time complexity analysis
// time complexity always equal to O(20000) as that is the amount of iterations of our for loop
your choice of data structures with a brief justification in the final coding stage
// a vector was used as a historgram as it is can be treated as one dimensional by using indexes as values and the value held at the index as the frequency
// doubles were used for mean and stdDev incase function is repurposed wihtout the need of a histogram
// default_random_engine and normal distribution from <random> were used in order to develop a normal distrubtion properly alongside with truly random numbers

-------------------------------------
________ calcNormalHistStats ________
-------------------------------------

input of the problem
// one integer vector populated in genRandNormalDist
// two double variables, mean and stdDev or standard deviation
output of the problem
// outputs histogram/distribution information to console along with corresponding value
   "Mean: #" 
   "Median: #"
   "Mode: #" 
   "Variance: #" 
   "Standard Deviation: #" 
   "Min: #" 
   "Max: #" 
your algorithm in pseudo code with comments
//
calcNormalHistStats
{
	//mean median and mode are the same in normal distribution
	declare median with value of the mean
    declare mode with value of the mean
    //standard deviation is the square root of the variance
	declare variance with value of stdDev^2

	declare minPos with the value of the min of the vector as this just is the frequency
	declare min as the index of minPos as the index is the actual value of the bin
	declare maxPos with the value of the max of the vector as this just is the frequency
	declare max as the index of maxPos as the index is the actual value of the bin

	// outputs histogram data to users
	"Mean: #" 
    "Median: #"
    "Mode: #" 
    "Variance: #" 
    "Standard Deviation: #" 
    "Min: #" 
    "Max: #" 
}
//
worst-case time complexity analysis
// time complexity always equal to O(n) due to min_element, max_element, and distance being used the  n representing the size of the vector 
// if the vector has a size of 21 then the time complexity is O(21)
your choice of data structures with a brief justification in the final coding stage
// auto was used in order to hold the min and max values to avoid errors based on the return of min_element and max_element
// size_t was used in order to account for possibly large vector sizes in order to hold indexes

-------------------------------------
__ calcNormalHistStats(overloaded) __
-------------------------------------

input of the problem
// one integer vector populated in genRandNormalDist
// two size_t variables, min and max
// five double variables, mean and stdDev or standard deviation, median, mode, variance
output of the problem
// returns median, mode, variance, min, and max by reference for unit testing
your algorithm in pseudo code with comments
//
calcNormalHistStats
{
	//mean median and mode are the same in normal distribution
	median assigned value of the mean
    mode assigned value of the mean
    //standard deviation is the square root of the variance
	variance assigned value of stdDev^2

	declare minPos with the value of the min of the vector as this just is the frequency
    min assigned the index of minPos as the index is the actual value of the bin
	declare maxPos with the value of the max of the vector as this just is the frequency
	max assigned the index of maxPos as the index is the actual value of the bin
}
//
worst-case time complexity analysis
// time complexity always equal to O(n) due to min_element, max_element, and distance being used the  n representing the size of the vector 
// if the vector has a size of 21 then the time complexity is O(21)
your choice of data structures with a brief justification in the final coding stage
// auto was used in order to hold the min and max values to avoid errors based on the return of min_element and max_element
// size_t was used in order to account for possibly large vector sizes in order to hold indexes

-------------------------------------
________ printNormalHist ________
-------------------------------------

input of the problem
// one integer vector populated in genRandNormalDist
// one char for user input of a symbol representing data in histogram
// one double for the mean
output of the problem
//  
    Mean: 9
	Standard Deviation: 3
	Enter symbol for histogram printing: @

	 4|@@@@@@
	 5|@@@@@@@@@@
	 6|@@@@@@@@@@@@@@@@
	 7|@@@@@@@@@@@@@@@@@@@@@
	 8|@@@@@@@@@@@@@@@@@@@@@@@@
	 9|@@@@@@@@@@@@@@@@@@@@@@@@@@
	10|@@@@@@@@@@@@@@@@@@@@@@@@
	11|@@@@@@@@@@@@@@@@@@@@@
	12|@@@@@@@@@@@@@@@
	13|@@@@@@@@@@@
	14|@@@@@@
//
your algorithm in pseudo code with comments
//
printNormalHist
{
	// 
	if empty
	{
		ends function
	}
	Enter symbol for histogram printing

	
	if the mean is closer to 0 by being lesser than 5
	{
		for loop iterates through vector
		{
			print out the value of the bin
			if the corresponding value is present
			{
				prints user symbol with frequency of it using 200 for scaling divided 20000 for the size of our distribution
			}
			else
			{
				new line outputted
			}
		}
	}
	if the mean is larger than 5 lesser than 10
	{
		for loop iterates through vector starting from 5 indexes below the mean
		{
			print out the value of the bin
			if the corresponding value is present
			{
				prints user symbol with frequency of it using 200 for scaling divided 20000 for the size of our distribution
			}
			else
			{
				new line outputted
			}
		}
	}
	if the mean is larger than or equal to 10
	{
		for loop iterates through vector starting from 10 indexes below the mean
		{
			print out the value of the bin
			if the corresponding value is present
			{
				prints user symbol with frequency of it using 400 for scaling divided 20000 for the size of our distribution
			}
			else
			{
				new line outputted
			}
		}
	}
}
//
worst-case time complexity analysis
// time complexity always equal to O(n) the n representing the size of the vector 
// if the vector has a size of 21 then the time complexity is O(21)
your choice of data structures with a brief justification in the final coding stage
// size_t used for iterators to prevent out of bound errors
// string conversional used to output user symbol


 /*
-----------------------------------
________ createHistogram ________
-----------------------------------

input of the problem
// one integer vector
// two double variables
//one character
output of the problem
// populates int vector passed into it and passes it along to printingHistogram
your algorithm in pseudo code with comments
//
createHistogram(double rangeMin, rangeMax)
	{

		declare size of distribution as 20000 as specified in the project description
		declare intervals and how wide they are
		declare default_random_engine used to generate numbers
		declare uniform distribution using the range with upper bound and lower bound variables
		declare vector of dataNums with the intervals
		declare temporary integer used to hold the value of numbers from random generation

		for loop used to generate 20000 random integers
		{
			assign a random value from the distribution to tempNums for it to generate histogram
			index = static_cast<int>((tempNums - rangeMin) / (rangeMax - rangeMin) * intervals// in order to create a histogram
			if index is not negative & less than the interval size, then increase dataNums
			{
				increase the frequency of the number generated
			}
		}
		calling the print function
	}
//
worst-case time complexity analysis
// time complexity always equal to O(20000) as that is the amount of iterations of our for loop
your choice of data structures with a brief justification in the final coding stage
// a vector was used as a histogram as it is can be treated as one dimensional by using indexes as values and the value held at the index as the frequency
// doubles were used for minimum and maximum range values because the assignment requires floating-point numbers
// default_random_engine and uniform distribution from <random> were used in order to develop a uniform distribution properly alongside with truly random numbers
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Input and output of the problem
quickSort() ->
    ({TokenFreq[freq: 1], TokenFreq[freq: 3], TokenFreq[freq: 2]}, 0, 3, sortAsc | {TokenFreq[freq: 1], TokenFreq[freq: 2], TokenFreq[freq: 3]})
    ({TokenFreq[freq: 1], TokenFreq[freq: 3], TokenFreq[freq: 2]},0, 3 sortDesc | {TokenFreq[freq: 3], TokenFreq[freq: 2], TokenFreq[freq: 1]})
your algorithm in pseudo code with comments
quickSort() ->
    Input:
        ({TokenFreq[freq: 1], TokenFreq[freq: 3], TokenFreq[freq: 2]}, 0, 3, sortAsc)
    Output:
        ({TokenFreq[freq: 1], TokenFreq[freq: 2], TokenFreq[freq: 3]})
    Algorithm:
         If the left and right indexes cross or are at the same index.
             The arr is sorted. Return nothing.
         Sort the full array and return the pivot position.
         Sort the lower parition, ending at the pivot.
         Sort the upper partition, starting at the value +1 the pivot.

partition() ->
    Input:
        ({TokenFreq[freq: 1], TokenFreq[freq: 3], TokenFreq[freq: 2]}, 0, 3, sortAsc)
    Output:
        ({TokenFreq[freq: 1], TokenFreq[freq: 2], TokenFreq[freq: 3]})
    Algorithm:
    Pick a random value as pivot

    Get the leftest and right most indexes.

    While the left and right index do not cross.
            increase the left most index until the comparison fails against the pivot.
            decrease the right most index until the comparison fails against the pivot.

            If the left and right indexes cross or are at the same index.
                the partition is complete.
            ELSE:
                Swap the values of the right index and left index.
    return the current pivot.


worst-case time complexity analysis
   quickSort -> O(n^2)
   parition -> partition -> O(n)
your choice of data structures with a brief justification in the final coding stage
    I am using vectors because I do care about order in this situation. Secondly, I care about being able to dynamically add values for ease of testing however, without that, basic arrays would be suitable. 

____________________
___ genKthRanked ___
____________________

Input: 
* a vector of TokenFreq objects
* an integer indicating the rank of the desired TokenFreq
* a comparison function

Ouput: A TokenFreq Object of the rank specified

Pseudocode:

genKthRanked(vector, k, comp)
    left = 0;
    right = length of vector -1
    Loop indefinitely:
        pivot = random int between left and right
	new_pivot = partition(vector, left, right, comp)

	If new_pivot is the index of the k-th ranked element:
	    Return vector[new_pivot]
	If new_pivot is greater than the index of the k-th ranked element:
	    Set right to new_pivot - 1
	If new_pivot is less than the index of the k-th ranked element:
	    Set left to new_pivot + 1

Worst case time complexity: O(N^2)

Justification for using user-defined struct TokenFreq:
* The idea was to expand on previous assignments we've already done in the class such as the tokenizer so that's why we used the TokenFreq object.

*/

