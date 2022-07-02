To run the code use makefile to get the required password.

The steps are :

First using chmod +rwx change the mode of the files under the folder Assignment5_pre
Then run makefile by writing the command ./makefile
This should give the desired password.



Note that:
The file fetchip.cpp is used to fetch inputs 
The file fetchop.sh fetches the corresponding ciphertext from server and saves it inside raw folder.
The file cleanop.cpp cleans the raw ouput files generated inside the raw folder
The file asciicode.cpp used to convert the string to ASCII code.

Also in the makefile we explicitly mentioned the commands which can be viewed using command : vi makefile
Here the numbers 1-8 are mentioned against the files in the lines since we decrypt the 16 characters string pairwise, so 8 inptut and ouput files are generted for each 16 character string.
 
