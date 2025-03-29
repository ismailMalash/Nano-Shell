# Nano Shell

## Description
This project implements a simple shell that supports local and environment variables. It handles variable assignments, exports variables, and substitutes variables in commands.

## Compilation
To compile the shell, run:
gcc -o myNanoShell myNanoShell.c

markdown
Copy

## Usage
1. Run the shell:
./ismail_shell

markdown
Copy

2. Example commands:

- Variable assignment:
ismail's_Nano_Shell$ x=5

diff
Copy

- Variable substitution:
ismail's_Nano_Shell$ echo $x 5

css
Copy

- Export variable to environment:
ismail's_Nano_Shell$ export x

bash
Copy

- Invalid command:
ismail's_Nano_Shell$ x = 5 Invalid command

shell
Copy

## Example Output

```bash
ismail's_Nano_Shell$ x=5
bash
Copy
ismail's_Nano_Shell$ echo $x
5
bash
Copy
ismail's_Nano_Shell$ folder=home
bash
Copy
ismail's_Nano_Shell$ ls /$folder
# lists the /home directory (example output, may vary based on system)
bash
Copy
ismail's_Nano_Shell$ export x
bash
Copy
ismail's_Nano_Shell$ printenv
x=5
vbnet
Copy
