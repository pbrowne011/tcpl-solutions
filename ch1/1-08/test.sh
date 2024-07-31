#!/bin/bash

verbose=$1

if [[ ! -e cs ]]; then
    echo "File ./cs not found. Making now"
    make cs
fi

ls *.txt | while read -r file; do
    num=${file%%s*}
    n=$(./cs < "$file")
    n=${n##*: }

    if [[ $verbose ]]; then
        echo "Value from filename: $num"
        echo "Detected value: $n"
    fi
    
    if [[ "$n" != "$num" ]]; then
        echo "Test failed for file $file" > stderr
        exit 1
    fi

    if [[ $verbose ]]; then
        echo "---"
    fi
done
echo "All tests passed"
