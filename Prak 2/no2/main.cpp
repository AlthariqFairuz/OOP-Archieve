#include "Invoker.hpp"
#include "Axe.hpp"

int main()
{
    Invoker *i = new Invoker(10, 1000);
    i->useSkill();
    Invoker *h = new Invoker(*i);
    h->Hero::heal(1);
    h = new Invoker(50, 200);
    h->move(10, 25);
    *h = *i;

    Axe *n = new Axe(200, 10);
    n->move(2, 20);
    n->heal(10);
    Axe *b = new Axe(*n);
    Axe *d = new Axe(*n + *b);

    n->useSkill();
    d->useSkill();
    delete n;
    delete d;
    delete h;
    return 0;
}
