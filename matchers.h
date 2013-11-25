#include <pcre.h>
#include <python2.7/Python.h>

#define MATCHER_MAX_LEN 2048
#define MATCHER_MAX_RESPONSE 32000
#define MATCHERS_DEFAULT_FILENAME "matchers.conf"

#define PYFUNCNAME "forge_response"
#define PYTHONPATH "." // python modules path

struct matcher_entry {
    char name[64];
    pcre *match;
    pcre *ignore;
    char *response;
    PyObject *pyfunc;
    unsigned int response_len;
    unsigned int options;
    #define MATCHER_OPTION_RESET 1
    struct matcher_entry *next;
};

typedef struct matcher_entry matcher_entry;

matcher_entry *parse_matchers_file(char *macher_file_path);