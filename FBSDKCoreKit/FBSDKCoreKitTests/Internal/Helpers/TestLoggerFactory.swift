/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

@objcMembers
class TestLoggerFactory: LoggingCreating {
  var capturedLoggingBehavior: LoggingBehavior?
  var logger = TestLogger(loggingBehavior: .developerErrors)

  func createLogger(withLoggingBehavior loggingBehavior: LoggingBehavior) -> Logging {
    capturedLoggingBehavior = loggingBehavior
    logger = TestLogger(loggingBehavior: loggingBehavior)
    return logger
  }
}
