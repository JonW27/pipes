#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int READ = 0;
  int WRITE = 1;
  
  int fds[2];
  int fds2[2];
  pipe(fds);
  pipe(fds2);

  if(fork()){
    close(fds[WRITE]);
    int num;
    read(fds[READ], &num, sizeof(num));
    printf("doing math operation on %d\n", num);
    num += 1; // im so original
    close(fds2[READ]);
    write(fds2[WRITE], &num, sizeof(num));
    
  } else{
    int num = 42;
    close(fds[READ]);
    printf("sending number %d\n", num);
    write(fds[WRITE], &num, sizeof(num));
    close(fds2[WRITE]);
    read(fds2[READ], &num, sizeof(num));
    printf("Addition by 1 complete! The returned value is %d!\n", num);
  }
    
  return 0;
}
