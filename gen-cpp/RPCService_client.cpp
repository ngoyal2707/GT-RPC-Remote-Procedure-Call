#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <ctime>
#include <fstream>
#include "RPCService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace RPC;

unsigned long long getCurrentTime(){
    struct timeval time;
    gettimeofday(&time,NULL);
    return time.tv_usec+(unsigned long long)time.tv_sec*1000000;
}

int main(int argc, char* argv[]) {
    boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    RPCServiceClient client(protocol);

    unsigned long long totalResponseTime = 0.0;
    int queryCount = 0;
    
    if(argc <2){
        cout<<"URL file not provided\n";
    }else{
        try {
            // string filename(argv[1]);
            ifstream iFile(argv[1]); 
            transport->open();
            dataFormat response;
    
            string URL;
            while(iFile >> URL){
                // cout<<URL<<
                unsigned long long begin_time = getCurrentTime();
                client.getResponse(response, URL);
                unsigned long long responseTime =  ( getCurrentTime() - begin_time );
                totalResponseTime += responseTime;
                queryCount++;
                cout<<"Got URL:"<<URL<<"\n";
            }
            // cout<<"response:"<<response.data;
            double averageResponseTime = ((double)totalResponseTime/(double)queryCount);
            cout<<"Average resposne time:"<<averageResponseTime<<"\n";
            transport->close();
        } catch (TException& tx) {
            cout << "ERROR: " << tx.what() << endl;
        }
    }
}