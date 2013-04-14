
set(GSOAP_PATH /usr/share/gsoap/import/)
set(SOAP_DIR "${CMAKE_SOURCE_DIR}/include/soap")

if(GENERATE_GSOAP_FILES)
        add_custom_command(
                OUTPUT ${SOAP_DIR}
                COMMAND mkdir
                ARGS -p ${SOAP_DIR}
        )

        add_custom_command(
                OUTPUT ${SOAP_DIR}/Cliente.hpp
                DEPENDS ${SOAP_DIR}
                COMMAND wsdl2h -o ${SOAP_DIR}/Cliente.hpp http://localhost:8080/servidor/servidor?WSDL
        )

        add_custom_command(
                OUTPUT ${SOAP_DIR}/soapservidorPortBindingProxy.h
                DEPENDS ${SOAP_DIR} ${SOAP_DIR}/Cliente.hpp
                COMMAND soapcpp2 -I${GSOAP_PATH} -d${SOAP_DIR}/ ${SOAP_DIR}/Cliente.hpp
        )

        # add_custom_target(gsoap_headers ALL DEPENDS Cliente.hpp)
        add_custom_target(gsoap_sources ALL DEPENDS ${SOAP_DIR}/soapservidorPortBindingProxy.h)
endif()



# file(GLOB SOAP_SRCS "${SOAP_DIR}/*.cpp")
set(SOAP_SRCS
${SOAP_DIR}/soapC.cpp
${SOAP_DIR}/soapClient.cpp
)

add_library(lsoap SHARED
${SOAP_SRCS}
)

set(GSOAP_LIBRARIES
lsoap
gsoap++
)

include_directories(${GSOAP_PATH})



if(GENERATE_GSOAP_FILES)
        add_dependencies(lsoap gsoap_sources)
endif()
