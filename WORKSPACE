load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("//thirdparty:thirdparty.bzl", "load_thirdparty_libs")
load_thirdparty_libs()

git_repository(
    name = "glog",
    remote = "https://github.com/google/glog.git",
    tag = "v0.5.0",
)

git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    tag = "v2.2.2",
)