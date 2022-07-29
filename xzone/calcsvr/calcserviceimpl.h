#ifndef XZONE_CALCSVR_CALCSERVICE_IMPL_H_
#define XZONE_CALCSVR_CALCSERVICE_IMPL_H_

#include "xzone/calcsvr/calcsvr.grpc.pb.h"

namespace xzone {
namespace calcsvr {

class CalcSvrImpl final : public Calc::Service {
public:
  ::grpc::Status BaseTest(
    ::grpc::ServerContext* ctx, 
    const ::xzone::common::BaseTestMsg* req, 
    ::xzone::common::BaseTestMsg* resp) override;
};

} // namespace calcsvr
} // namespace xzone


#endif  // XZONE_CALCSVR_CALCSERVICE_IMPL_H_