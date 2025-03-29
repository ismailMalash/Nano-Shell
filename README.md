# Nano Shell

## Overview

This project implements a custom shell named **Nano Shell** that supports local and environment variables. It handles variable assignments, exports variables to the environment, and substitutes variable references in commands. It also provides error handling for invalid inputs and dynamically manages memory for shell variables.

## Features

- **Variable Assignment**: Allows variable assignments in the format `Variable=Value`. The shell saves these variables for future reference.
- **Variable Substitution**: Supports the `$variable_name` format to substitute variables in command arguments.
- **Export**: Implements a built-in command `export` to add shell variables to environment variables, making them available to external commands.
- **Environment Inheritance**: All newly executed commands inherit the environment variables of the shell.
- **Dynamic Memory Management**: Uses dynamic allocation to manage variables, ensuring scalability without memory leaks.

## Compilation

To compile the Pico Shell, use the following command:

```bash
gcc -o myNanoShell myNanoShell.c
This will produce an executable named ismail_shell.
```

Usage
Start the shell by running the compiled executable:

bash
Copy
./ismail_shell
The shell will display the prompt ismail's_Nano_Shell$ where you can enter commands.

Use the following commands to interact with the shell:

Variable Assignment: To assign a value to a variable, use the format Variable=Value. Example:

bash
Copy
ismail's_Nano_Shell$ x=5
Variable Substitution: To substitute the value of a variable in a command, use the $variable_name format. Example:

bash
Copy
ismail's_Nano_Shell$ echo $x
5
Export Command: To add a variable to the environment, use the export command. Example:

bash
Copy
ismail's_Nano_Shell$ export x
Invalid Commands: If an invalid command or syntax is entered, an error message is displayed:

bash
Copy
ismail's_Nano_Shell$ x = 5
Invalid command
To test the behavior of environment variables, you can use the printenv command after exporting a variable:

bash
Copy
ismail's_Nano_Shell$ export x
ismail's_Nano_Shell$ printenv
x=5
Example Output
Here are some example interactions with the shell:

bash
Copy
ismail's_Nano_Shell$ x = 5
Invalid command
ismail's_Nano_Shell$ x=5 echo hello world
Invalid command
ismail's_Nano_Shell$ x=5
ismail's_Nano_Shell$ echo $x
5
ismail's_Nano_Shell$ folder=home
ismail's_Nano_Shell$ ls /$folder
# lists the /home directory
ismail's_Nano_Shell$ echo $non-existing-var

ismail's_Nano_Shell$ export x
ismail's_Nano_Shell$ printenv
...
x=5
...
ismail's_Nano_Shell$

Memory Management
The shell uses dynamic memory allocation (e.g., malloc and free) to store variables and their values. This ensures that the shell can handle any number of variables without running into memory issues. The code also ensures proper deallocation of memory to prevent memory leaks.

markdown
Copy

---



