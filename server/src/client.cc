#include <grpcpp/grpcpp.h>
#include "proto/hello.grpc.pb.h"
#include "proto/hello.pb.h"
#include <memory>
#include <iostream>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hello::Point3;
using hello::Numeric;
using hello::ProcessingServices;

class SampleClient {
    public:
    SampleClient(std::shared_ptr<Channel> channel) : _stub{ProcessingServices::NewStub(channel)} {}
    std::string computeSum(const ::Point3& request) {

        // Send Request
        Numeric response;
        ClientContext context;
        Status status;
        status = _stub->computeSum(&context, request, &response);

        //Handle response
        if(status.ok()) {
            std::cout << "response: " << response.value() << std::endl;
            return "True";
        }
        else {
            std::cerr << status.error_code() << ": " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }
    
    private:
    std::unique_ptr<ProcessingServices::Stub> _stub;
};

int main(){
	std::string server_address{"0.0.0.0:9999"};
    SampleClient client{grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials())};
    
    Point3 sample_point;
    sample_point.set_x(10);
    sample_point.set_y(15);
    sample_point.set_z(25);

    std::string response = client.computeSum(sample_point);
    std::cout << "Client received: " << response << std::endl;
    return 0;
	// builder.AddListeningPort("0.0.0.0:9999", grpc::InsecureServerCredentials());
}
