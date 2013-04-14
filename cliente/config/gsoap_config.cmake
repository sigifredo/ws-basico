
set(GSOAP_DIR "${CMAKE_SOURCE_DIR}/include/soap")

add_custom_command(
OUTPUT ${GSOAP_DIR}
COMMAND mkdir
ARGS -p ${GSOAP_DIR}
)

add_custom_command(
OUTPUT ${GSOAP_DIR}/Cliente.hpp
DEPENDS ${GSOAP_DIR}
COMMAND wsdl2h -o ${GSOAP_DIR}/Cliente.hpp http://localhost:8080/servidor/servidor?WSDL
)

add_custom_command(
OUTPUT ${GSOAP_DIR}/soapservidorPortBindingProxy.h
DEPENDS ${GSOAP_DIR} ${GSOAP_DIR}/Cliente.hpp
COMMAND soapcpp2 -I/usr/share/gsoap/import/ -d${GSOAP_DIR}/ ${GSOAP_DIR}/Cliente.hpp
)

# add_custom_target(gsoap_headers ALL DEPENDS Cliente.hpp)
add_custom_target(gsoap_sources ALL DEPENDS ${GSOAP_DIR}/soapservidorPortBindingProxy.h)

FILE(GLOB SOAP_SRCS "${GSOAP_DIR}/*.cpp")

add_library(lsoap SHARED
${SOAP_SRCS}
)

add_dependencies(lsoap gsoap_sources)

set(GSOAP_LIBRARIES
lsoap
)

include_directories(${CMAKE_BINARY_DIR} /usr/share/gsoap/import/)
