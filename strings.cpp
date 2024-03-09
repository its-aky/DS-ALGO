//important problems

//Logic:Concatenate the string1 with itself and check whether string2 is substring of concatenated string 
//https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1


//Checking maximum length of palindromic substring in a given string and also generating the string as output 
//Logic:for i(0->n-1) generate all substring using j(i->n-1) and pass this i and j to helper which tell that substring starting at i and ending at j is palindromic or not
//maintain a start and lenght of maximum palindrome possible to generate the substring
//https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0


//Generating all permutations of a string(not array) and also using set to handle duplicate characters in the string
//Logic: Used for loop + recursion technique for this kind of problems where for each position n! ways are possible
//The for loop again starts from i=0 for each recursive call, So a hash DS will be needed to keep track of chosen indexes
//So two DS are required as parameter to recursive function call ,one for storing generated string and one for hashing
//https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1


