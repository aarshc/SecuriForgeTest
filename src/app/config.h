#ifndef CONFIG_H
#define CONFIG_H

#define MODE_LEN 32

typedef struct {
    char mode[MODE_LEN];
    int retries;
} AppConfig;

// Load configuration from a file
AppConfig load_config(const char *path);

#endif // CONFIG_H
