
if(ZEQ_FOUND AND FlatBuffers_FOUND)
  list(APPEND FIND_PACKAGES_DEFINES LIVRE_USE_REMOTE_DATASOURCE)
  set(LIVRE_USE_REMOTE_DATASOURCE 1)
endif()
