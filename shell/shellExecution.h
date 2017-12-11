#ifndef shellExecution
#define shellExecution

char *shellInput( char **envp );

int executeCommand( char **args, char **envp );

int executePipes( char **pipeVec, char **envp );

#endif
