set(HDRS
   tanksMid.h
   )

set(SRCS
   tanksMid.cpp
   processMessage.cpp
   )

add_library(TanksMid ${HDRS} ${SRCS})
target_link_libraries(TanksMid util ${GTK2_LIBRARIES})

