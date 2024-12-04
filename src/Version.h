#define NAME          "IPhreeqc"
#define VER_MAJOR      3
#define VER_MINOR      8
#define VER_PATCH      5
#define VER_REVISION   17066
#define GIT_COMMIT     7e412da938f8c163004a17d5e30a874a045d541c

#define RELEASE_DATE           "December  4, 2024"

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
