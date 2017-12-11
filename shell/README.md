# Fall 2017, OS - Shell Lab

use "make" to create shell executable
use "./shell" to run shell
use "make clean" to remove all *.o files and other junk

This program is a basic shell that uses MyToc from the previous lab in order to receive commands and execute them.

The current version of this shell is able to execute commands with or without a path, in multiple lines, with and without parameters, redirect input/output, and change directory, including the ".." comand for a level above of the current working directory.

it is currently unable to use pipes, neither single or multiple, nor is it able to run processes in the background.
      
Discussion of implementation and algorithms was had amongst author and the following colleagues:
    
    Edward Seymour (execve() command and general discussion)
    Daniel Pacheco (PATH, envp, argc, argv, and other useful code)
    Jorge Guijosa (HOW to use PATH)
    Adrian Veliz (How to prepare for PS1="", what to tokenize regarding envp)
