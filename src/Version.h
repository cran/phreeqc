#define NAME          "IPhreeqc"
#define VER_MAJOR      3
#define VER_MINOR      8
#define VER_PATCH      7
#define VER_REVISION   17149
#define GIT_COMMIT     75780866714a0cd0f0fa3a3a98426a72b5e4c02f

#define RELEASE_DATE           "February 25, 2025"

#define APR_STRINGIFY(n) APR_STRINGIFY_HELPER(n)
#define APR_STRINGIFY_HELPER(n) #n

/** Version number */
#define VER_NUM                APR_STRINGIFY(VER_MAJOR) \
                           "." APR_STRINGIFY(VER_MINOR) \
                           "." APR_STRINGIFY(VER_PATCH) \
                           "." APR_STRINGIFY(VER_REVISION)



#define PRODUCT_NAME   NAME \
                       "-" APR_STRINGIFY(VER_MAJOR) \
                       "." APR_STRINGIFY(VER_MINOR)

#if defined(_WIN64)
#define VERSION_STRING         APR_STRINGIFY(VER_MAJOR) \
                           "." APR_STRINGIFY(VER_MINOR) \
                           "." APR_STRINGIFY(VER_PATCH) \
                           "-" APR_STRINGIFY(VER_REVISION) \
                           "-x64"
#else
#define VERSION_STRING         APR_STRINGIFY(VER_MAJOR) \
                           "." APR_STRINGIFY(VER_MINOR) \
                           "." APR_STRINGIFY(VER_PATCH) \
                           "-" APR_STRINGIFY(VER_REVISION)
#endif
