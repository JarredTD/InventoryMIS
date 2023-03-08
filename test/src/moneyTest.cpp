#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_CPP11_COMPAT

#include "../doctest/doctest.h"
#include "../../include/money.h"

TEST_CASE("DefaultContructor") {
    Money money;
    CHECK_EQ(0, money.getDollar());
    CHECK_EQ(1, money.getChange());
}

int main(int argc, char* argv[]) {
    doctest::Context context;
    context.setOption("abort-after", 5); // stop tests after 5 failures
    context.setOption("no-breaks", true); // don't break into the debugger on failures
    context.setOption("no-skip", true); // don't skip tests marked as "skip"
    context.applyCommandLine(argc, argv); // apply command line options
    context.setOption("no-version", true); // don't print doctest version
    int res = context.run(); // run tests
    return res;
}
