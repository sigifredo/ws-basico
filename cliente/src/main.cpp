

#include <iostream>
#include <soap/soapservidorPortBindingProxy.h>

int main()
{
    servidorPortBinding soapObj;
    
    ns1__hello *hola = new ns1__hello;
    ns1__helloResponse *response = new ns1__helloResponse;
    
    soapObj.__ns1__hello(hola, response);

    std::cout << response->return_ << std::endl;

    return 0;
}
