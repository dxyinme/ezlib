cc_library(
  name = "threadpool",
  srcs = [
    "threadpool.cc",
  ],
  hdrs = [
    "threadpool.hpp",
  ],
  includes = [
    ".",
  ],
  deps = [
    "//thread/timeup:timeup",
  ],
  visibility = [
    "//visibility:public"
  ]
)


cc_binary(
  name = 'threadpool_example',
  srcs = [
    "threadpool_example.cc",
  ],
  deps = [
    ":threadpool"
  ],
  linkopts = [
    "-lpthread",
  ],
  copts = [
    "-O2",
  ]
)