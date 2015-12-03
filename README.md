# GT-RPC-based-web-proxy-server#

The objective of the project is to build a RPC­based proxy server. Remote procedure call is the communication between client and server connected through network. The functionality of RPC server is to get a URL from the client through a RPC call and return the text response back to the client. The major goal of the project is to implement various cache strategies on the RPC server for caching the URL response and experiment with them. 


README:

## Compilation of server and client ##


To compile browse to the gen-cpp folder and make using following command:

	make all

This creates all th object files and the executable for the server and client.


### Run Server and Client: ###


1. Run client by following command:

	./rpc_server

2. To run client with remote server, the ip has to be changed in the RPCServer_client.cpp. Apart from that, the client is run as following:

	./RPC_client <workload_file.txt>

where the workload file is having all the URLs for the webpages.


We have added two work load file and generation script also.

The work laod files are:
	a) randomWorkload.txt
	b) repeatedWorkload.txt


### Evaluation metrics: ###

1. Hit ratio is printed on server command window.

2. Average response time is printed on the client command window. 
