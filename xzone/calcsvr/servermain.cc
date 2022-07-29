#include <grpcpp/grpcpp.h>
#include "calcserviceimpl.h"

int main() {
  std::string addr("0.0.0.0:50051");
  xzone::calcsvr::CalcSvrImpl impl;
  grpc::ServerBuilder builder;
  builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
  builder.RegisterService(&impl);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << addr << std::endl;
  server->Wait();
  return 0;
}