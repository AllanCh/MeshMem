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

string Client::iniciar(string texto) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];


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
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    strcpy(buffer,texto.c_str());
    buffer[texto.length()]='\n';
    cout<<"Buffer"<<buffer<<"Hola"<<endl;
    n=send(sockfd,buffer,texto.length()+1,0);
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    n=recv(sockfd,buffer,sizeof(buffer)-1,0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    close(sockfd);
    shutdown(sockfd, SHUT_RDWR);
    cout<<"Buffer"<<buffer<<"Hola de nuevo"<<endl;

    return buffer;
}
