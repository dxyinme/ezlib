load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

proto_library(
  name = "base_proto",
  srcs = ["base.proto"],
  deps = [],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "base_cpp_proto",
  protos = [":base_proto"],
  visibility = ["//visibility:public"],
)