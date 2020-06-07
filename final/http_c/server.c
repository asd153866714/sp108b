// Server side C program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 80     // 設為 http 預設的 80 port, 方便從外網測試

int main(int argc, char const *argv[])
{
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;     // 建立
    int addrlen = sizeof(address);
    
    // 建立要傳回給客戶端的訊息 (respond)
    char *hello = "Header:\nHTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nBody:\nHello world!";
    
    // int socket(int domain, int type, int protocol);
    // 建立伺服端的 socket 檔案描述符
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    

    address.sin_family = AF_INET;           // ipv4
    address.sin_addr.s_addr = INADDR_ANY;   // 0.0.0.0
    address.sin_port = htons( PORT );       // 80 port
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);    // 初始化 sin_zero, 設為空字元
    
    // 綁定伺服器端的地址
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");          // 傳回 'In bind 錯誤訊息'
        exit(EXIT_FAILURE);         // exit(-1) 非正常退出
    }

    // server_fd 進入監聽，請求的隊列最大設為 10
    if (listen(server_fd, 10) < 0)  
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");

        // 建立 socket 連線, 程式會被阻擋直到有新的請求(連線)
        // server_fd 是伺服器的連線端口, sockaddr 儲存了客戶端的ip和port 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);    // request: 從 new_socket 讀取到 buffer
        printf("%s\n",buffer );
        write(new_socket , hello , strlen(hello));      // respond: 從 hello 寫入 new_socket 
        printf("------------------Hello message sent-------------------\n");
        close(new_socket);
    }
    return 0;
}