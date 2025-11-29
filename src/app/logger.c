#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

static FILE *log_file = NULL;

void init_logger(const char *filename) {
    log_file = fopen(filename, "a");
}

void log_info(const char *fmt, ...) {
    if (!log_file) return;
    va_list args;
    va_start(args, fmt);
    fprintf(log_file, "[INFO] ");
    vfprintf(log_file, fmt, args);
    fprintf(log_file, "\n");
    va_end(args);
}

void log_error(const char *fmt, ...) {
    if (!log_file) return;
    va_list args;
    va_start(args, fmt);
    fprintf(log_file, "[ERROR] ");
    vfprintf(log_file, fmt, args);
    fprintf(log_file, "\n");
    va_end(args);
}

void close_logger() {
    if (log_file) fclose(log_file);
}
