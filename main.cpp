#include "LongLongInt.h"


int main() {
    LongLongInt a("111111");
    LongLongInt b("222");
    LongLongInt c;
    c = (a + b);
    c.Lprint();
    return 0;
}