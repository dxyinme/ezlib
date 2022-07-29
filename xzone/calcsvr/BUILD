load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")


proto_library(
  name = "calcsvr_proto",
  srcs = ["calcsvr.proto"],
  deps = [
    "//xzone/common:base_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_grpc_library(
  name = "calcsvr_cpp_grpc",
  protos = [":calcsvr_proto"],
  deps = [
    "//xzone/common:base_cpp_proto",
  ],
  visibility = ["//visibility:public"],
)

cc_binary(
  name = "calcsvr",
  srcs = [
    "servermain.cc",

    "calcserviceimpl.cpp",    
    "calcserviceimpl.h",
  ],
  deps = [
    "@com_github_grpc_grpc//:grpc++",
    "@com_github_grpc_grpc//:grpc++_reflection",
    ":calcsvr_cpp_grpc",
  ],
  linkopts = [
    "-lpthread",
  ]
)