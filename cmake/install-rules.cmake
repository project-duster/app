install(
    TARGETS app_exe
    RUNTIME COMPONENT app_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()

