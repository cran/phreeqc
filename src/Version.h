#define NAME          "IPhreeqc"
#define VER_MAJOR      3
#define VER_MINOR      7
#define VER_PATCH      5
#define VER_REVISION   16379
#define GIT_COMMIT     78e93f68cbab7b61521b50b47c82bfc9b3e77809

#define RELEASE_DATE           "January 17, 2023"

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
