#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

struct EnvVar{
  char *name;
  char *value;
};

struct ExeCommand{
    char *name;
    time_t time;
    int returnValue;
};

struct ExeCommand commands[10]; 
struct EnvVar variables[10];

int childProcess(char*);
char* readInput();
int waitForInput();
int parseInput(char*);
int logg();
int variableCreation(char*);

int m = 1;

int main(int argc, char *argv[]){


while(m == 1){
  parseInput("");
  if( m != 1){
    exit(0);
  }

}
  
  return 0;
}

char* readInput(){

  size_t bufsize = 30;
  char * input = NULL;
  char tempbuf[bufsize];
  size_t inputlen = 0, templen = 0;

  do{
    fgets(tempbuf, bufsize, stdin);
    templen = strlen(tempbuf);
    input = realloc(input, inputlen + templen + 1);
    strcpy(input + inputlen, tempbuf);
    inputlen += templen;
  } while(templen == bufsize - 1 && tempbuf[bufsize-2] != '\n');

  return input;


}

int waitForInput(){

  printf("\ncshell$ ");

  char* input = readInput();

  char *token;
  char *whiteSpace = " \n"; 

  int numberOfWords = 0;

  char *wholePrompt[5];

    for (token = strtok(input, whiteSpace); token; token = strtok(NULL, " ")){ //changed name to input

        wholePrompt[numberOfWords] = token;
        numberOfWords = numberOfWords + 1;

        
    }
    time_t rTime;
    struct tm * timeinfo;
    time(&rTime);
    timeinfo = localtime(&rTime);

    

    char *arrayOfCommands[][5] = {{"exit", "log", "print", "theme"}}; //removed n at the end
    
    for(int i = 0; i <= 3; i++){
        if(strcmp(wholePrompt[0], arrayOfCommands[0][0]) == 0){
            printf("Bye!");
            i = 3;
            exit(0);
        }else if(strcmp(wholePrompt[0], arrayOfCommands[0][1]) == 0){
            i = 3;
        }else if(strcmp(wholePrompt[0], arrayOfCommands[0][2]) == 0){
            printf("%s", wholePrompt[1]);
            i = 3;
            printf("%s", asctime(timeinfo));
            //log("print")
        }else if(strcmp(wholePrompt[0], arrayOfCommands[0][3]) == 0){
            
            i = 3;
        }else{

          childProcess(wholePrompt[0]);
          i = 3;
        }
    }
  
  free(input);

  return 0;

}

int parseInput(char* tempr){

  printf("cshell$ ");

  char* input = readInput();

  char *token;
  char *whiteSpace = " \n"; 

  int numberOfWords = 0;

  char *wholePrompt[5];

    for (token = strtok(input, whiteSpace); token; token = strtok(NULL, " ")){ 

        wholePrompt[numberOfWords] = token;
        numberOfWords = numberOfWords + 1;

    }

    time_t rTime;
    struct tm * timeinfo;
    time(&rTime);
    timeinfo = localtime(&rTime);

    int nVariable = 0;
    char* envVarName;
    char* envVarValue;

    

    char *arrayOfCommands[][5] = {{"exit", "log", "print", "theme"}}; 
    
    for(int i = 0; i <= 3; i++){
        if(strcmp(wholePrompt[0], arrayOfCommands[0][0]) == 0){
            printf("Bye!");
            m = 5;
            i = 3;
            
        }else if(strcmp(wholePrompt[0], arrayOfCommands[0][1]) == 0){
            i = 3;
        }else if(strcmp(wholePrompt[0], arrayOfCommands[0][2]) == 0){
            printf("%s", wholePrompt[1]);
            i = 3;
            //printf("%s", wholePrompt[1]);

        }else if(strcmp(wholePrompt[0], arrayOfCommands[0][3]) == 0){
            
            i = 3;
        }else if(wholePrompt[0][0] == '$'){ 

          variableCreation(wholePrompt[0]);


          //////////////////
          // for(int c = 1; c < strlen(wholePrompt[0]); c++){
          //   if(wholePrompt[0][c] == '='){
          //     printf("assigning a variable");
          //   }
          // }

          // variables[nVariable].name = wholePrompt[1];
          // nVariable++;
          // printf("%s", variables[nVariable-1].name);
          
          // i = 3;
          //////////////////

        }
        else{

            childProcess(wholePrompt[0]);
            i = 3;
        }
    }
  
  free(input);

  return 0;

}

int variableCreation(char* variableInfo){

      // for(int c = 1; c < strlen(wholePrompt[0]); c++){

      //       if(wholePrompt[0][c] == ' '){
      //         printf("should not have any spaces");
      //       }
      //       else if(wholePrompt[0][c] == '='){
      //         printf("assigning a variable");
      //       }
      // }


  return 0;

}

int childProcess(char* prompt){

   int pid = fork();

        if(pid < 0){
        printf("Fork failed \n");
        exit(1);
      }else if (pid == 0){
        //printf("I am child (pid %d) \n", (int) getpid());
        system(prompt);
        waitForInput();
      }else{
        wait(NULL);
        //printf("I'm a parent, waited");
      }

  return 0;

}

int logg(){

  for(int i = 0; i <= 9; i++){
    
      //printf("%s", &commands[i]); fix later???
    
  }

  return 0;
}


