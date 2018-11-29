#!/bin/bash
clang++ -I include \
        -lsfml-{graphics,window,system} \
        src/* \
        -o game