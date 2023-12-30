# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_test
cc_test(
    name="tests",
    srcs=glob(["**/*.cc"]),
    deps=[
        "//src/lib:SolutionLib",
        "@googletest//:gtest_main",
        ],   
)