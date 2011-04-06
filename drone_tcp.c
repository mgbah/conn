#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MYPORT 9600

/*by Acho and Nelson*/
/* this creates a socket */
int socket_file_descriptor(){
  return socket(AF_INET,SOCK_STREAM,0);
}

/* checks the status of the socket */
checkSocket(int sockFd){
  if(sockFd == -1){
    return 0;
  }else{
    return 1;
  }
}

/* binds the socket */
int bindStatus(int socketfd){
  struct sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr= INADDR_ANY;
  if(bind(socketfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1){
    return 0;
  }else{
    return 1;
  }
}

/* listens to the socket */
int listenStat(int sockfd,int capacity_conn){
  if(listen(sockfd,capacity_conn) ==-1){
    return 0;
  }else{
    return 1;
  }
}

/* make connection by giving the socket file descriptor and the number of connections the connection can hold in a queue */

int mk_Connct(int sfd,int cap_conn){
  int sockStat = checkSocket(sfd);
  int bindStat = bindStatus(sfd);
  int LstStat = listenStat(sfd,cap_conn);

  if(sockStat == 1 && bindStat == 1 && LstStat == 1 ){
    return 1;
  }else{
    return 0;
  }
}


int main(void){
  int sD = socket_file_descriptor();
  mk_Connct(sD,10);
}
