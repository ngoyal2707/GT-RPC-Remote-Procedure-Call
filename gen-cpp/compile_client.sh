g++ -Wall -I/usr/local/include/thrift -c RPCService_client.cpp -o rpc_client.o
g++ -L/usr/local/lib rpc_client.o RPCService.o server_constants.o server_types.o -o RPC_client -lthrift

