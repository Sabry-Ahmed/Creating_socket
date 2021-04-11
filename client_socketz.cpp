
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

using namespace std;


int main()
{
 	struct sockaddr_in adIPv4;
 
 
	 int desc= socket(PF_INET,SOCK_STREAM,0);
	 int port=8080 ;
 	
 	 
 	 
 	
   	 if (desc == -1) 
   	  {
        	cout<<"Could not create socket"<<endl;
    	  }
 	 adIPv4.sin_family=PF_INET; 
 	 adIPv4.sin_port = htons(port);
	 inet_aton("server ip adresse ex: 192.168.2.192",&adIPv4.sin_addr);
 	 string msg="client S2SNIR\n";	
 
 
	  if ( connect(desc, (struct sockaddr*)& adIPv4,sizeof( adIPv4)) < 0)
	  {
			cout <<"Erreur de connection"<<endl;	
			return 1;
	   }
		
		cout << "coonnected" << endl;
		
  	   if (send(desc, msg.c_str(), msg.size(), 0) < 0)
   	   {
       	 cout<<"Send failed\n"<<endl;
       	 return 1;
    	   }
    
		cout << "sended\t" << msg << endl;
	
	
	

 close (desc);


return 0;
}
