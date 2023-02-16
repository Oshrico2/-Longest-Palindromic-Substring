# -Longest-Palindromic-Substring
 Solves the maximum palindrome problem using dynamic programming and returns as output the size and the table.

example:

enter string:
sasarbasa
String: sasarbasa
size of String: 9
size of max palindrom: 7
Table:
1 1 3 3 3 3 3 5 7 
0 1 1 3 3 3 3 5 7 
0 0 1 1 1 1 3 5 5 
0 0 0 1 1 1 3 3 3 
0 0 0 0 1 1 1 1 3 
0 0 0 0 0 1 1 1 3 
0 0 0 0 0 0 1 1 3 
0 0 0 0 0 0 0 1 1 
0 0 0 0 0 0 0 0 1 
Max Palindrom: asabasa
