intal: integer(non-negative) of arbitrary length.

# intal-library
intal is a nonnegative integer of arbitrary length (not more than 1000 decimal digits).

The integer is stored as a null terminated string of ASCII characters.
String of decimal digits ('0' thru '9') are stored in big endian style.
That is, the most significant digit is at the head of the string.
Eg: Integer 25 is stored in str as '2' at str[0], '5' at str[1], and null char at str[2].

An intal is, any non-negative integer of arbitrary length which is stored and processed as an array of characters.
All the data-types such as int,float,short have their own working limit which when exceeds, behaves abnormally.
intal, unlike doesn't have any limit as it is stored as an array of characters.

Apllications of intal:
1.To store very large numbers (numbers which may even not fit in long long int)
2.To performs operations on very large numbers.


Implementation of functions in the library of intal:

1.char* intal_add(const char* intal1, const char* intal2);\
	->Returns the sum of two intals.\
	->The idea implemented is of school mathematics.\
	->Process the both strings from the end, add the each number(stored as character) from both strings and store it in new string at it's 
	  respective place,also keep track of carry.\
	->Finally sum is storedin the new resultant string.\

2.int intal_compare(const char* intal1, const char* intal2);\
	->Returns the comparison value of intal1 and intal2.\
	->The idea is,
	  first check the length of both strings and return accordingly,
	  and then if the length of strings are equal, process both strings from the start and compare each number and return accordingly.

3.char* intal_diff(const char* intal1, const char* intal2);\
	->Returns the diff(non-negative) of two intals.\
	->The idea implemented is of school mathematics.\
	->Process the both strings from the end, subtract the each number(stored as character) from both strings and store it in new string,
	  also keep track of borrow.\
	->Finally reverse the new string and trim the leading zeors to get the resultant string.\

4.char* intal_multiply(const char* intal1, const char* intal2);\
	->Returns the product of two intals.\
	->The idea implemented is of school mathematics.\
	->Process the both strings from the end, multiply the each number(stored as character) from both strings and store it in new string,
	  We add all these multiplications. While adding, we put i-th multiplication shifted.\
	->Finally reverse the new string to get the resultant string.\

5.char* intal_mod(const char* intal1, const char* intal2);\
	->The idea implemented is,\
	->Get one variable to store the answer intialized to zero.\
	->Scan the string from left to right,\
	->Everytime multiply the answer by 10 and add the next number and take the modulo and store this as new answer.\
	  i,e\
	  12345%100\
	  ans = 0\
	  ans = (0*10 + 1)%100\
	  ans = (1*10 + 2)%100\
	  ans = (12*10 + 3)%100\
	  ans = (23*10 + 4)%100\
	  ans = (34*10 + 5)%100\
	  ans = 45.\


6.char* intal_pow(const char* intal1, unsigned int n);\
	->The idea implemented is decrease by constant factor,\
	->i.e\
	  Power(a,n)\
	  if (n = 0) return 1\ 
	  p ← Power(a, ⌊n/2⌋)\
	  p ← p * p \
	  if (n is odd) p ← p * a \
	  return p\


7.char* intal_gcd(const char* intal1, const char* intal2);\
	->The idea implemented is eucledian algorithm\
	  gcd(m,n)\
	  if(n==0) return m;\
	  return gcd(n,m%n);\

8.char* intal_fibonacci(unsigned int n);\
	->The idea implemented is,\
	  f[n]=f[n-1]+f[n-2],where\
	  f[0]=0\
	  f[1]=1\

9.char* intal_factorial(unsigned int n);\
	->The idea implemented is,\
	  res = 1; \
	  for (i = 2; i <= n; i++) \
		  res *= i; \
	  return res;\

10.char* intal_bincoeff(unsigned int n, unsigned int k);\
	->As we know C(n,k)=C(n,n-k)\
	->k is choosen between smallest of k and n-k\
	->The idea implemented is,\
	  Basic Formula,\
	  C(n, k) = C(n-1, k-1) + C(n-1, k)\
	  C(n, 0) = C(n, n) = 1\
	  using DP table of size k+1,\
	  and using the recursion,\
	  for (int i = 1; i <= n; i++) \
	  { 
	  	  for (int j = min(i, k); j > 0; j--) \
          		    C[j] = C[j] + C[j-1]; \
	  } 

11.int intal_max(char **arr, int n);\
	->The idea implemented is to initialize max as first element, then traverse the given array from second element till end. 
	  For every traversed element, compare it with max, if it is greater than max, then update max.\

12.int intal_min(char **arr, int n);\
	->The idea implemented is to initialize min as first element, then traverse the given array from second element till end. 
	  For every traversed element, compare it with min, if it is smaller than min, then update min.\

13.int intal_search(char **arr, int n, const char* key);\
	->The idea implemented is of Linear Search
	  Compare each element (starting at 0th index) of the array with the key, if it matches return the index of that element,	
	  else return -1. \

14.int intal_binsearch(char **arr, int n, const char* key);\
	->The idea implemented is of Binary Search on a sorted array.\
	  Compare "key" with the middle element.\
	  If "key" matches with middle element, we return the mid index.\
	  Else If "key" is greater than the mid element, then "key" can only lie in right half subarray after the mid element. 
	  So we recur for right half.\
	  Else ("key" is smaller) recur for the left half.\
	->It is also made sure that with duplicate elements in the array first one is selected.\

15.void intal_sort(char **arr, int n);\
	->The idea implemented is Merge Sort as it is O(nlogn) algorithm irrespective of stored elements.\
	->Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. 
	  The Merge() function is used for merging two halves. \
	  The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted,\
	  and merges the two sorted sub-arrays into one.\


16.char* coin_row_problem(char **arr, int n);\
	->The idea is using Dyanmic Programming(DP table)\
	->The recursion is, f(n) = max{ arr[n-1] + f(n-2), f(n-1) } for n > 1 where f(0) = 0, f(1) = c0\
	->As we are interested in only optimal value we can use a window of 3 and slide it in every iteration.\
	  i.e \
	  for i = 2 to n\
		next = max(prev+C[i-1], cur)\  
		prev = cur \
		cur = next.\
 
To generate your own testcases, you can use https://www.omnicalculator.com/math
