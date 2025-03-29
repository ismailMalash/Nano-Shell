# Nano Shell

## Description

This project implements a simple shell that supports local and environment variables. It handles variable assignments, exports variables, and substitutes variables in commands.

## Compilation

To compile the shell, run:

```bash
gcc -o myNanoShell myNanoShell.c
Usage
Run the shell:

bash
Copy
./ismail_shell
Example commands:

Variable assignment:

bash
Copy
ismail's_Nano_Shell$ x=5
Variable substitution:

bash
Copy
ismail's_Nano_Shell$ echo $x
5
Export variable to environment:

bash
Copy
ismail's_Nano_Shell$ export x
Invalid command:

bash
Copy
ismail's_Nano_Shell$ x = 5
Invalid command
Example Output
bash
Copy
ismail's_Nano_Shell$ x=5
ismail's_Nano_Shell$ echo $x
5
ismail's_Nano_Shell$ folder=home
ismail's_Nano_Shell$ ls /$folder
# lists the /home directory
ismail's_Nano_Shell$ export x
ismail's_Nano_Shell$ printenv
x=5
