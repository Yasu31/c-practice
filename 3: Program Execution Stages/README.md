# Program Execution
## the shell
ex: sh, bash, tcsh

compares the command that the user enters, checks with the PATH environment variable

to run something in the background, do either:
* type "&" after program name
* press ctrl-Z (issuing the SIGSTOP signal) and type "$ bg", issuing the SIGCONT signal to the child process

## the kernel
invoke a function from the *exec* family of functions, which calls the *sys_execve* function in the end. Then, it determines the executable format (such as ELF)

## loading
group up the sections into **segments**, based on common attributes

### static build
library is fully portable. Compile with -static linker flag.
`$ gcc -static main.c -o staticBuild`
