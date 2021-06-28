#!/bin/sh
clear && make && (cat ./testcase.txt; cat) | ./main
