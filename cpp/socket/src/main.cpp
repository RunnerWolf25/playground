#include <iostream>
#include <array>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <fcntl.h>

#include <arpa/inet.h>
#include <sys/socket.h>
//#include <sys/ioctl.h>
//#include <netdb.h>
//#include <linux/in.h>

#define SERVER_PORT 80
#define MAXLINE     4096

#define SA struct sockaddr

void error( const char* msg = "generic error") {
	std::cout << msg << std::endl;
	std::exit(2);
}

int main( int argc, const char** argv ) {
	int sockfd, n;
	int sendbytes;
	struct sockaddr_in servaddr;
	std::array<char, MAXLINE> sendline;
	std::array<char, MAXLINE> recvline;
	const char* default_addr_str = "172.217.16.206";
	std::array<char, 12> addr_str;
	addr_str[addr_str.size()] = '\0';


	if( argc < 2 ) {
		strcpy(addr_str.begin(), default_addr_str);
	} else {
		strncpy(addr_str.begin(), argv[1], 11);
	}

	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
		error("could not create a socket");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_family = htons(SERVER_PORT);

	if( inet_pton(AF_INET, addr_str.begin(), &servaddr.sin_addr ) <= 0)
		error("inet_pton error for given string");

	if( connect(sockfd, reinterpret_cast<SA*>(&servaddr), sizeof(servaddr)) < 0 ) {
		error("failed to connect");
	}

	
	// setting up GET request
	sendbytes = sprintf(sendline.begin(), "GET / HTTP/1.1\r\n\r\n");

	if ( (write(sockfd, sendline.begin(), sendbytes)) !=  sendbytes)
		error("write failiure");

	// bzero(recvline.begin(), 0, recvline.length());

	// write
	while( (n = read(sockfd, recvline.begin(), MAXLINE-1)) > 0) {
		write(1, recvline.begin(), n);
	}
	if (n < 0)
		error("read failiure");

	return 0;
}