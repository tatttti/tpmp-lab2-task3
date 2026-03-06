#!/bin/bash
OK=0
FAIL=0

for i in 1 2 3; do
    echo "Running test $i..."
    ./bin/program < tests/input$i.txt > tests/result$i.txt

    if diff -q tests/result$i.txt tests/output$i.txt > /dev/null; then
        echo "Test $i: OK"
        OK=$((OK+1))
    else
        echo "Test $i: FAIL"
        FAIL=$((FAIL+1))
    fi
done

echo "Passed: $OK"
echo "Failed: $FAIL"

if [ $FAIL -eq 0 ]; then
    exit 0
else
    exit 1
fi

