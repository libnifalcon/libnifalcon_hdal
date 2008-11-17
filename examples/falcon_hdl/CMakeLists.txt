FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)
MESSAGE(STATUS ${GLUT_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_DIR}/src/ ${INC_DIRS} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})
LINK_DIRECTORIES(${PROJECT_DIR}/lib ${LINK_DIRS})
SET(SRCS main_opengl.cpp haptics.cpp)
ADD_EXECUTABLE(falcon_hdl_ogl ${SRCS})
SET_COMPILE_FLAGS(falcon_hdl_ogl ${CPP_DEFINES})	
TARGET_LINK_LIBRARIES(falcon_hdl_ogl nifalcon_comm_libftdi nifalcon nifalcon_device_boost_thread usb-1.0 nifalcon_hdal ${Boost_PROGRAM_OPTIONS_LIBRARY} ${GLUT_glut_LIBRARY}) 

IF(APPLE)
  SET_TARGET_PROPERTIES(falcon_hdl_ogl PROPERTIES LINK_FLAGS "-framework Carbon -framework ApplicationServices -framework OpenGL -framework GLUT")
ENDIF(APPLE)

