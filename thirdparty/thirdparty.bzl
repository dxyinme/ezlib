load("//thirdparty/gtest:gtest.bzl", "load_gtest")
load("//thirdparty/benchmark:benchmark.bzl", "load_benchmark")


def load_thirdparty_libs():
    load_gtest()
    load_benchmark()