GTEST_DEPS = [
  "@gtest",
  "@gtest//:gtest_main",  
]

cc_test(
  name = 'inireader_test',
  srcs = [
    "inireader_test.cc",
  ],
  deps = GTEST_DEPS + [
    "//necfs/config:inireader"
  ],
)