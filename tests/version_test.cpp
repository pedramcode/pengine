#include "pengine/version.h"

#include <assert.h>

int main() {
    assert(pengine::version() == "pengine v0.1.0 2025");
    return 0;
}