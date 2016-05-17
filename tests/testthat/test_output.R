library(rtest)
context("Output")

test_that("hello() prints 'Hello, world!'", {
  expect_output(hello(), "Hello, world!")
})
