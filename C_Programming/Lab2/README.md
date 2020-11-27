# Replace spaces in string by "-" symbols
## Specification:
Write a function "replace" which takes a
pointer to a string as a parameter, which
replaces all spaces in that string by minus
signs, and delivers the number of spaces it
replaced.  
Thus
```C
char *cat = "The cat sat";
n = replace( cat );
```
should set
cat to "The-cat-sat"
and n to 2.  
Typical input:
```
The cat sat on the mat.
```
Typical output:
```
String was : The cat sat on the mat.
String is : The-cat-sat-on-the-mat.
Number replaced 5
```

# Code a string
## Specification:
Write a function "code" which takes a
pointer to a string as a parameter, and
encodes the string using the arrays:
```C
char code1[] = “abcdefghijklmnopqrstuvwxyz”;
char code2[] = “bpduhijkaltxwmrzfoysvngeqc”;
```
The encoding works as follows: Each lower
case letter occurs somewhere in array
code1. The program searches the array for
the letter, notes the index of the variable in
which the letter occurs, and then uses this
index in the array code2 to find the corre
sponding letter to be used in the output.
For example, suppose that the line contains
the letter b. Because the b is stored at index
1 in code1, b is encoded as p - the char
acter stored at index 1 in code2. Uppercase
characters in the input file are not coded
since they are not in array code1. They are
thus unchanged.  
Thus
```C
char *cat = "The cat sat";
code( cat );
```
should set
cat to "Tkh dbs ybs"  
Typical input:
```
The cat sat on the mat.
```
Typical output:
```
String was : The cat sat on the mat.
String is : Tkh dbs ybs rm skh wbs.
```
