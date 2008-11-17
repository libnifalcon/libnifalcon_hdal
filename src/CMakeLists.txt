SET(SRCS hdl.cpp FalconNovintHDALCompat.cpp)

INSTALL(FILES 
  hdl.h
  hdlConstants.h
  hdlErrors.h
  hdlExports.h
  hdlu.h
  hdluExports.h
  FalconNovintHDALCompat.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/falcon/hdal)
 
#SET(LINK_LIBS ${LIBNIFALCON_LIBRARIES} ${LIBNIFALCON_COMM_LIBRARIES} ${LIBNIFALCON_DEVICE_BOOST_THREAD_LIBRARY} ${LIBFTDI_LIBRARIES})
SET(LINK_LIBS nifalcon nifalcon_comm_libusb nifalcon_device_boost_thread usb-1.0)
INCLUDE_DIRECTORIES(/usr/local/include/falcon /home/qdot/projects/software/libs/libnifalcon/src/cpp)
LINK_DIRECTORIES(/home/qdot/projects/software/libs/libnifalcon/lib/ /usr/local/lib)
BUILD_NIFALCON_LIB(${LIBNIFALCON_HDAL} "${BUILD_TYPES}" "${SRCS}" "${LINK_LIBS}" FALSE)
