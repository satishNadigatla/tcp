#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>



int main(){

  char *ip = "192.168.189.106";
  int port = 631;

  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;
  

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

 // memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = INADDR_ANY;//inet_addr(ip);
   
 char *p=(char*)malloc(sizeof(char));
  

  connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  while(1){
  scanf("%s",p);
  printf("Connected to the server.\n");
  bzero(buffer, 1024);
  strcpy(buffer, p);
  printf("Client: %s\n", buffer);
  send(sock, buffer, strlen(buffer), 0);

  bzero(buffer, 1024);
recv(sock, buffer, sizeof(buffer), 0);
  printf("Server: %s\n", buffer);

}
  //close(sock);
  //printf("Disconnected from the server.\n");

  return 0;

}

