#!/bin/sh
find ../ -regex '.*\.\(c\|h\)$' -exec ./format.sh {} \;

