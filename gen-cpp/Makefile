all: server client

server: RPCService.o server_constants.o server_types.o RPCService_server.o
	g++ -o rpc_server -I. -I/usr/local/include/thrift/ RPCService_server.cpp RPCService.cpp server_constants.cpp server_types.cpp LFUCache.cpp -lthrift -lcurl

client: RPCService_client.o
	g++ -L/usr/local/lib rpc_client.o RPCService.o server_constants.o server_types.o -o RPC_client -lthrift
	
RPCService.o:
	g++ -Wall -I/usr/local/include/thrift -c RPCService.cpp -o RPCService.o

server_constants.o:
	g++ -Wall -I/usr/local/include/thrift -c server_constants.cpp -o server_constants.o

server_types.o:
	g++ -Wall -I/usr/local/include/thrift -c server_types.cpp -o server_types.o

RPCService_server.o:
	g++ -Wall -I/usr/local/include/thrift -c RPCService_server.cpp -o RPCService_server.o

RPCService_client.o:
	g++ -Wall -I/usr/local/include/thrift -c RPCService_client.cpp -o rpc_client.o 

clean:
	rm *.o rpc_server RPC_client