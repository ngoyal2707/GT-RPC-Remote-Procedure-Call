g++ -Wall -I/usr/local/include/thrift -c RPCService.cpp -o RPCService.o
g++ -Wall -I/usr/local/include/thrift -c server_constants.cpp -o server_constants.o
g++ -Wall -I/usr/local/include/thrift -c server_types.cpp -o server_types.o
g++ -Wall -I/usr/local/include/thrift -c RPCService_server.cpp -o RPCService_server.o
# g++ -Wall -I/usr/local/include/thrift -c LRUCache.cpp -o LRUCache.o
# g++ -o rpc_server -I. -I/usr/local/include/thrift/ RPCService_server.cpp RPCService.cpp server_constants.cpp server_types.cpp LRUCache.cpp -lthrift -lcurl

g++ -o rpc_server -I. -I/usr/local/include/thrift/ RPCService_server.cpp RPCService.cpp server_constants.cpp server_types.cpp LFUCache.cpp -lthrift -lcurl
