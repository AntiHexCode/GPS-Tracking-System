when working in the project make sure to follow these steps:

1- make a new folder for the new feature, that folder will contain 2 files (.c and .h)

  1.1- the .c file will contain the code.
  1.2- the .h will contain the macros (#define), constants and prototypes 
       needed for JUST YOUR CODE.
  NOTE: add the macros and constants that you will only use, don't add here
        the general macros or general constants that we will need,
        also here you add the prototypes for the functions in your .c file
  1.3- the general macros and constanst will be found in tm4c123gh6pm.h.
  NOTE: general macros means that they are used in every part of the project not
        only your file, so if you need a general macro or a general constant,
        you will find it in the general .h file (tm4c123gh6pm.h), and if not found
        jus add it in there, soy we can all use it, assuming it's of general use.


NOTE: probably you will include these files in your .c file
      1- your .h file
      2- tm4c123gh6pm.h
      3- <stdint.h>

NOTE: if you are working in the main file, and need any functions, include the .h file
      that contains the prototype of the needed fuction.

NOTE: any needed macros, just get it from the tiva header file without including
      the whole file, just the needed macros

NOTE: you can use the file called bit_help for some help when dealing with bits.

NOTE: test everything before pushing to the github