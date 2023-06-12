#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

typedef struct{

    char *name;
    char *value;

} EnvVar;

int printShell();
int exitShell();
int print();
int parse();
int tokenize(char*);

int main(int argc, char *argv[]){

    printShell();
    parse();
    //exitShell();
    //readInput();

    
}

int tokenize(char* text){

    printf("%s", text);

    //int n = strlen(text) + 1;
    //char *dest [n];
    char *dest;


    //char *dest; //make it 1 only 

    strcpy(dest, text); //removed & infront of text
    printf("%s", dest);

    
    

    char *ptr = strtok(dest, " ");
    while(ptr != NULL){
        printf(" %s \n ", &ptr);
        ptr = strtok(NULL, " ");
    }

    return (0);

}

int parse(){

    // char* prompt[30];

    // scanf("%s", prompt);

    size_t bufsize = 30;
    size_t inputsize = 0;


    char *buffer = realloc(NULL, sizeof(char) * bufsize);
    char c;

    //input = getline(&buffer, &bufsize, stdin);

    
    int i = 1;

    c = getchar();
    buffer[inputsize] = c;

    while(c != '\n'){
        //inputsize = inputsize + 1;

        if(inputsize == bufsize){

            i = i + 1;
            buffer = realloc(buffer, sizeof(char) * bufsize * i);

        }

        c = getchar();
        inputsize = inputsize + 1;
        buffer[inputsize] = c;
        

        //putchar(c);
    }

    //buffer[inputsize] = c;


    //printf("Typed: %s", buffer);

    tokenize(buffer);
    free(buffer);



    return (0);

}

int printShell(){

    printf("cshell$ ");

    return (0);

}

int exitShell(){

    kill(getpid(), SIGINT);

    return (0);
}

// int readInput(){

//     char* prompt[30];

//     scanf("%s", prompt);

//     return 0;

// }

int print(char *input){

return (0);

}





  //   char *arrayOfCommands[][5] = {{"exit", "log", "print", "theme"}}; 
    
  //   for(int i = 0; i <= 3; i++){
  //       if(strcmp(wholePrompt[0], arrayOfCommands[0][0]) == 0){
  //           printf("Bye!");
  //           i = 3;
  //           exit(0);
  //       }else if(strcmp(wholePrompt[0], arrayOfCommands[0][1]) == 0){
  //           printf("Log");
  //           i = 3;
  //       }else if(strcmp(wholePrompt[0], arrayOfCommands[0][2]) == 0){
  //           printf("%s", asctime(timeinfo));
  //           //printf("print");
  //           i = 3;
  //       }else if(strcmp(wholePrompt[0], arrayOfCommands[0][3]) == 0){
  //           printf("theme");
  //           i = 3;
  //       }else{

  //         childProcess(wholePrompt[0]);
  //         i = 3;
  //       }
  //   }
  
  // free(input); 