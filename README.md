# C+-

  ![alt text](https://github.com/koreaneggroll/C-plus-minus/blob/main/logo.jpeg?raw=true)

A personal project trying to be a programming language with close resemblence to C/C++ (probably gonna fail at that).

## What I want the programming language to  be
 I want it to be:

 * An imperative programming language(obviously)
 * Statically typed
 * I want it to be able to be used in bigger projects but also small scripts
 * Have close syntax to C++ but with more features, but also easier to read.


  But for now I want it to be able at least to be close to assembly so it can actually do stuff.


## How to contribute
 If you want to contribute the layout of the program is pretty simple.
 The `include` directory holds all of the header files.
 The `lib` directory holds all of the files for the standard libraries of the programming language.
 The `src` directory holds all the C files.
 The `testing` directory is where the actual .cpm file is located.

 And now lets test if everything works fine. This should work on linux I don't know about windows though.

 To test the program you must clone it so first you're gonna run:


    git clone https://github.com/koreaneggroll/C-plus-minus.git
    cd C-plus-minus


    And now you'll have to run 2 very simple commands


    make
    ./cpm compile ./testing/main.cpm


    If the output is "Hello world"(this is only for now until I learn about compilers and start working on it) then it works fine. You can start contributing to either the syntax, the compiler or anything you'd like.


## Technologies
 For now it is being built with C.
