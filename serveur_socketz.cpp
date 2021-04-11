

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <cstring>
#include <iostream>

using namespace std;
 	
int main()
{
struct sockaddr_in serveur;
struct sockaddr_in adIPv4;



 int desc=socket(PF_INET,SOCK_STREAM,0);
 int taille,descClient, ret;
 int port=8080;

 	
 	 
 	
 
  if (desc == -1) 
    {
        cout<<"Could not create socket"<<endl;
    }

    cout << "Socket définit " << endl;
    
 taille=sizeof(struct sockaddr_in);
 //char *msg1="bonjoursnir2021";
 char msg2[200];

		
 serveur.sin_family=PF_INET; 
 serveur.sin_port = htons(port);
 serveur.sin_addr.s_addr=htons(INADDR_ANY);


 cout << "structure complétée " << endl;
	
 ret=bind(desc, (struct sockaddr * )&serveur, sizeof(serveur));
 

 if (ret ==  0 )
 {
	  cout << "Socket construit " << endl;
 }

 ret=listen(desc, 2);
  cout << "voici lle ret \t" << ret <<endl;
 if (ret > -1)
 {
	  cout << "socket en écoute " << endl;
 }

 descClient=accept(desc, (struct sockaddr*)&adIPv4, (socklen_t*)&taille);
 cout << "client connecté " << descClient << endl;
 	//send(descClient, "Bonjour\n", 8, 0 ); 

	// recv(descClient, msg2, 14, 0);
	
	recv(descClient, msg2, 20, 0);
	
	cout << "reception ok " << endl;
	cout << "Affichage " << endl;
	cout <<"hello  here is the message \t" << msg2 << endl;
	
    		 
	
	
	close (desc);


return 0;
}

