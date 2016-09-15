//
// Created by allan on 10/09/16.
//


#include "Client.h"


char* Client::host="";
int Client::port=0;
void Client::error(const char* msg) {
    perror(msg);
    exit(0);
}

void Client::iniciar(const string texto) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    char reading[256];
    /*if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }*/
    portno = getPort();
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(Client::getHost());
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    printf("Por favor escriba su mensaje: ");
    //bzero(buffer,256);
    //fgets(buffer,255,stdin);
    //strcpy(buffer,texto.data());
    n=write(sockfd,buffer,strlen(buffer));

    if (n < 0)
        error("ERROR writing to socket");
      bzero(reading,256);
      n=read(sockfd,reading,255);
    //cout<<"Aqui"<<endl;
    //if (n < 0)
        //error("ERROR reading from socket");
    printf("%s\n",reading);
    close(sockfd);
}
