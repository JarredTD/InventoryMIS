#include <iostream>
#include "../obj/money.h"

int main(){
    Money* price_0 = new Money();
    Money* price = new Money(13.5);

    printf("%i.%i", price_0->getDollar(), price_0->getChange());
    printf("%i.%i", price_0->getDollar(), price_0->getChange());

    delete price_0;
    delete price;
    return 0;
}