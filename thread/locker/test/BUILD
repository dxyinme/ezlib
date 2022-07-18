load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_test(
  name = 'locker_test',
  srcs = [
    "rwmutex_test.cc",
  ],
  deps = [
    "@gtest",
    "@gtest//:gtest_main",
    "//thread/locker:locker"
  ],
  linkopts = [
    "-pthread"
  ]
)