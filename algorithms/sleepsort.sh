#!/bin/bash
# https://dis.4chan.org/read/prog/1295544154/
function f() {
    sleep "$1"
    echo "$1"
}
while [ -n "$1" ]
do
    f "$1" &
    shift
done
wait
