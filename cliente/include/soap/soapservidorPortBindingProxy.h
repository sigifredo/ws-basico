/* soapservidorPortBindingProxy.h
   Generated by gSOAP 2.8.7 from /home/raziel/proyectos/soap/prueba1/cliente/include/soap/Cliente.hpp

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapservidorPortBindingProxy_H
#define soapservidorPortBindingProxy_H
#include "soapH.h"
class servidorPortBinding
{   public:
	/// Runtime engine context allocated in constructor
	struct soap *soap;
	/// Endpoint URL of service 'servidorPortBinding' (change as needed)
	const char *endpoint;
	/// Constructor allocates soap engine context, sets default endpoint URL, and sets namespace mapping table
	servidorPortBinding()
	{ soap = soap_new(); endpoint = "http://localhost:8080/servidor/servidor"; if (soap && !soap->namespaces) { static const struct Namespace namespaces[] = 
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "http://servidor.prueba1.org/", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap->namespaces = namespaces; } };
	/// Destructor frees deserialized data and soap engine context
	virtual ~servidorPortBinding() { if (soap) { soap_destroy(soap); soap_end(soap); soap_free(soap); } };
	/// Invoke 'hello' of service 'servidorPortBinding' and return error code (or SOAP_OK)
	virtual int __ns1__hello(ns1__hello *ns1__hello_, ns1__helloResponse *ns1__helloResponse_) { return soap ? soap_call___ns1__hello(soap, endpoint, NULL, ns1__hello_, ns1__helloResponse_) : SOAP_EOM; };
};
#endif
