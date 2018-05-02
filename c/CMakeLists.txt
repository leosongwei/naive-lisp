add_library(nlruntime SHARED defines.h gc.h gc.c init.c)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2")        ## Optimize
endif()
