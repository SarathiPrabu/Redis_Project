#include <sys/socket.h>
#include <iostream>

using namespace std;

static void do_something(int connfd){
	char rbuf[64] = {};
	ssize_t n = read(connfd, rbuf, sizeof(rbuf)-1);
	if(n < 0){
		msg("read() error");
		return;
	}
	printf("Client : %s\n",rbuf);

	char wbuff[] = "world";
	write(connfd, wbuf, strlen(wbuf));
}

int main(){
	cout << "Hello World cpp \n";
// Step 1 : Obtain socket handle
	int fd = socket(AF_INET, SOCK_STERAM, 0);

// Step 2 : Set socket options
	int val = 1;
	setsocket(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

// Step 3 : Bind to an address
// We will bind to the address 0.0.0.0:1234
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = ntohs(1234);
	addr.sin_addr.s_addr = ntohl(0);

	int rv = bind(fd, (const sockaddr *)&addr, sizeof(addr));
	if(rv){
		die("bind()");
	}

// Step 4: Listen
	rv = listen(fd,SOMAXCONN);
	if(rv){ die("listen()");}

// Step 5: Accept Connections
	while(true){
		struct sockaddr_in client_addr = {};
		socklen_t addrlen = sizeof(client_addr);
		int connfd = accept(fd, (struct sockaddr *)&client_addr, &addrlen);
		if(connfd < 0){
			continue;
		}
		do_something(connfd);
		close(connfd);
	}

return 0;
}
