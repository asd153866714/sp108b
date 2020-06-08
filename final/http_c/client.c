// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 80

int main(int argc, char const *argv[])
{
    int sock = 0; long valread;

    // <arpa/inet.h> 預設的 sockaddr_in 結構，用來儲存伺服端的資訊
    struct sockaddr_in serv_addr;

    // 建立要傳給伺服端的訊息 (request)
    char *hello = "Hello from client\n";

    // 建立接收訊息的緩衝區
    char buffer[1024] = {0};

    // 建立客戶端的 socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    // 把 ipv4 或 ipv6 的主機位址轉換成網路端的數值
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // 建立連線
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // 傳送資料, hello 為 Socket 塞入訊息的緩衝區
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    printf("------------------Hello message sent-------------------\n");
    // 讀取伺服器傳回的訊息
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}