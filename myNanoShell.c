#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF_SIZE 100
#define MAX_ARG_NUMBER 5
#define MAX_ARG_SIZE 10

extern char **environ;	//To make all enviromental variables seen to all childs

typedef struct localVar{
	char *varName;
	char *varValue;
}localVar;

localVar varArray[100] = {0}; // for storing local variables
short int arrayCounter = 0;

void add_var(char *, char *);
char *search_var(char *);
int check_variable_format(char *);

int main(void) {
	
	char *buff = NULL;
	char *token = NULL;
	char *value = NULL;    //for variable value
	//char *name = NULL;		//for variable tokenizing
	char *message = NULL;
	char **arguments = NULL;

	int i = 0;

	while(1) 
	{
		printf("ismail's_Nano_Shell$ ");

		buff = (char *)calloc(BUFF_SIZE, sizeof(char));
		fgets(buff, BUFF_SIZE, stdin);
		buff[strlen(buff) - 1] = 0;	//deleting \n character
		if (strlen(buff) == 0)
		continue;

		token = strtok(buff, " ");

		/*exit*/
		if (!strcmp(token, "exit"))
		{
			free(buff);
			break;
		}
		/*echo*/
		else if (!strcmp(token, "echo"))
		{
			token = strtok(NULL, " ");
			while (token != NULL)
			{
				if(strchr(token, '$') != NULL)
				{
					while (token[i] != '$')
					{
						printf("%c", token[i]);
						i++;
					}

					token+= (i+1);
					i = 0;
					value = search_var(token);
					printf("%s ", value);
				}
				else
				{
					printf ("%s ", token);
				}

				token = strtok(NULL, " ");
			}
			printf("\n");
			free(buff);
		}
		/*pwd*/
		else if (!strcmp(token, "pwd"))
		{
			printf("%s\n", getcwd(message, 100));
			free(buff);
		}
		/*cd*/
		else if (!strcmp(token, "cd"))
		{
			token = strtok(NULL, " ");

			if(token[0] == '$')
			{
				token +=1;
				value = search_var(token);
				token = value;
			}

			if(chdir(token) == -1)
			{
				printf("%s: No such file or directory\n", token);
			}
			free(buff);
		}
		/*export*/
		else if (!strcmp(token, "export"))
		{
			token = strtok(NULL, " ");

			if (check_variable_format(token))
				putenv(token);
			else
				printf("Invalid command!: wrong format\n");
		}

		/*assigning local variables*/
		else if (strchr(token, '=') != NULL)
		{
			token = strtok(token, "=");
			value = strtok(NULL, "=");

			add_var(token, value);
		}
		else
		{
			if (fork() == 0) {
				/*New child Process*/
				char *command = token;
				token = strtok(NULL, " ");

				arguments = (char **)calloc(MAX_ARG_NUMBER, MAX_ARG_SIZE);
				arguments[0] = command;
				int i = 1;
				while(token != NULL)
				{		// add args in the array of args to be passed to execvp() so you can check on each arg if ity contains $ sign
				//  to replace it with its value

					if (strchr(token, '$'))
					{
						token+=1;
						arguments[i] = search_var(token);
					}
					else
					{
						arguments[i] = token;
					}
					token = strtok(NULL, " ");
					i++;
				}
				arguments[i] = NULL;

				if (execvp(command, arguments) == -1) 
				{
					printf("Terminated Incorrectly\n");
					free (arguments);
					free(buff);
					exit(3);
				}
				free(arguments);
				free(buff);
			}
			else 
			{
				/*Parent process*/
				int status = 0;

				wait(&status);
				if(WEXITSTATUS(status) == 3)
				printf("couldn't perform the command]\n");
				free(buff);
			}
		}

	}

	return 0;
}


void add_var(char *name, char *value) {
	int i = 0;

	for (i = 0; i < 100; i++)
	{
		if (varArray[i].varName == NULL)
		{
			varArray[i].varName = name;
			varArray[i].varValue = value;
			break;
		}
	}

}

char *search_var(char *name) {
	
	int i =0;

	for (i = 0; i < 100; i++)
	{
		if (strcmp(varArray[i].varName, name) == 0)
		{
			return varArray[i].varValue;
		}
	}

}

int check_variable_format(char *string) {

	if ( (string[0] != '=') && (strchr(string, '=') != NULL) && (strchr(string, ' ') == NULL) )
		return 1;

	return 0;
}