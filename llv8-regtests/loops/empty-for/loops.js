var N = 10000 

function foo() {
    // noinline
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    // =========================================================
    for (var i = 0; i < 1000; i++) {
    }
    return 42;
}

var k = 0;
for (var i = 0; i < N; i++) {
    k += foo();
}

print (k);
