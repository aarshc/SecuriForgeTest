#ifndef LOGGER_H
#define LOGGER_H

#include <stdarg.h>

// Initialize logger with a file name
void init_logger(const char *filename);

// Log info message
void log_info(const char *fmt, ...);

// Log error message
void log_error(const char *fmt, ...);

// Close the logger
void close_logger();

#endif // LOGGER_H
