echo "Running unit tests:"

for i in tests/*_test.out
do
    if test -f $i
    then
        if ./$i 2>> tests/tests.log
        then
            echo ""
            echo $i PASS
            echo ":)"
            echo ""
        else
            echo "ERROR in test $i: here is tests/tests.log"
            echo "---------"
            tail tests/tests.log
            exit 1
        fi
    fi
done

echo ""
