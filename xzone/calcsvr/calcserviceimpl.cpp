#include "calcserviceimpl.h"

namespace xzone::calcsvr {

::grpc::Status CalcSvrImpl::BaseTest(
  ::grpc::ServerContext* ctx, 
  const ::xzone::common::BaseTestMsg* req, 
  ::xzone::common::BaseTestMsg* resp) {
  
  resp->set_msg(req->msg());

  return ::grpc::Status::OK;
}

}