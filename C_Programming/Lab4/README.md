# CD Catalogue
### 1. Assignment
For this assessment you are asked to implement and test a program for cataloguing a collection of compact
disks. Each compact disk has the following details:

|Description|Data Type|
|------|---|
|Name of Band/Singer|String of 48 characters|
|Name of CD|String of 48 characters|
|Reference|String of 16 characters|
|Cost|Floating point number|
|Year of Release|Integer|

The program should carry out the following tasks:

##### • Read in data from the standard input (keyboard) and save it appropriately organised in a file.
##### • Retrieve from the file and print out data to the screen appropriately annotated (e.g. Name of Band: XXXX, etc).  

The User Interface of the program should be based on the following text based menu:
```C
The following options are available:
Read in data [1]
Print out catalogue to screen [2]
Save data to file [3]
Exit Program [4]
Enter your choice now:
```
After a task is performed the user should be probed for a new choice until Exit is requested.
### Programming hints:
You could create a custom struct to hold the above details.
You can use unformatted input to read in one line at a time into a string. This will allow you to read in
names and titles with spaces, e.g.
```C
gets(str);
```
to read characters from the standard input into a character array called str. Keep in mind that **gets()** does not
let you specify a limit on how many characters are to be read so you must be careful with the size of the
array pointed by str to avoid buffer overflows.
You may also use **fgets()** although the usage differs from **gets()** slightly.
