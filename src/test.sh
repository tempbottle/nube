#!/bin/bash - 
ulimit -n unlimited
httperf --server localhost\
    --port=8181 \
    --uri=/ \
    --method=POST \
    --num-calls=1000 \
    --num-conns=1000 \
    --rate=1000 \
    --print-reply \
