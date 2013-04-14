

#include <iostream>
#include <soap/soapservidorPortBindingProxy.h>
#include <soap/servidorPortBinding.nsmap>

int main()
{
    servidorPortBinding soapObj;
    
    ns1__hello *request = new ns1__hello;
    ns1__helloResponse *response = new ns1__helloResponse;

    std::string nombre("Sigifredo");
    request->name = &nombre;

    soapObj.__ns1__hello(request, response);

    std::cout << *response->return_ << std::endl;

    delete request;
    delete response;

    return 0;
}
