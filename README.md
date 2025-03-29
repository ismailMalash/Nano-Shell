# Nano Shell

This project implements a simple shell program (Nano Shell) in C, which introduces the ability to manage both local and global environment variables. It supports basic shell functionalities such as variable assignment, variable expansion, the `export` command to set global environment variables, and the ability to print the environment with the `printenv` command. The shell uses an array of data structures to store local variables and the `putenv` function to manage global environment variables.

## Features

- **Variable Assignment:**
  - Local variables can be assigned with the syntax `name=value` (e.g., `x=10`).
  - Global variables can be assigned using the `export` command (e.g., `export x=5`).

- **Variable Expansion:**
  - Variables are expanded when referenced with the `$` symbol (e.g., `echo $x` prints the value of `x`).
  - The shell supports referencing both local and global variables.

- **Built-in Commands:**
  - `echo`: Prints the provided arguments, expanding any variables.
  - `printenv`: Displays the current environment variables, including those set with `export`.

- **Local and Global Variables:**
  - **Local Variables**: Stored in a custom array of data structures.
  - **Global Variables**: Managed using the `putenv` function to add variables to the environment.

- **Error Handling:**
  - Incorrect syntax or invalid variable assignments will return an error message indicating the failure (e.g., `Terminated Incorrectly: couldn't perform the command`).
  - Local variables are scoped within the session and not shared across different instances of the shell.

## Compilation

To compile the Nano Shell, run the following command:

```bash
gcc -o myNanoShell myNanoShell.c
```

## Running the Shell

After compiling, you can run the shell with the following command:

```bash
./myNanoShell
```

The shell will prompt you with:

```
ismail's_Nano_Shell$
```

You can then enter commands like `echo`, `export`, or `printenv` to interact with the shell.

## Example Usage

### 1. **Variable Assignment:**
   ```bash
   ismail's_Nano_Shell$ x=10
   ismail's_Nano_Shell$
   ```

### 2. **Variable Expansion (Echo command):**
   ```bash
   ismail's_Nano_Shell$ echo $x
   10
   ```

### 3. **Variable Expansion with Multiple Variables:**
   ```bash
   ismail's_Nano_Shell$ echo number=$x
   number=10
   ```

### 4. **Exporting Global Variables:**
   ```bash
   ismail's_Nano_Shell$ export x=5
   ismail's_Nano_Shell$
   ```

### 5. **Print Environment Variables:**
   ```bash
   ismail's_Nano_Shell$ printenv
   x=5
   ```

### 6. **Invalid Command (Variable Assignment with Spaces):**
   ```bash
   ismail's_Nano_Shell$ x = 10
   Terminated Incorrectly: couldn't perform the command
   ```

## Code Structure

The **Nano Shell** program is structured as follows:

- **myNanoShell.c**: The main program file implementing the shell functionality.
  - The main loop where user input is processed, parsed, and executed.
  - Local variables are stored using a custom array of data structures. Each structure holds a variable name and its value.
  - When the `export` command is issued, the `putenv()` function is used to add global environment variables.

- **Local Variable Storage:**
  - Local variables are stored in an array of structs, each representing a variable. The shell looks for the variable in the array when it is referenced.
  - Local variables are scoped to the session and can be accessed during the session's runtime but are not preserved across different shell invocations.

- **Global Variable Management:**
  - When the `export` command is used, the `putenv()` function is invoked to add the variable to the system's environment, making it globally accessible.
  - Global variables persist across different shell sessions until explicitly unset or changed.

- **Error Handling:**
  - Syntax errors, such as improper spaces in variable assignments (`x = 10` instead of `x=10`), trigger error messages and prevent command execution.

